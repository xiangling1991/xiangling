#include "FileCompress.h"
#include "FileCompressDlg.h"

using namespace titan::ui;

FileCompress::FileCompress()
{
	QTranslator* trans = new QTranslator(this);
	const char* path = titan::util::GetTranslationPath();

	if (trans->load("filecompress_" + QLocale::system().name() + ".qm", path))
		qApp->installTranslator(trans);
}

FileCompress::~FileCompress()
{

}

void FileCompress::Execute(QAction * action, std::string option, titan::map::qt::MapViewerPtr viewer)
{
	FileCompressDlg* dlg = new FileCompressDlg();
	dlg->exec();
	delete dlg;
}

extern "C" {

FILE_COMPRESS Plugin* GetPluginObject(const char* id, const char* version)
{
	return new FileCompress();
}

}