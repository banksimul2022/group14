#ifndef RFID_H
#define RFID_H

#include "RFID_global.h"
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QDebug>
#include <QObject>

class RFID_EXPORT RFID: public QObject
{

    Q_OBJECT

public:
    RFID(QObject * parent = nullptr);
    ~RFID();
    void readSerial();
signals:
    void sendtoexe(QByteArray);
public slots:
   void  recvID();
private:
    QSerialPort * serial = nullptr;
    QByteArray ID;

};

#endif // RFID_H
