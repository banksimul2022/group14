#ifndef INTERFACE_H
#define INTERFACE_H

#include "interface_global.h"
#include <QDebug>
#include <QObject>
#include "engine.h"

class INTERFACE_EXPORT Interface:public QObject
{

    Q_OBJECT
public:
    Interface(QObject * parent=nullptr);
    ~Interface();
    void sendSignal();
signals:
    void testi(QString);
private:
    engine * pengine;
public slots:
    void receive(QString s);
};

#endif // INTERFACE_H
