#ifndef FILE_COMPRESS_EXPORT_H
#define FILE_COMPRESS_EXPORT_H

#include <QtCore/qglobal.h>

#ifdef FILECOMPRESS_LIB
# define FILE_COMPRESS Q_DECL_EXPORT
#else
# define FILE_COMPRESS Q_DECL_IMPORT
#endif

#endif // FILECOMPRESS_GLOBAL_H
