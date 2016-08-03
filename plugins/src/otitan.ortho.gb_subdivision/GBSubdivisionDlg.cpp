#include <QtitanRibbon.h>
#include <QFileDialog>
#include <QMessageBox>
#include <boost/tokenizer.hpp>
#include <gdal/gdal_priv.h>
#include <TitanFlexUI/TitanFlexUI.h>
#include <ImgEngine/ImgEngineExport.h>
#include "GBSubdivisionDlg.h"

Q_DECLARE_METATYPE(titan::ui::PluginPtr)

using namespace titan;
using namespace titan::engine;
using namespace titan::algo::ortho;

static MapScaleCode gb_scale[11] = { GB2012_500,
									GB2012_1000,
									GB2012_2000,
									GB2012_5000,
									GB2012_10000,
									GB2012_25000,
									GB2012_50000,
									GB2012_100000,
									GB2012_250000,
									GB2012_500000,
									GB2012_1000000 };

const QStringList GetFileFormatChoices(const std::string& append_name,
	const std::string& append_desc,
	const std::string& append_format,
	std::map<QString, QString>& output_format);

int GDALBuildOverviews(const std::string& dataset_path,
	const std::string& method,
	double factor = 2.0,
	bool built_in = false,
	bool force = true);

GBSubdivisionDlg::GBSubdivisionDlg(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);

	Init();

	connect(ui.cut_method_box, SIGNAL(currentIndexChanged(int)), this, SLOT(ExchangeCutMethod(int)));
	connect(ui.input_btn, &QPushButton::clicked, this, &GBSubdivisionDlg::OpenImage);
	connect(ui.output_path_btn, &QPushButton::clicked, this, &GBSubdivisionDlg::AddOutputPath);
	connect(ui.scale_box, SIGNAL(currentIndexChanged(int)), this, SLOT(ScaleChanged(int)));
	connect(ui.use_graph_check, &QCheckBox::stateChanged, this, &GBSubdivisionDlg::CheckChanged);
	connect(ui.graph_tab, &QTableWidget::itemChanged, this, &GBSubdivisionDlg::SymbolStateChanged);

	connect(ui.ok_btn, SIGNAL(clicked()), this, SLOT(Confirm()));
	connect(ui.cancel_btn, &QPushButton::clicked, this, [this] {reject(); });
}

GBSubdivisionDlg::~GBSubdivisionDlg()
{

}

void GBSubdivisionDlg::Init()
{
	map_scale = gb_scale[0];
	sub_dir = "GB_500";

	auto format_list = GetFileFormatChoices("GTiff", "GTiff + World File", ".tif", output_format);
	ui.out_format_box->addItems(format_list);
	ui.graph_sym_txt->hide();
	ui.graph_sym_label->hide();
}

void GBSubdivisionDlg::ValidityCheck()
{
	if (ui.input_imgs_txt->text().isEmpty())
		THROW(FormatException, tr("Input image not allowed empty!").toStdString());
	if (ui.output_path_txt->text().isEmpty())
		THROW(FormatException, tr("File output path not allowed empty!").toStdString());
	if (!ui.x_res_txt->text().isEmpty()) {
		bool ok = true;
		int num = ui.x_res_txt->text().toInt(&ok);
		if (!ok || num < 0)
			THROW(FormatException, tr("X resolution must be integer and >= 0!").toStdString());
	}
	if (!ui.y_res_txt->text().isEmpty()) {
		bool ok = true;
		int num = ui.y_res_txt->text().toInt(&ok);
		if (!ok || num < 0)
			THROW(FormatException, tr("Y resolution must be integer and >= 0!").toStdString());
	}
	if (!ui.no_data_txt->text().isEmpty()) {
		bool ok = true;
		int num = ui.no_data_txt->text().toInt(&ok);
		if (!ok || num < 0)
			THROW(FormatException, tr("No data value must be integer and >= 0!").toStdString());
	}
	if (!ui.expand_pixel_txt->text().isEmpty()) {
		bool ok = true;
		int num = ui.expand_pixel_txt->text().toInt(&ok);
		if (!ok || num < 0)
			THROW(FormatException, tr("Expand pixel must be integer and >= 0!").toStdString());
	}
	if (ui.cut_method_box->currentIndex() == 1
		&& ui.graph_sym_txt->text().isEmpty())
		THROW(FormatException, tr("Empty graph symbol!").toStdString());
}

