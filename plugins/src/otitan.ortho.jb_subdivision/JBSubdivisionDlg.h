#ifndef JBSUBDIVISIONDLG_H
#define JBSUBDIVISIONDLG_H

#include <QDialog>
#include <TitanSystem/TitanSystem.h>
#include <ImgGadgetQT/ImgGadget.h>
#include "ui_JBSubdivisionDlg.h"

class JBSubdivisionDlg : public QDialog
{
	Q_OBJECT

public:
	JBSubdivisionDlg(QWidget *parent = 0);
	~JBSubdivisionDlg();

protected slots:
	void ExchangeCutMethod(int);

	void Confirm();

	void OpenImage();

	void AddOutputPath();
private:
	void ValidityCheck();

	titan::Error Execute(titan::Progress *p);
private:
	Ui::JBSubdivisionDlg ui;
	std::map<QString, QString> output_format;
	std::map<QString, std::string> drivers;
};

#endif // JBSUBDIVISIONDLG_H
