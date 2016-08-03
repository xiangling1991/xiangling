#include <QApplication>
#include "FileExtract.h"
#include "FileExtractDlg.h"

using namespace titan::ui;

FileExtract::FileExtract()
{
	QTranslator* trans = new QTranslator(this);
	const char* path = titan::util::GetTranslationPath();

	if (trans->load("fileextract_" + QLocale::system().name() + ".qm", path))
		qApp->installTranslator(trans);
}

FileExtract::~FileExtract()
{

}

void FileExtract::Execute(QAction * action, std::string option, titan::map::qt::MapViewerPtr viewer)
{
	FileExtractDlg* dlg = new FileExtractDlg();
	dlg->exec();
	delete dlg;
}

extern "C" {

FILE_EXTRACT Plugin* GetPluginObject(const char* id, const char* version)
{
	return new FileExtract();
}

}