#ifndef RFID_GLOBAL_H
#define RFID_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(RFID_LIBRARY)       //määritellään DLL projektifilessä
#  define RFID_EXPORT Q_DECL_EXPORT // Tämä voimassa DLL:ssä
#else
#  define RFID_EXPORT Q_DECL_IMPORT // tämä voimassa EXE:ssä
#endif

#endif // RFID_GLOBAL_H
