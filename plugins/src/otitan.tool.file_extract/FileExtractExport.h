#ifndef FILE_EXTRACT_EXPORT_H
#define FILE_EXTRACT_EXPORT_H

#include <QtCore/qglobal.h>

#ifdef FILEEXTRACT_LIB
# define FILE_EXTRACT Q_DECL_EXPORT
#else
# define FILE_EXTRACT Q_DECL_IMPORT
#endif

#endif // FILEEXTRACT_GLOBAL_H
