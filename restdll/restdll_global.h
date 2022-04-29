#ifndef RESTDLL_GLOBAL_H
#define RESTDLL_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(RESTDLL_LIBRARY)
#  define RESTDLL_EXPORT Q_DECL_EXPORT
#else
#  define RESTDLL_EXPORT Q_DECL_IMPORT
#endif

#endif // RESTDLL_GLOBAL_H