void GBSubdivisionDlg::ShowGraphSymbol()
{
	ui.graph_tab->setRowCount(0);

	setCursor(QCursor(Qt::WaitCursor));
	disconnect(ui.graph_tab, &QTableWidget::itemChanged, this, &GBSubdivisionDlg::SymbolStateChanged);
	ui.graph_tab->setRowCount(sheet_numbers.size());
	for (int i = 0; i < sheet_numbers.size(); i++) {
		QTableWidgetItem* status = new QTableWidgetItem();
		if (ui.use_graph_check->isChecked())
			status->setCheckState(Qt::Checked);
		else
			status->setCheckState(Qt::Unchecked);
		ui.graph_tab->setItem(i, 0, status);

		QTableWidgetItem* number = new QTableWidgetItem(QString::number(i));
		ui.graph_tab->setItem(i, 1, number);
		auto symbol_name = sheet_numbers[i];
		QTableWidgetItem* symbol = new QTableWidgetItem(QString::fromStdString(symbol_name));
		ui.graph_tab->setItem(i, 2, symbol);
	}
	setCursor(QCursor(Qt::ArrowCursor));
	connect(ui.graph_tab, &QTableWidget::itemChanged, this, &GBSubdivisionDlg::SymbolStateChanged);
}

Error GBSubdivisionDlg::CalculateSheets(const std::string& img_path, Progress *p)
{
	sheet_numbers.clear();

	Progress::Wrapper prog(p);
	prog.Create(tr("Calculate sheets").toLocal8Bit().toStdString(), 0, true);
	prog.SetTotalLoops(1);
	prog.SetUnknownSteps();

	auto sheet_num_ptr = GetSheetNumberByScale(map_scale);
	Error err = sheet_num_ptr->GetSheetNumbersByImg(img_path, map_scale, sheet_numbers);
	if (err != ErrNone) {
		prog.Stop(false);
		return err;
	}
	prog.Stop(true);

	return ErrNone;
}


void GBSubdivisionDlg::ExchangeCutMethod(int index)
{
	if (index == 0) {
		ui.graph_sym_label->hide();
		ui.graph_sym_txt->hide();
		ui.scale_box->show();
		ui.scale_label->show();
		ui.use_graph_check->setChecked(true);
		ShowGraphSymbol();
	} else {
		ui.scale_box->hide();
		ui.scale_label->hide();
		ui.graph_sym_label->show();
		ui.graph_sym_txt->show();
		ui.use_graph_check->setChecked(false);
		ui.graph_tab->setRowCount(0);
	}
}

void GBSubdivisionDlg::OpenImage()
{
	QString filter = "GeoTIFF(*.tif *.tiff);;ERDAS Imagine(*.img);;PCI Geomatica(*.pix);;Titan MOS Image(*.mos);;JPG Files(*.jpg);;PNG Files(*.png);;All(*)";
	auto img_path = QFileDialog::getOpenFileName(this, tr("Open Image"), QString(), filter);
	if (img_path.isEmpty())
		return;
	try {
		if (ui.cut_method_box->currentIndex() == 0) {
			Error err = app::qt::CreateGadget<app::qt::BackgroundExecutor>(BACKGROUND_EXECUTOR)
				->Execute(app::qt::BackgroundTask([&](Progress* p) {return CalculateSheets(img_path.toLocal8Bit().toStdString(), p); }));
			if (err != ErrNone) {
				THROW(Exception, err.Description());
			}
		}
		ui.input_imgs_txt->setText(img_path);
		ShowGraphSymbol();
	} catch (std::exception& e) {
		QMessageBox::warning(this, tr("Warning"), e.what());
	}
}

void GBSubdivisionDlg::AddOutputPath()
{
	auto path = QFileDialog::getExistingDirectory(this, tr("Open"));
	if (path.isEmpty())
		return;
	ui.output_path_txt->setText(path);
}

void GBSubdivisionDlg::ScaleChanged(int index)
{
	map_scale = gb_scale[index];
	auto img_path = ui.input_imgs_txt->text();
	if (!img_path.isEmpty()) {
		Error err = app::qt::CreateGadget<app::qt::BackgroundExecutor>(BACKGROUND_EXECUTOR)
			->Execute(app::qt::BackgroundTask([&](Progress* p) {return CalculateSheets(img_path.toLocal8Bit().toStdString(), p); }));
		if (err != ErrNone)
			return;
		ShowGraphSymbol();
	}
	ChangeSubDir();
}

void GBSubdivisionDlg::ChangeSubDir()
{
	switch (map_scale) {
		case GB2012_500:sub_dir = "BG2012_500"; break;
		case GB2012_1000:sub_dir = "BG2012_1000"; break;
		case GB2012_2000:sub_dir = "BG2012_2000"; break;
		case GB2012_5000:sub_dir = "BG2012_5000"; break;
		case GB2012_10000:sub_dir = "BG2012_10000"; break;
		case GB2012_25000:sub_dir = "BG2012_25000"; break;
		case GB2012_50000:sub_dir = "BG2012_50000"; break;
		case GB2012_100000:sub_dir = "BG2012_100000"; break;
		case GB2012_250000:sub_dir = "BG2012_250000"; break;
		case GB2012_500000:sub_dir = "BG2012_500000"; break;
		case GB2012_1000000:sub_dir = "BG2012_1000000"; break;
	}
}

