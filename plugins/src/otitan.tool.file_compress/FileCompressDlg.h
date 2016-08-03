#ifndef FILECOMPRESSDLG_H
#define FILECOMPRESSDLG_H

#include <QDialog>
#include <TitanSystem/FileSystem.h>
#include <ImgGadgetQT/ImgGadget.h>

#include "ui_FileCompressDlg.h"

class FileCompressDlg : public QDialog
{
	Q_OBJECT

public:
	FileCompressDlg(QWidget *parent = 0);
	~FileCompressDlg();

signals:
	void Message(const QString& msg);
protected slots:
	void Confirm();
	void AddFiles();
	void FilterFile();
	void RemoveFiles();

	void RemoveSubFiles();
	void AddOutPath();

	void ExchangeCompressMethod();
	void UpdateSubList(QListWidgetItem *item);

	void ShowMessage(const QString& msg);
private:
	void Init();
	void UpdateSubFiles(const QString& path);
	void UpdateSubList(const QString& path);
	const QStringList GetSubFiles(const titan::Path& path);
	void AddFileToList(const QString& path);
	void ValidCheck();
	void Execute();
	titan::Error CompressSinglePackage(titan::Progress *p);
	titan::Error CompressMultiPackage(titan::Progress *p);
private:
	Ui::FileCompressDlg ui;

	typedef std::map<QString, QStringList > FileSubMap;
	FileSubMap file_sub_map;
	QString filter_root_path;
};

#endif // FILECOMPRESSDLG_H
