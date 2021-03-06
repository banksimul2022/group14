QT       += core gui
QT       +=network
QT       += serialport
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    drawmoney.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    drawmoney.h \
    mainwindow.h

FORMS += \
    drawmoney.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/RFID/build/release/ -lRFID
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/RFID/build/debug/ -lRFID

INCLUDEPATH += $$PWD/RFID
DEPENDPATH += $$PWD/RFID


win32:CONFIG(release, debug|release): LIBS += -L$$PWD/PINUI/build/release/ -linterface
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/PINUI/build/debug/ -linterface
else:unix: LIBS += -L$$PWD/PINUI/build/ -linterface

INCLUDEPATH += $$PWD/PINUI
DEPENDPATH += $$PWD/PINUI



win32:CONFIG(release, debug|release): LIBS += -L$$PWD/restdll/build/release/ -lrestdll
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/restdll/build/debug/ -lrestdll

INCLUDEPATH += $$PWD/restdll
DEPENDPATH += $$PWD/restdll
