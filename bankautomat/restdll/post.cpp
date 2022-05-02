#include "post.h"

#include <QDebug>
post::post()

{
   base_url = "http://localhost:3000";
   qDebug()<<"annetut muuttujat ovat"+param1+param2;
   connect(this,SIGNAL(returnpostvalues(QString)),
           this,SLOT(recvpostvalues(QString,QString)));
}

post::~post()
{

}


void post::recvpostvalues(QString param1, QString param2)
{
    QJsonObject jsonObj;
    jsonObj.insert("idKortti",param1);
    jsonObj.insert("PIN",param2);
    QNetworkRequest request((base_url+"/login"));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    postmanager = new QNetworkAccessManager(this);
    connect(postmanager, SIGNAL(finished (QNetworkReply*)), this, SLOT(postslot(QNetworkReply*)));

    reply = postmanager->post(request, QJsonDocument(jsonObj).toJson());

    response_data=reply->readAll();
    qDebug()<<response_data;
    token="Bearer "+response_data;
  emit returnpostvalues(token);
}

void post::postvalues()
{
  /*  QJsonObject jsonObj;
    jsonObj.insert("idKortti",param1);
    jsonObj.insert("PIN",param2);
    QNetworkRequest request((base_url+"/login"));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    postmanager = new QNetworkAccessManager(this);
    connect(postmanager, SIGNAL(finished (QNetworkReply*)), this, SLOT(postslot(QNetworkReply*)));

    reply = postmanager->post(request, QJsonDocument(jsonObj).toJson());
*/
}

/*void post::loginbtn()
{
    QJsonObject jsonObj;
    jsonObj.insert("idKortti",param1);
    jsonObj.insert("PIN",param2);
    QNetworkRequest request((base_url+"/login"));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    postmanager = new QNetworkAccessManager(this);
    connect(postmanager, SIGNAL(finished (QNetworkReply*)), this, SLOT(postslot(QNetworkReply*)));

    reply = postmanager->post(request, QJsonDocument(jsonObj).toJson());

}*/
/*
void post::on_loginbtn_clicked()
{
   // qDebug()<<"base_url="+base_url;
    param1 =ui->leusername->text();
    param2 =ui->lepassword->text();
    id="id";
    objectbankmain=new bankmain(username,id);
    objectbankmain->show();
    QJsonObject jsonObj;
    jsonObj.insert("idKortti",username);
    jsonObj.insert("PIN",password);


    QNetworkRequest request((base_url+"/login"));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    loginmanager = new QNetworkAccessManager(this);
    connect(loginmanager, SIGNAL(finished (QNetworkReply*)), this, SLOT(loginslot(QNetworkReply*)));

    reply = loginmanager->post(request, QJsonDocument(jsonObj).toJson());
}
*/

void post::postslot(QNetworkReply *reply)
{
    response_data=reply->readAll();
    qDebug()<<response_data;
    token="Bearer "+response_data;
}
