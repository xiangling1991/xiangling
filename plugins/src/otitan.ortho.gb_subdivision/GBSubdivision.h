#ifndef GBSUBDIVISION_H
#define GBSUBDIVISION_H

#include <QTranslator>
#include <TitanFlexUI/TitanFlexUI.h>
#include <TitanSystem/TitanSystem.h>
#include <ImgMapQT/ImgMap.h>
#include "GBSubdivisionExport.h"

class GB_SUBDIVISION GBSubdivision : public titan::ui::CommandPlugin
{
	Q_OBJECT
public:
	GBSubdivision();
	~GBSubdivision();

	virtual void Execute(QAction* action, std::string option, titan::map::qt::MapViewerPtr viewer);
};

#endif // GBSUBDIVISION_H
