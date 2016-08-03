#include <QFileDialog>
#include <QMessageBox>
#include <QProcess>
#include <TitanSystem/Exception.h>

#include "FileCompressDlg.h"
#include "FileFilterDlg.h"

using namespace titan;

FileCompressDlg::FileCompressDlg(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);

	Init();

	connect(ui.add_file_btn, &QToolButton::clicked, this, &FileCompressDlg::AddFiles);
	connect(ui.file_del_btn, &QToolButton::clicked, this, &FileCompressDlg::RemoveFiles);
	connect(ui.file_filter_btn, &QToolButton::clicked, this, &FileCompressDlg::FilterFile);
	connect(ui.sub_file_del_btn, &QToolButton::clicked, this, &FileCompressDlg::RemoveSubFiles);
	connect(ui.output_path_btn, &QPushButton::clicked, this, &FileCompressDlg::AddOutPath);
	connect(ui.file_list_radio, &QRadioButton::clicked, this, &FileCompressDlg::ExchangeCompressMethod);
	connect(ui.dir_list_radio, &QRadioButton::clicked, this, &FileCompressDlg::ExchangeCompressMethod);
	connect(ui.contain_sub_check, &QCheckBox::clicked, this, &FileCompressDlg::ExchangeCompressMethod);
	connect(ui.contain_mul_check, &QCheckBox::clicked, this, &FileCompressDlg::ExchangeCompressMethod);
	connect(ui.file_list, SIGNAL(itemClicked(QListWidgetItem *)), this, SLOT(UpdateSubList(QListWidgetItem *)));
	connect(this, &FileCompressDlg::Message, this, &FileCompressDlg::ShowMessage);

	connect(ui.ok_btn, &QPushButton::clicked, this, &FileCompressDlg::Confirm);
	connect(ui.cancel_btn, &QPushButton::clicked, this, [this] {reject(); });
}

FileCompressDlg::~FileCompressDlg()
{
}

void FileCompressDlg::Init()
{
	file_sub_map.clear();
	ui.zip_radio->setChecked(true);
	ui.file_list_radio->setChecked(true);
	ui.contain_sub_check->setChecked(true);
}

void FileCompressDlg::UpdateSubFiles(const QString& path)
{
	Path file_path(path.toLocal8Bit().toStdString());
	auto sub_paths = GetSubFiles(file_path);
	file_sub_map[path] = sub_paths;
}

void FileCompressDlg::UpdateSubList(const QString& path)
{
	ui.sub_file_list->clear();
	auto find_it = file_sub_map.find(path);
	if (find_it != file_sub_map.end()) {
		auto sub_files = find_it->second;
		for (int i = 0; i < sub_files.size(); i++) {
			auto sub_file = sub_files[i];
			QListWidgetItem* item = new QListWidgetItem(sub_file, ui.sub_file_list);
			item->setToolTip(sub_file);
			item->setData(Qt::UserRole, path);
			ui.sub_file_list->addItem(item);
		}
	}
}

const QStringList FileCompressDlg::GetSubFiles(const Path &path)
{
	QStringList sub_paths;
	QDir dir(QString::fromLocal8Bit(path.ParentPath().c_str()));
	auto entry_list = dir.entryInfoList(QDir::Files);
	auto file_name = path.Stem();
	for (int i = 0; i < entry_list.size(); i++) {
		QString entry_path = entry_list[i].absoluteFilePath();
		Path sub_path = Path(entry_path.toLocal8Bit().toStdString());
		if ((sub_path.Stem() == file_name
			|| QString::fromStdString(sub_path.Stem()).contains(path.FileName().c_str()))
			&& path.String() != sub_path.String())
			sub_paths.push_back(entry_path);
	}

	return sub_paths;
}

void FileCompressDlg::AddFileToList(const QString &path)
{
	int count = ui.file_list->count();
	bool is_exist = false;
	for (int i = 0; i < count; i++) {
		if (ui.file_list->item(i)->text() == path)
			is_exist = true;
	}
	if (!is_exist) {
		auto item = new QListWidgetItem(path, ui.file_list);
		item->setToolTip(path);
		ui.file_list->addItem(item);
	}
}

void FileCompressDlg::AddFiles()
{
	if (ui.file_list_radio->isChecked()) {
		QString filter = "GeoTIFF(*.tif *.tiff);;ERDAS Imagine(*.img);;PCI Geomatica(*.pix);;Titan MOS Image(*.mos);;JPG Files(*.jpg);;PNG Files(*.png);;All files (*.*)";
		auto files = QFileDialog::getOpenFileNames(this, tr("Select Files"), QString(), filter);
		if (files.isEmpty())
			return;
		for (int i = 0; i < files.size(); i++) {
			auto path = files[i];
			AddFileToList(path);
		}
		if (ui.contain_sub_check->isChecked()) {
			for (int i = 0; i < files.size(); i++) {
				UpdateSubFiles(files[i]);
			}
		}
		if (ui.file_list->selectedItems().isEmpty()
			&& !file_sub_map.empty())
			UpdateSubList(file_sub_map.begin()->first);
		else {
			auto items = ui.file_list->selectedItems();
			auto file_name = items[items.size() - 1]->text();
			UpdateSubList(file_name);
		}
	} else if (ui.dir_list_radio->isChecked()) {
		auto dir = QFileDialog::getExistingDirectory(this, tr("Open"));
		if (dir.isEmpty())
			return;
		bool is_exists = false;
		for (int i = 0; i < ui.file_list->count(); i++) {
			if (ui.file_list->item(i)->text() == dir)
				is_exists = true;
		}
		if (!is_exists) {
			ui.file_list->addItem(dir);
			file_sub_map[dir] = QStringList();
		}
	}
}