void GBSubdivisionDlg::CheckChanged(int status)
{
	int rows = ui.graph_tab->rowCount();
	for (int row = 0; row < rows; row++) {
		auto item = ui.graph_tab->item(row, 0);
		item->setCheckState((Qt::CheckState)status);
	}
}

void GBSubdivisionDlg::SymbolStateChanged(QTableWidgetItem *item)
{
	if (item->column() != 0)
		return;
	if (item->checkState() == Qt::Unchecked) {
		disconnect(ui.use_graph_check, &QCheckBox::stateChanged, this, &GBSubdivisionDlg::CheckChanged);
		ui.use_graph_check->setChecked(false);
		connect(ui.use_graph_check, &QCheckBox::stateChanged, this, &GBSubdivisionDlg::CheckChanged);
	} else {
		bool all_checked = true;
		if (item->checkState() == Qt::Checked) {
			int rows = ui.graph_tab->rowCount();
			for (int i = 0; i < rows; i++) {
				auto im = ui.graph_tab->item(i, 0);
				if (im->checkState() == Qt::Unchecked) {
					all_checked = false;
					break;
				}
			}
		}
		if (all_checked)
			ui.use_graph_check->setChecked(true);
	}
}

void GBSubdivisionDlg::Confirm()
{
	try {
		ValidityCheck();
		Error err = app::qt::CreateGadget<app::qt::BackgroundExecutor>(BACKGROUND_EXECUTOR)
			->Execute(app::qt::BackgroundTask([this](Progress* p) {return Execute(p); }));
		if (err != ErrNone) {
			QMessageBox::warning(this, tr("Warning"), err.Description().data());
			return;
		}
		accept();
	}
	catch (std::exception& e) {
		QMessageBox::warning(this, tr("Warning"), e.what());
	}
}

Error GBSubdivisionDlg::Execute(Progress *p)
{
	Path input_image_path = ui.input_imgs_txt->text().toLocal8Bit().toStdString();
	std::string crop_method = "ByFrame";
	if (ui.cut_method_box->currentIndex() == 1)
		crop_method = "BySheetNumber";

	auto output_dir = ui.output_path_txt->text().toLocal8Bit().toStdString();
	if (crop_method == "ByFrame" 
		&& (!Exists(output_dir + "/" + sub_dir))
		&&(!sub_dir.empty())) {
		output_dir.append("/" + sub_dir);
		CreatePath(Path(output_dir).String(), FileAccessPublic);
	}

	auto prefix = ui.file_pre_txt->text().toLocal8Bit().toStdString();
	auto suffix = ui.file_suf_txt->text().toLocal8Bit().toStdString();
	auto name_pattern = prefix + "%s" + suffix;

	auto extension_name = output_format[ui.out_format_box->currentText()];

	std::string creation_opts;
	if (ui.out_format_box->currentIndex() == 1)
		creation_opts += "TFW=YES;INTERLEAVE=PIXEL;";
	
	int expand_index = ui.expand_method_box->currentIndex();
	algo::BoundaryExtendType expand_type = algo::DivExtendRect;
	if (expand_index == 1)
		expand_type = algo::DivExtendPolygon;

	ResamplingMode resample_mode = ResamplingNearest;
	switch (ui.resample_method_box->currentIndex()) {
		case 0:resample_mode = ResamplingNearest; break;
		case 1:resample_mode = ResamplingBilinear; break;
		case 2:resample_mode = ResamplingCubic; break;
		case 3:resample_mode = ResamplingGauss; break;
		default: break;
	}
	double no_data_value = DBL_MIN;
	if (!ui.no_data_txt->text().isEmpty())
		no_data_value = ui.no_data_txt->text().toDouble();

	double out_expand = 0.0;
	if (!ui.expand_pixel_txt->text().isEmpty())
		out_expand = ui.expand_pixel_txt->text().toDouble();
	
	double x_resolution = 0.0, y_resolution = 0.0;
	if (!ui.x_res_txt->text().isEmpty())
		x_resolution = ui.x_res_txt->text().toDouble();
	if (!ui.y_res_txt->text().isEmpty())
		y_resolution = ui.y_res_txt->text().toDouble();

	bool chk_keep_out_range = ui.keep_out_check->isChecked();
	bool chk_out_edge = ui.out_check->isChecked();
	bool chk_build_pyramid = ui.build_overview_check->isChecked();

	auto ExecuteSheet = [&](const Path& output_image, const std::string& sheet_num)->Error {
		char** opts = NULL;
		if (!creation_opts.empty()) {
			typedef boost::tokenizer< boost::char_separator<char> > tokenizer;
			tokenizer tokens(creation_opts, boost::char_separator<char>(";"));
			for (tokenizer::iterator it = tokens.begin(); it != tokens.end(); ++it)
				opts = CSLAddString(opts, (*it).c_str());
		}
		Error err = CutImgBySheetNumber(input_image_path, output_image, sheet_num, out_expand,
			expand_type, resample_mode, x_resolution, y_resolution, chk_out_edge,
			no_data_value == DBL_MIN ? NULL : &no_data_value, chk_keep_out_range, opts);
		if (err != ErrNone)
			return err;

		if (opts)
			CSLDestroy(opts);
		if (chk_build_pyramid)
			GDALBuildOverviews(output_image.String(), "BILINEAR");

		return ErrNone;
	};

	if (crop_method == "ByFrame") {
		std::vector<std::string> select_sheet_numbers;
		for (int i = 0; i < ui.graph_tab->rowCount(); i++) {
			if (ui.graph_tab->item(i, 0)->checkState() == Qt::Checked)
				select_sheet_numbers.push_back(sheet_numbers[i]);
		}

		Progress::Wrapper prog(p);
		prog.Create(tr("GB Subdivision").toLocal8Bit().data(), select_sheet_numbers.size(), true);
		prog.SetTotalLoops(1);
		
		for (auto i = 0; i < select_sheet_numbers.size(); i++) {
			std::string output_name = boost::str(boost::format(name_pattern) % select_sheet_numbers[i]);
			Path output_image = boost::str(boost::format("%s/%s%s") % output_dir %output_name %extension_name.toStdString());

			if (output_image.IsEmpty())
				continue;
			prog.SetTipText(output_image.String());
			Error err = ExecuteSheet(output_image, select_sheet_numbers[i]);
			if (err != ErrNone) {
				prog.Stop(false);
				return err;
			}
			prog.Step();
		}
		prog.Stop(true);
	} else {
		Progress::Wrapper prog(p);
		prog.Create(tr("GB Subdivision").toLocal8Bit().data(), 0, true);
		prog.SetTotalLoops(1);
		prog.SetUnknownSteps();

		auto str_sheet_number = ui.graph_sym_txt->text().toLocal8Bit().toStdString();
		auto output_name = boost::str(boost::format(name_pattern) % str_sheet_number);
		Path output_image = boost::str(boost::format("%s/%s%s") % output_dir %output_name %extension_name.toStdString());
		
		if (output_image.IsEmpty())
			return Error(tr("Output image is empty!").toLocal8Bit().data());
		prog.SetTipText(output_image.String());
		Error err = ExecuteSheet(output_image, str_sheet_number);
		if (err != ErrNone) {
			prog.Stop(false);
			return err;
		}
		prog.Stop(true);
	}

	return ErrNone;
}


