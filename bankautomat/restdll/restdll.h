#ifndef RESTDLL_H
#define RESTDLL_H

#include "restdll_global.h"
#include <QObject>
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>
#include <qstring.h>

class RESTDLL_EXPORT Restdll :public QObject
{
    Q_OBJECT
public:
    Restdll(QObject *parent =nullptr);
    ~Restdll();


signals:
    void returnvalues(QString);

public slots:
   void recvpostvalues(QString param1,QString param2);
   void logingetID();
   void getsaldo();
   void getbalance();
   void drawraha(double saldonmuutos);
   void drawcredit(double saldonmuutos);
   void logout();
private slots:
    //void loginbtn();

     void loginslot(QNetworkReply *reply);
    void IDslot(QNetworkReply *reply1);
    void saldoslot(QNetworkReply *reply);
    void saldoslot2(QNetworkReply *reply2);
    void drawslot(QNetworkReply *reply1);
private:

    QString param1;
    QString param2;
    QString userid;
    QString base_url;


    int numidkortti;
    int numidtili;
    int numidasiakas;

    double numsaldo;


    QString idkortti;
    QString idtili;
    QString idasiakas;

    QString ready;

    QNetworkAccessManager *postmanager;
    QNetworkAccessManager *getmanager;
    QNetworkAccessManager *getmanager2;
    QNetworkAccessManager *putmanager;

    QNetworkReply *reply;
    QNetworkReply *reply1;
    QNetworkReply *reply2;

    QByteArray response_data;
    QByteArray loginresponse_data;
    QByteArray token;


};


#endif // RESTDLL_H
