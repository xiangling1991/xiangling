#include <QFileDialog>
#include <QProcess>
#include <QThread>
#include <QStatusBar>
#include <QMessageBox>
#include <TitanSystem/Exception.h>
#include <TitanSystem/FileSystem.h>
#include "FileExtractDlg.h"

using namespace titan;

FileExtractDlg::FileExtractDlg(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);

	connect(ui.add_file_btn, &QPushButton::clicked, this, &FileExtractDlg::AddCompressFile);
	connect(ui.del_file_btn, &QPushButton::clicked, this, &FileExtractDlg::RemoveCompressFile);
	connect(ui.output_path_btn, &QPushButton::clicked, this, &FileExtractDlg::AddOutputPath);
	connect(this, &FileExtractDlg::Message, this, &FileExtractDlg::ShowMessage);

	connect(ui.ok_btn, &QPushButton::clicked, this, &FileExtractDlg::Confirm);
	connect(ui.cancel_btn, &QPushButton::clicked, this, [this] {reject(); });
}

FileExtractDlg::~FileExtractDlg()
{

}

void FileExtractDlg::AddCompressFile()
{
	auto filter = "All Compressed file(*.zip *.tar *.tar.gz *.tar.bz2);;\
					ZIP(*.zip);;Tar file(*.tar);;GZip file(*.tar.gz);;BZip2 file(*.tar.bz2)";
	auto file_paths = QFileDialog::getOpenFileNames(this, tr("Open"), QString(), filter);
	if (file_paths.isEmpty())
		return;
	ui.file_list->addItems(file_paths);
}

void FileExtractDlg::RemoveCompressFile()
{
	auto items = ui.file_list->selectedItems();
	for (int i = 0; i < items.size(); i++)
		ui.file_list->takeItem(ui.file_list->row(items[i]));
}

void FileExtractDlg::AddOutputPath()
{
	auto path = QFileDialog::getExistingDirectory(this, tr("Open"));
	if (path.isEmpty())
		return;
	ui.output_path_txt->setText(path);
}

void FileExtractDlg::Confirm()
{
	try {
		ValidityCheck();
		Error  error = app::qt::CreateGadget<app::qt::BackgroundExecutor>(BACKGROUND_EXECUTOR)
			->Execute(app::qt::BackgroundTask([this](Progress* p) {return Execute(p); }));
		QMessageBox::information(this, tr("Information"), QString::fromLocal8Bit(error.Description().c_str()));
		accept();
	} catch (std::exception& e) {
		QMessageBox::warning(this, tr("Warning"), e.what());
	}
}

void FileExtractDlg::ShowMessage(const QString  &msg)
{
	QMessageBox::information(this, tr("Information"), msg);
}

void FileExtractDlg::ValidityCheck()
{
	if (ui.file_list->count() == 0)
		THROW(FormatException, tr("Please add compression files!").toStdString());
	if (ui.output_path_txt->text().isEmpty())
		THROW(FormatException, tr("Please add output path!").toLocal8Bit().toStdString());
}

Error FileExtractDlg::Execute(Progress* p)
{
	auto z_path = titan::GetModulePath() + std::string("/7z.exe");
	if (!Exists(z_path)) {
		emit Message(tr("Can't find 7z application!"));
		return ErrPathNotExist;
	}
	int steps = GetAllSteps();
	Progress::Wrapper prog(p);
	prog.Create(tr("Extract file").toLocal8Bit().toStdString(), steps, true);
	prog.SetTotalLoops(1);
	prog.SetTipText(tr("Beginning extract ...").toStdString());

	std::vector<Path> list_gzbz;
	int count = 0;
	for (int i = 0; i < ui.file_list->count(); i++) {
		auto file_name = ui.file_list->item(i)->text();
		auto out_path = Path(ui.output_path_txt->text().toLocal8Bit());
		auto input_file = Path(file_name.toLocal8Bit());

		QStringList args("x");
		args << file_name;
		args << "-y" << "-aos";
		auto extension = input_file.Extension();
		if (extension != ".zip" && extension != ".tar") {
			out_path /= Path(".temp");
			if (!Exists(out_path.String())
				&& !CreatePath(out_path, FileAccessPrivate))
				continue;
			out_path /= Path(input_file.Stem());
			list_gzbz.push_back(out_path);
		}
		if (ui.extract_same_radio->isChecked()
			&& (extension == ".zip" || extension == ".tar"))
			out_path /= Path(input_file.Stem());
		auto extract_str = "-o" + QString::fromLocal8Bit(out_path.String().c_str());
		args << extract_str;

		prog.SetTipText(input_file.String());
		if (QProcess::execute("7z.exe", args)) {
			if (ui.ignore_err_check->checkState() == Qt::Unchecked)
				emit Message(tr("Extract error occurred!"));
		} else {
			count++;
			if (!prog.Step()) {
				prog.Stop(false);
				break;
			}
		}
	}
	for (int i = 0; i < list_gzbz.size(); i++) {
		Path output_path(ui.output_path_txt->text().toLocal8Bit());
		Path input_file = list_gzbz[i];
		QStringList args("x");
		args << QString::fromLocal8Bit(input_file.String().c_str());
		args << "-y" << "-aos";
		if (ui.extract_same_radio->isChecked())
			output_path /= Path(input_file.Stem());
		QString output_str = "-o" + QString::fromLocal8Bit(output_path.String().c_str());
		args << output_str;
		if (QProcess::execute("7z.exe", args)) {
			if (ui.ignore_err_check->checkState() == Qt::Unchecked)
				emit Message(tr("Extract error occurred!"));
		}
		else {
			steps--;
			if (!prog.Step()) {
				prog.Stop(false);
				break;
			}
		}
	}
	Path temp_path = Path(ui.output_path_txt->text().toLocal8Bit()).Append(".temp");
	if (Exists(temp_path))
		RemovePath(temp_path);
	bool normal_finished = (count == steps);
	prog.Stop(normal_finished);
	QString message = (normal_finished ? tr("Extraction finished") :
		tr("Extraction finished, part of the file error:")) + "\n";
	return Error(titan::ErrNone,
		(message + tr("Total number of files: %1 , the actual number of extraction files: %2.")
			.arg(ui.file_list->count()).arg(count)).toLocal8Bit().data());
}

int FileExtractDlg::GetAllSteps()
{
	int steps = 0;
	for (int i = 0; i < ui.file_list->count(); i++) {
		auto file = ui.file_list->item(i)->text();
		if (file.contains(".tar") || file.contains(".zip"))
			steps++;
		if (file.contains(".tar.gz") || file.contains(".tar.bz2"))
			steps += 2;
	}

	return steps;
}