const QStringList GetFileFormatChoices(const std::string& append_name,
	const std::string& append_desc,
	const std::string& append_format,
	std::map<QString, QString>& output_format)
{
	QString format_str = GeoDataDriver::GetFormatDescription(DataCapability::Raster | DataCapability::RandomWrite | DataCapability::Create | DataCapability::Georeferencing,
		0, ";;", false).c_str();
	GeoDataDriverList driver_list = GeoDataDriver::GetRegisteredDrivers();

	auto format_data = format_str.split(";;", QString::SkipEmptyParts);
	format_data.erase(format_data.begin());

	QStringList format_list;
	BOOST_FOREACH(auto format, format_data) {
		int pos = format.indexOf("(*");
		if (pos != -1) {
			QString readable_name = format.leftRef(pos - 1).toString();
			BOOST_FOREACH(GeoDataDriver* driver, driver_list) {
				if (driver->GetReadableName() == readable_name) {
					QString extensions = driver->GetExtensionNames();

					QString extension;
					int pos = extensions.indexOf(';');
					if (pos != -1)
						extension = extensions.leftRef(pos).toString();
					else
						extension = extensions;

					QString choice = QString("%1(*%2)").arg(readable_name, extension);
					format_list.push_back(choice);
					output_format[choice] = extension;

					if (format_list.size() == 1
						&& !append_desc.empty() && !append_format.empty() && !append_name.empty()) {
						choice = QString("%1(*%2)").arg(append_desc.c_str(), append_format.c_str());
						format_list.push_back(choice);
						output_format[choice] = extension;
					}
				}
			}
		}
	}
	return format_list;
}

int GDALBuildOverviews(const std::string& dataset_path,
	const std::string& method,
	double factor,
	bool built_in,
	bool force)
{
	RasterDatasetPtr dataset = OpenRasterDataset(dataset_path);
	if (!dataset)
		return -1;
	if (dataset->HasOverviews() && force == false)
		return 0;
	Error err = dataset->BuildOverviews(2.0, GetResamplingModeEnum(method.c_str()), built_in, 0, NULL);
	return err == ErrNone ? 0 : 1;
}
