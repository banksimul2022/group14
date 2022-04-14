#ifndef INTERFACE_GLOBAL_H
#define INTERFACE_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(INTERFACE_LIBRARY)
#  define INTERFACE_EXPORT Q_DECL_EXPORT
#else
#  define INTERFACE_EXPORT Q_DECL_IMPORT
#endif

#endif // INTERFACE_GLOBAL_H
