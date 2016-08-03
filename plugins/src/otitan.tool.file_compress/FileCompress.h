#ifndef FILE_COMPRESS_H
#define FILE_COMPRESS_H

#include <QTranslator>
#include <TitanFlexUI/TitanFlexUI.h>
#include "FileCompressExport.h"

class FILE_COMPRESS FileCompress : public titan::ui::CommandPlugin
{
public:
	FileCompress();
	~FileCompress();

	virtual void Execute(QAction* action, std::string option, titan::map::qt::MapViewerPtr viewer);
};

#endif // FILECOMPRESS_H
