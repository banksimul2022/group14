#include "rfid.h"
#include <QDebug>

RFID::RFID(QObject *)
{
    serial = new QSerialPort(this);
}

RFID::~RFID()
{
    delete serial;
    serial = nullptr;
    disconnect(serial, SIGNAL(readyRead()), this, SLOT(recvID()));
}

void RFID::readSerial()
{
    serial->setPortName("COM4");
    serial->open(QIODevice::ReadOnly);
    connect(serial, SIGNAL(readyRead()),this, SLOT(recvID()));
}

void RFID::recvID()
{
    qDebug() <<"vastaanotetaan dataa lukijalta";
    QByteArray ID = serial->read(16).chopped(3).remove(0, 3);
    qDebug() << "Vastaanotettiin data lukijalta-> "<<ID.data();
    StringID = QString(ID);
    qDebug() << "sama stringinä-> "<<StringID;
    emit sendtoexe(ID);

}