void FileCompressDlg::FilterFile()
{
	FileFilterDlg* dlg = new FileFilterDlg(filter_root_path);
	int res = dlg->exec();

	if (res == QDialog::Accepted) {
		auto filter_files = dlg->GetFilterFiles();
		for (int i = 0; i < filter_files.size(); i++) {
			AddFileToList(filter_files[i]);
			UpdateSubFiles(filter_files[i]);
		}
	}
	if (!file_sub_map.empty())
		UpdateSubList(file_sub_map.begin()->first);
	delete dlg;
}

void FileCompressDlg::RemoveFiles()
{
	auto items = ui.file_list->selectedItems();
	for (int i = 0; i < items.size(); i++) {
		int row = ui.file_list->row(items[i]);
		auto path = items[i]->text();
		if (ui.file_list_radio->isChecked()) {
			auto find_it = file_sub_map.find(path);
			if (find_it != file_sub_map.end())
				file_sub_map.erase(find_it);
		} else if (ui.dir_list_radio->isChecked()) {
			auto find_it = file_sub_map.find(path);
			if (find_it != file_sub_map.end())
				file_sub_map.erase(find_it);
		}
		ui.file_list->takeItem(row);
	}
	if (ui.file_list_radio->isChecked()) {
		if (!file_sub_map.empty()) {
			UpdateSubFiles(file_sub_map.begin()->first);
			UpdateSubList(file_sub_map.begin()->first);
		}
		else
			ui.sub_file_list->clear();
	}
}

void FileCompressDlg::RemoveSubFiles()
{
	auto items = ui.sub_file_list->selectedItems();
	for (int i = 0; i < items.size(); i++) {
		auto item = items[i];
		auto data = item->data(Qt::UserRole).toString();
		if (file_sub_map.find(data) != file_sub_map.end()) {
			auto sub_path = item->text();
			if (file_sub_map[data].contains(sub_path))
				file_sub_map[data].removeOne(sub_path);
		}
		ui.sub_file_list->takeItem(ui.sub_file_list->row(item));
	}
}

void FileCompressDlg::AddOutPath()
{
	auto path = QFileDialog::getExistingDirectory(this, tr("Open"));
	if (path.isEmpty())
		return;
	ui.output_path->setText(path);
}

void FileCompressDlg::ExchangeCompressMethod()
{
	auto ChangeState = [this](bool state) {
		ui.sub_file_label->setVisible(state);
		ui.sub_file_list->setVisible(state);
		ui.sub_file_del_btn->setVisible(state);
	};

	auto obj = sender();
	if (obj == ui.file_list_radio) {
		ChangeState(true);
		ui.file_filter_btn->setEnabled(true);
		ui.contain_sub_check->setChecked(true);
		ui.contain_sub_check->setEnabled(true);
		file_sub_map.clear();
		ui.file_list->clear();
	} else if (obj == ui.dir_list_radio) {
		ChangeState(false);
		ui.file_filter_btn->setDisabled(true);
		ui.contain_sub_check->setChecked(false);
		ui.contain_sub_check->setDisabled(true);
		file_sub_map.clear();
		ui.file_list->clear();
		ui.sub_file_list->clear();
	} else if (obj == ui.contain_sub_check) {
		if (ui.contain_sub_check->isChecked())
			ChangeState(true);
		else
			ChangeState(false);
	}
	else if (obj == ui.contain_mul_check) {
		if (ui.contain_mul_check->isChecked()) {
			ui.output_filename->clear();
			ui.output_filename->setDisabled(true);
		} else
			ui.output_filename->setEnabled(true);
	}
}

void FileCompressDlg::UpdateSubList(QListWidgetItem *item)
{
	if (item) {
		UpdateSubList(item->text());
	}
}

void FileCompressDlg::ShowMessage(const QString &msg)
{
	QMessageBox::information(this, tr("Information"), msg);
}

void FileCompressDlg::ValidCheck()
{
	if (ui.file_list->count() == 0)
		THROW(FormatException, tr("Please specify the need to compress the file or directory!").toStdString());
	if (ui.output_path->text().isEmpty())
		THROW(FormatException, tr("Please fill out output path!").toStdString());
	if (ui.file_list_radio->isChecked()
		&& ui.output_filename->text().isEmpty()
		&& !ui.contain_mul_check->isChecked())
		THROW(FormatException, tr("Please fill out output filename!").toStdString());
}

