#ifndef FILE_EXTRACT_H
#define FILE_EXTRACT_H

#include <QTranslator>
#include <TitanFlexUI/TitanFlexUI.h>
#include "FileExtractExport.h"

class FILE_EXTRACT FileExtract : public titan::ui::CommandPlugin
{
public:
	FileExtract();
	~FileExtract();

	virtual void Execute(QAction* action, std::string option, titan::map::qt::MapViewerPtr viewer);
};

#endif // FILEEXTRACT_H
