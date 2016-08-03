#ifndef GBSUBDIVISIONDLG_H
#define GBSUBDIVISIONDLG_H

#include <QDialog>
#include <ImgGadgetQT/ImgGadget.h>
#include <TitanSystem/TitanSystem.h>
#include <ImgOrtho/ImgSubdivision.h>
#include "ui_GBSubdivisionDlg.h"

class GBSubdivisionDlg : public QDialog
{
	Q_OBJECT

public:
	GBSubdivisionDlg(QWidget *parent = 0);
	~GBSubdivisionDlg();

protected slots:
	void ExchangeCutMethod(int);

	void Confirm();

	void OpenImage();

	void AddOutputPath();

	void ScaleChanged(int index);

	void CheckChanged(int status);

	void SymbolStateChanged(QTableWidgetItem * item);
private:
	void Init();

	void ValidityCheck();

	titan::Error Execute(titan::Progress *p);

	void ShowGraphSymbol();

	Error CalculateSheets(const std::string& img_path, Progress *p);
	
	void ChangeSubDir();
private:
	Ui::GBSubdivisionDlg ui;

	std::map<QString, QString> output_format;

	titan::algo::ortho::MapScaleCode map_scale;
	std::vector<std::string> sheet_numbers;
	std::string sub_dir;
};

#endif // GBSUBDIVISIONDLG_H