void FileCompressDlg::Execute()
{
	auto z_path = titan::GetModulePath() + std::string("/7z.exe");
	if (!Exists(z_path)) {
		QMessageBox::warning(this, tr("Warning"), tr("Can't find 7z application!"));
		return;
	}
	Error err;
	if (!ui.contain_mul_check->isChecked()) {
		err = app::qt::CreateGadget<app::qt::BackgroundExecutor>(BACKGROUND_EXECUTOR)
			->Execute(app::qt::BackgroundTask([this](Progress* p) {return CompressSinglePackage(p); }));
	} else {
		err = app::qt::CreateGadget<app::qt::BackgroundExecutor>(BACKGROUND_EXECUTOR)
			->Execute(app::qt::BackgroundTask([this](Progress* p) {return CompressMultiPackage(p); }));
	}

	QMessageBox::information(this, tr("Information"), err.Description().c_str());
}

Error FileCompressDlg::CompressSinglePackage(titan::Progress *p)
{
	QString output_format = ui.zip_radio->isChecked() ? ".zip" : ".tar";

	QStringList cmp_arg("a");
	QString output_path = QString("%1/%2%3").arg(ui.output_path->text(), ui.output_filename->text(), output_format);
	cmp_arg << output_path;

	for (auto it = file_sub_map.begin(); it != file_sub_map.end(); ++it) {
		cmp_arg << it->first;
		if (ui.contain_sub_check->isChecked()) {
			for (int i = 0; i < it->second.size(); i++)
				cmp_arg << it->second[i];
		}
	}
	Progress::Wrapper prog(p);
	prog.Create(tr("Compress files").toLocal8Bit().toStdString(), 0, true);
	prog.SetUnknownSteps();

	if (QProcess::execute("7z.exe", cmp_arg))
		if (ui.ignore_check->checkState() == Qt::Unchecked)
			emit Message(tr("Compression error occurred!"));

	if (ui.tar_bz_btn->isChecked() || ui.tar_gz_btn->isChecked()) {
		cmp_arg.clear();
		cmp_arg << "a";
		QString output_path_tar = output_path + (ui.tar_bz_btn->isChecked() ? ".bz2" : ".gz");
		cmp_arg << output_path_tar;
		cmp_arg << output_path;
		if (QProcess::execute("7z.exe", cmp_arg))
			if (ui.ignore_check->checkState() == Qt::Unchecked)
				emit Message(tr("Compression error occurred!"));

		remove(output_path.toLocal8Bit().toStdString().c_str());
	}
	prog.Stop(true);

	return Error(ErrNone, tr("Compression operation completed.").toLocal8Bit().data());
}

Error FileCompressDlg::CompressMultiPackage(titan::Progress *p)
{
	QString output_format = ui.zip_radio->isChecked() ? ".zip" : ".tar";

	Progress::Wrapper prog(p);
	prog.Create(tr("Compress files").toLocal8Bit().data(), ui.file_list->count(), true);
	prog.SetTotalLoops(1);

	int file_count = 0;
	for (auto it = file_sub_map.begin(); it != file_sub_map.end(); ++it) {
		auto file = it->first;
		QStringList arg("a");
		auto file_name = Path(file.toLocal8Bit().toStdString());
		if (ui.file_list_radio->isChecked())
			file_name.ReplaceExtension();
		QString out_path = QString("%1/%2%3").arg(ui.output_path->text(),
			QString::fromStdString(file_name.FileName()), output_format);
		arg << out_path;
		arg << file;
		if (ui.contain_sub_check->isChecked())
			arg << it->second;
		prog.SetTipText(file_name.FileName());

		if (QProcess::execute("7z.exe", arg))
			if(ui.ignore_check->checkState() == Qt::Unchecked)
				emit Message(tr("Compression error occurred!"));

		if (ui.tar_bz_btn->isChecked() || ui.tar_gz_btn->isChecked()) {
			arg.clear();
			arg << "a";
			QString output_path_tar = out_path + (ui.tar_bz_btn->isChecked() ? ".bz2" : ".gz");
			arg << output_path_tar;
			arg << out_path;
			prog.SetTipText(Path(out_path.toStdString()).FileName());

			if (QProcess::execute("7z.exe", arg)) 
				if (ui.ignore_check->checkState() == Qt::Unchecked)
					emit Message(tr("Compression error occurred!"));
			
			remove(out_path.toLocal8Bit().toStdString().c_str());
		}
		file_count++;
		prog.Step();
	}
	bool normal_finished = (file_count == ui.file_list->count());
	prog.Stop(normal_finished);
	QString message = (normal_finished ? tr("Compression finished:") :
		tr("Compression finished, part of the file error:")) + "\n";

	return Error(titan::ErrNone, (message + tr("Total number of files: %1, \
		the actual number of compressed files: %2.").arg(ui.file_list->count())
		.arg(file_count)).toLocal8Bit().data());
}

void FileCompressDlg::Confirm()
{
	try {
		ValidCheck();
		Execute();
		accept();
	} catch (std::exception& e) {
		QMessageBox::warning(this, tr("Warning"), e.what());
	}
}
