#ifndef JB_SUBDIVISION_EXPORT_H
#define JB_SUBDIVISION_EXPORT_H

#include <QtCore/qglobal.h>

#ifdef JBSUBDIVISION_LIB
# define JB_SUBDIVISION Q_DECL_EXPORT
#else
# define JB_SUBDIVISION Q_DECL_IMPORT
#endif

#endif // JB_SUBDIVISION_EXPORT_H
