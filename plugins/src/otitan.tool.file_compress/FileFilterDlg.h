#ifndef FILEFILTERDLG_H
#define FILEFILTERDLG_H

#include <QDialog>
#include "ui_FileFilterDlg.h"

class FileFilterDlg : public QDialog
{
	Q_OBJECT

public:
	FileFilterDlg(QString& root_path = QString(), QWidget *parent = 0);
	~FileFilterDlg();


	const QStringList GetFilterFiles();
protected slots:
	void AddDirectory();

	void AllSelect();

	void ClearFiles();

	void ReverseSelect();

private:
	void ScanFiles(const QString& path);

	void ShowInTable(const QStringList& paths);
private:
	Ui::FileFilterDlg ui;

	QString& root_path;
};

#endif // FILEFILTERDLG_H
