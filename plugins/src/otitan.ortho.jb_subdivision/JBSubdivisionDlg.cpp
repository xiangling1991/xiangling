#include <QtitanRibbon.h>
#include <QMessageBox>
#include <QFileDialog>
#include <boost/tokenizer.hpp>
#include <gdal/gdal_priv.h>
#include <TitanFlexUI/TitanFlexUI.h>
#include <ImgEngine/ImgEngine.h>
#include <ImgOrtho/ImgSubdivision.h>
#include <ImgOrtho/SheetNumber.h>
#include "JBSubdivisionDlg.h"

Q_DECLARE_METATYPE(titan::ui::PluginPtr)

using namespace titan;
using namespace titan::engine;
using namespace titan::algo::ortho;

const QStringList GetFileFormatChoices(const std::string& append_name, 
				  const std::string& append_desc, 
				  const std::string& append_format, 
				  std::map<QString, QString>& output_format);

int GDALBuildOverviews(const std::string& dataset_path,
	const std::string& method,
	double factor = 2.0,
	bool built_in = false,
	bool force = true);

JBSubdivisionDlg::JBSubdivisionDlg(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	auto format_list = GetFileFormatChoices("GTiff", "GTiff + World File", ".tif", output_format);
	ui.out_format_box->addItems(format_list);
	ui.graph_sym_txt->hide();
	ui.graph_sym_label->hide();

	connect(ui.cut_method_box, SIGNAL(currentIndexChanged(int)), this, SLOT(ExchangeCutMethod(int)));
	connect(ui.input_btn, &QPushButton::clicked, this, &JBSubdivisionDlg::OpenImage);
	connect(ui.output_path_btn, &QPushButton::clicked, this, &JBSubdivisionDlg::AddOutputPath);

	connect(ui.ok_btn, SIGNAL(clicked()), this, SLOT(Confirm()));
	connect(ui.cancel_btn, &QPushButton::clicked, this, [this] {reject(); });
}

JBSubdivisionDlg::~JBSubdivisionDlg()
{

}

void JBSubdivisionDlg::ExchangeCutMethod(int index)
{
	if (index == 0) {
		ui.graph_sym_label->hide();
		ui.graph_sym_txt->hide();
		ui.scale_box->show();
		ui.scale_label->show();
	} else if (index == 1) {
		ui.scale_box->hide();
		ui.scale_label->hide();
		ui.graph_sym_label->show();
		ui.graph_sym_txt->show();
	}
}

void JBSubdivisionDlg::OpenImage()
{
	QString filter = "GeoTIFF(*.tif *.tiff);;ERDAS Imagine(*.img);;PCI Geomatica(*.pix);;Titan MOS Image(*.mos);;JPG Files(*.jpg);;PNG Files(*.png);;All(*)";
	auto img = QFileDialog::getOpenFileName(this, tr("Open Image"), QString(), filter);
	if (img.isEmpty())
		return;
	ui.input_imgs_txt->setText(img);
}

void JBSubdivisionDlg::AddOutputPath()
{
	auto out_path = QFileDialog::getExistingDirectory(this, tr("Open"));
	if (out_path.isEmpty())
		return;
	ui.output_path_txt->setText(out_path);
}

void JBSubdivisionDlg::Confirm()
{
	try {
		ValidityCheck();
		
		Error err = app::qt::CreateGadget<app::qt::BackgroundExecutor>(BACKGROUND_EXECUTOR)
			->Execute(app::qt::BackgroundTask([this](Progress *p) {return Execute(p); }));
		if (err != ErrNone) {
			QMessageBox::warning(this, tr("Warning"), err.Description().c_str());
			return;
		}
		accept();
	} catch(std::exception& e) {
		QMessageBox::information(this, tr("Information"), e.what());
	}
}

void JBSubdivisionDlg::ValidityCheck()
{
	if (ui.input_imgs_txt->text().isEmpty())
		THROW(FormatException, tr("Input image not allowed empty!").toStdString());
	if(ui.output_path_txt->text().isEmpty())
		THROW(FormatException, tr("File output path not allowed empty!").toStdString());
	if (!ui.x_res_txt->text().isEmpty()){
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
		if(!ok || num < 0)
			THROW(FormatException, tr("Expand pixel must be integer and >= 0!").toStdString());
	}
}

