#include <QApplication>
#include "GBSubdivision.h"
#include "GBSubdivisionDlg.h"

using namespace titan::ui;

GBSubdivision::GBSubdivision()
{
	QTranslator* trans = new QTranslator(this);
	const char* path = titan::util::GetTranslationPath();

	if (trans->load("gbsubdivision_" + QLocale::system().name() + ".qm", path))
		qApp->installTranslator(trans);

}

GBSubdivision::~GBSubdivision()
{

}

void GBSubdivision::Execute(QAction * action, std::string option, titan::map::qt::MapViewerPtr viewer)
{
	GBSubdivisionDlg* gb_dlg = new GBSubdivisionDlg();
	gb_dlg->exec();
	delete gb_dlg;
}

extern "C" {

GB_SUBDIVISION Plugin* GetPluginObject(const char* id, const char* version)
{
	return new GBSubdivision();
}

}