#include "interface.h"



Interface::Interface(QObject *parent):QObject(parent)
{
    qDebug("pin ui DLL luotu");
    pengine=new engine;
    pengine->show();
    connect(pengine,SIGNAL(interfacelle(QString)),
            this,SLOT(receive(QString)));
}

Interface::~Interface()
{
    qDebug("dll tuhottu");
}

void Interface::sendSignal()
{
    emit testi("signaali dll:stä");
}

void Interface::receive(QString s)
{
    //emit testi("signaali enginestä");
    emit testi(s);
}
