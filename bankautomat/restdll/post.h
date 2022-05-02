#ifndef POST_H
#define POST_H

#include <QObject>
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>
#include <qstring.h>
#include "restdll_global.h"

class post :public QObject
{
    Q_OBJECT
public:

    explicit post();
    ~post();
    void postvalues();
signals:
    void returnpostvalues(QString);
public slots:
   void recvpostvalues(QString param1,QString param2);
private slots:
    //void loginbtn();
    void postslot(QNetworkReply *reply);
private:

    QString param1;
    QString param2;
    QString id;
    QString base_url;

    QNetworkAccessManager *postmanager;
    QNetworkReply *reply;
    QByteArray response_data;
    QByteArray token;
};

#endif // POST_H
