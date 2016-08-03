#ifndef FILEEXTRACTDLG_H
#define FILEEXTRACTDLG_H

#include <QDialog>
#include <ImgGadgetQT/ImgGadget.h>
#include "ui_FileExtractDlg.h"

class FileExtractDlg : public QDialog
{
	Q_OBJECT

public:
	FileExtractDlg(QWidget *parent = 0);
	~FileExtractDlg();

signals:
	void Message(const QString& msg);
protected slots:
	void AddCompressFile();

	void RemoveCompressFile();

	void AddOutputPath();

	void Confirm();

	void ShowMessage(const QString& msg);
private:
	void ValidityCheck();

	titan::Error Execute(titan::Progress* p);

	int GetAllSteps();
private:
	Ui::FileExtractDlg ui;
};

#endif // FILEEXTRACTDLG_H
