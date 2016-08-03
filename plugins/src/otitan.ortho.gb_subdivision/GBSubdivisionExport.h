#ifndef GB_SUBDIVISION_EXPORT_H
#define GB_SUBDIVISION_EXPORT_H

#include <QtCore/qglobal.h>

#ifdef GBSUBDIVISION_LIB
# define GB_SUBDIVISION Q_DECL_EXPORT
#else
# define GB_SUBDIVISION Q_DECL_IMPORT
#endif

#endif // GBSUBDIVISION_GLOBAL_H
