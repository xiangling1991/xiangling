#include "JBSubdivision.h"
#include "JBSubdivisionDlg.h"

using namespace titan::ui;

JBSubdivision::JBSubdivision()
{
	QTranslator* trans = new QTranslator(this);
	const char* path = titan::util::GetTranslationPath();

	if (trans->load("jbsubdivision_" + QLocale::system().name() + ".qm", path))
		qApp->installTranslator(trans);
}

JBSubdivision::~JBSubdivision()
{

}

void JBSubdivision::Execute(QAction *action, std::string option, titan::map::qt::MapViewerPtr viewer)
{
	JBSubdivisionDlg* jb_dlg = new JBSubdivisionDlg();
	jb_dlg->exec();
	delete jb_dlg;
}

extern "C" {

JB_SUBDIVISION Plugin* GetPluginObject(const char* id, const char* version)
{
	return new JBSubdivision();
}

}