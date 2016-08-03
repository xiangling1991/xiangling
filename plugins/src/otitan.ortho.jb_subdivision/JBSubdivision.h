#ifndef JB_SUBDIVISION_H
#define JB_SUBDIVISION_H

#include <QTranslator>
#include <TitanFlexUI/TitanFlexUI.h>
#include <TitanSystem/TitanSystem.h>
#include <ImgMapQT/ImgMap.h>
#include "JBSubdivisionExport.h"

class JB_SUBDIVISION JBSubdivision : public titan::ui::CommandPlugin
{
	Q_OBJECT
public:
	JBSubdivision();
	~JBSubdivision();

	virtual void Execute(QAction* action, std::string option, titan::map::qt::MapViewerPtr viewer);
};

#endif // JBSUBDIVISION_H