Error JBSubdivisionDlg::Execute(Progress *p)
{
	auto input_image = Path(ui.input_imgs_txt->text().toLocal8Bit().toStdString());
	std::string cut_method;
	if (ui.cut_method_box->currentIndex() == 0)
		cut_method = "ByFrame";
	else
		cut_method = "BySheetNumber";

	std::string sheet_scale;
	MapScaleCode jb_scale[7] = {JB873A_10000,
								JB873A_25000,
								JB873A_50000,
								JB873A_100000,
								JB873A_250000,
								JB873A_500000,
								JB873A_1000000 };
	MapScaleCode scale;
	std::string output_dir = ui.output_path_txt->text().toLocal8Bit().toStdString();
	if (cut_method == "ByFrame") {
		int scale_choice = ui.scale_box->currentIndex();
		scale = jb_scale[scale_choice];
		switch (scale) {
			case JB873A_10000: sheet_scale = "JB873A_10000"; break;
			case JB873A_25000: sheet_scale = "JB873A_25000"; break;
			case JB873A_50000: sheet_scale = "JB873A_50000"; break;
			case JB873A_100000:sheet_scale = "JB873A_100000"; break;
			case JB873A_250000:sheet_scale = "JB873A_250000"; break;
			case JB873A_500000:sheet_scale = "JB873A_500000"; break;
			case JB873A_1000000:sheet_scale = "JB873A_1000000"; break;
			default:break;
		}
		if (!Exists(output_dir + "/" + sheet_scale)) {
			output_dir.append("/" + sheet_scale);
			CreatePath(Path(output_dir).String(), FileAccessPublic);
		}
	}
	std::string prefix = ui.file_pre_txt->text().toStdString();
	std::string suffix = ui.file_suf_txt->text().toStdString();
	std::string name_pattern = prefix + "%1" + suffix;

	auto extension_name = output_format[ui.out_format_box->currentText()];
	auto format = drivers[ui.out_format_box->currentText()];

	std::string creation_opts;
	if (ui.out_format_box->currentIndex() == 1)
		creation_opts += "TFW=YES;INTERLEAVE=PIXEL";

	int expand_index = ui.expand_method_box->currentIndex();
	algo::BoundaryExtendType expand_type;
	if (expand_index == 0)
		expand_type = algo::DivExtendRect;
	else
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
	if(!ui.no_data_txt->text().isEmpty())
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
		Error err = CutImgBySheetNumber(input_image, output_image, sheet_num, out_expand,
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

	if (cut_method == "ByFrame") {
		std::vector<std::string> sheet_numbers;
		auto sheet_nums_ptr = GetSheetNumberByScale(scale);
		auto err = sheet_nums_ptr->GetSheetNumbersByImg(input_image, scale, sheet_numbers);
		if (err != ErrNone) {
			QString msg = QString("Calculating the number of points in the input image:%1").arg(err.Description().c_str());
			THROW(Exception, msg.toStdString());
		}
		titan::Progress::Wrapper prog(p);
		prog.Create(tr("JB Subdivision").toLocal8Bit().data(), sheet_numbers.size(), true);
		prog.SetTotalLoops(1);
		
		for (auto i = 0; i < sheet_numbers.size(); i++) {
			auto sheet_num = sheet_numbers[i];
			auto output_img_name = QString::fromStdString(name_pattern).arg(sheet_num.c_str()).toStdString();
			Path output_image = boost::str(boost::format("%s/%s%s") % output_dir %output_img_name %extension_name.toStdString());
			
			if (output_image.IsEmpty())
				continue;
			prog.SetTipText(output_image.String());
			Error err = ExecuteSheet(output_image, sheet_num);
			if (err != ErrNone)
				return err;

			prog.Step();
		}
		prog.Stop(true);
	} else {
		titan::Progress::Wrapper prog(p);
		prog.Create(tr("JB Subdivision").toLocal8Bit().data(), 0, true);
		prog.SetTotalLoops(1);
		prog.SetUnknownSteps();

		auto str_sheet_number = ui.graph_sym_txt->text().toLocal8Bit().toStdString();
		auto output_img_name = QString::fromStdString(name_pattern).arg(str_sheet_number.c_str()).toStdString();
		Path output_image = boost::str(boost::format("%s/%s%s") % output_dir %output_img_name %extension_name.toStdString());
		if (!output_image.IsEmpty()) {
			Error err = ExecuteSheet(output_image, str_sheet_number);
			if (err != ErrNone)
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