#include <QFileDialog>
#include <TitanSystem/FileSystem.h>
#include "FileFilterDlg.h"

FileFilterDlg::FileFilterDlg(QString& root_path, QWidget *parent)
	: QDialog(parent),
	root_path(root_path)
{
	ui.setupUi(this);
	ui.file_list->setColumnWidth(0, 20);
	ui.file_list->setColumnWidth(1, 200);

	ScanFiles(root_path);
	connect(ui.root_dir_btn, &QPushButton::clicked, this, &FileFilterDlg::AddDirectory);
	connect(ui.all_select_btn, &QPushButton::clicked, this, &FileFilterDlg::AllSelect);
	connect(ui.clear_btn, &QPushButton::clicked, this, &FileFilterDlg::ClearFiles);
	connect(ui.reverse_btn, &QPushButton::clicked, this, &FileFilterDlg::ReverseSelect);

	connect(ui.ok_btn, &QPushButton::clicked, this, [this] {accept(); });
	connect(ui.cancel_btn, &QPushButton::clicked, this, [this] {reject(); });
}

FileFilterDlg::~FileFilterDlg()
{

}

const QStringList FileFilterDlg::GetFilterFiles()
{
	QStringList filter_files;
	for (int i = 0; i < ui.file_list->rowCount(); i++) {
		auto path = ui.file_list->item(i, 1)->data(Qt::UserRole).toString();
		if (ui.file_list->item(i, 0)->checkState() == Qt::Checked)
			filter_files.push_back(path);
	}

	return filter_files;
}

void FileFilterDlg::AllSelect()
{
	int rows = ui.file_list->rowCount();
	for (int i = 0; i < rows; i++) {
		if (ui.file_list->item(i, 0)->checkState() == Qt::Unchecked)
			ui.file_list->item(i, 0)->setCheckState(Qt::Checked);
	}
}

void FileFilterDlg::ClearFiles()
{
	ui.file_list->setRowCount(0);
}

void FileFilterDlg::ReverseSelect()
{
	int rows = ui.file_list->rowCount();
	for (int i = 0; i < rows; i++) {
		if (ui.file_list->item(i, 0)->checkState() == Qt::Unchecked)
			ui.file_list->item(i, 0)->setCheckState(Qt::Checked);
		else
			ui.file_list->item(i, 0)->setCheckState(Qt::Unchecked);
	}
}

void FileFilterDlg::ScanFiles(const QString& path)
{
	if (path.isEmpty())
		return;
	QStringList files;
	QDir dir(path);
	auto paths = dir.entryInfoList(QDir::Files);
	for (int i = 0; i < paths.size(); i++) {
		files.push_back(paths[i].absoluteFilePath());
	}

	QStringList filter_files;
	if (!ui.file_format_txt->text().isEmpty()) {
		QString ext_format = ui.file_format_txt->text();
		for (int i = 0; i < files.size(); i++) {
			titan::Path full_path(files[i].toLocal8Bit().toStdString());
			if (full_path.Extension() == ("." + ext_format.toStdString())) {
				filter_files.push_back(files[i]);
			}
		}
	}
	else
		filter_files = files;
	ui.root_dir_txt->setText(path);
	ShowInTable(filter_files);
}

void FileFilterDlg::ShowInTable(const QStringList &paths)
{
	ui.file_list->setRowCount(0);
	for (int i = 0; i < paths.size(); i++) {
		titan::Path path = paths[i].toLocal8Bit().toStdString();
		int rows = ui.file_list->rowCount();
		ui.file_list->insertRow(rows);
		auto item = new QTableWidgetItem();
		item->setCheckState(Qt::Checked);
		ui.file_list->setItem(rows, 0, item);
		ui.file_list->setItem(rows, 1, new QTableWidgetItem(QString::fromStdString(path.FileName())));
		ui.file_list->item(rows, 1)->setData(Qt::UserRole, paths[i]);
	}
}

void FileFilterDlg::AddDirectory()
{
	auto path = QFileDialog::getExistingDirectory(this, tr("Open"));
	if (path.isEmpty())
		return;
	ScanFiles(path);
	root_path = path;
}