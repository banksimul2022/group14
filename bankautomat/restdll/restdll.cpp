#include "restdll.h"


Restdll::Restdll(QObject *parent) :QObject(parent)
{
     base_url = "http://localhost:3000";
    qDebug()<<"At rest DLL  constructor!";

}

Restdll::~Restdll()
{
    qDebug()<<"At rest DLL  destructor!";

}



void Restdll::recvpostvalues(QString param1, QString param2)
{
qDebug()<<"login kohdassa";
    QJsonObject jsonObj;
    jsonObj.insert("korttinumero",param1);
    jsonObj.insert("PIN",param2);
    QNetworkRequest request1((base_url+"/login"));
    request1.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    userid=param1;

    postmanager = new QNetworkAccessManager(this);
    connect(postmanager, SIGNAL(finished(QNetworkReply*)), this, SLOT(loginslot(QNetworkReply*)));


    reply = postmanager->post(request1, QJsonDocument(jsonObj).toJson());



}

void Restdll::loginslot(QNetworkReply *reply)
{
    loginresponse_data=reply->readAll();
    token="Bearer "+loginresponse_data;
    qDebug()<<loginresponse_data;
    reply->deleteLater();
    postmanager->deleteLater();
    logingetID();



}
void Restdll::logingetID()
{


    qDebug()<<" logingetid kohdassa";
    QNetworkRequest request((base_url+"/Kortti/userid/"+userid));

        request.setRawHeader(QByteArray("Authorization"),(token));

        request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");



        getmanager = new QNetworkAccessManager(this);
        connect(getmanager, SIGNAL(finished(QNetworkReply*)), this, SLOT(IDslot(QNetworkReply*)));

        reply1 = getmanager->get(request);

}


void Restdll::IDslot(QNetworkReply *reply1)
{
    response_data=reply1->readAll();
    qDebug()<<"ID slotissa";
    qDebug()<<"DATA : "+response_data;

   QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
   QJsonArray json_obj = json_doc.array();


   foreach (const QJsonValue & v, json_obj)
   {
       QJsonObject obj = v.toObject();
       qDebug() << obj.value("word").toString();
       QJsonValue score = obj.value("idKortti");
       if (!score.isUndefined())
           qDebug() << score.toInt();
       QJsonValue score2 = obj.value("Tili_idTili");
       if (!score.isUndefined())
           qDebug() << score2.toInt();
       QJsonValue score3 = obj.value("Asiakas_idAsiakas");
       if (!score.isUndefined())
           qDebug() << score3.toInt();
       numidkortti = score.toInt();
       numidtili = score2.toInt();
       numidasiakas = score3.toInt();
   }


idkortti = QString::number(numidkortti);
idtili = QString::number(numidtili);
idasiakas = QString::number(numidasiakas);





    emit returnvalues(response_data);
     reply1->deleteLater();
     getmanager->deleteLater();
}

void Restdll::getsaldo()
{
    qDebug()<<" getsaldo kohdassa";
    QNetworkRequest request((base_url+"/tilitapahtumat/"+idtili));
    //QNetworkRequest request2((base_url+"/tili/"+idtili));

        request.setRawHeader(QByteArray("Authorization"),(token));
         //request2.setRawHeader(QByteArray("Authorization"),(token));

        request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
         //request2.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");



        getmanager = new QNetworkAccessManager(this);
        //getmanager2 = new QNetworkAccessManager(this);
        connect(getmanager, SIGNAL(finished(QNetworkReply*)), this, SLOT(saldoslot(QNetworkReply*)));
        //connect(getmanager2, SIGNAL(finished(QNetworkReply*)), this, SLOT(saldoslot2(QNetworkReply*)));


        reply = getmanager->get(request);
        //reply2 = getmanager2->get(request2);

}
void Restdll::getbalance()
{
    qDebug()<<" getsaldo kohdassa";
    //QNetworkRequest request((base_url+"/tilitapahtumat/"+idtili));
    QNetworkRequest request2((base_url+"/tili/"+idtili));

        //request.setRawHeader(QByteArray("Authorization"),(token));
         request2.setRawHeader(QByteArray("Authorization"),(token));

        //request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
         request2.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");



        //getmanager = new QNetworkAccessManager(this);
        getmanager2 = new QNetworkAccessManager(this);
        //connect(getmanager, SIGNAL(finished(QNetworkReply*)), this, SLOT(saldoslot(QNetworkReply*)));
        connect(getmanager2, SIGNAL(finished(QNetworkReply*)), this, SLOT(saldoslot2(QNetworkReply*)));


        //reply = getmanager->get(request);
        reply2 = getmanager2->get(request2);

}

void Restdll::saldoslot(QNetworkReply *reply)
{
   QByteArray tilitapahtumatresponse_data=reply->readAll();
   qDebug()<<" saldoslot kohdassa";
    qDebug()<<tilitapahtumatresponse_data;

    emit returnvalues(tilitapahtumatresponse_data);
    reply->deleteLater();
    getmanager->deleteLater();

}

void Restdll::saldoslot2(QNetworkReply *reply2)
{
     QByteArray tiliresponse_data=reply2->readAll();
    qDebug()<<" saldoslot2 kohdassa";
     qDebug()<<tiliresponse_data;

     emit returnvalues(tiliresponse_data);
     reply2->deleteLater();
     getmanager2->deleteLater();
}




void Restdll::drawraha(double saldonmuutos)
{

    qDebug()<<" drawraha kohdassa";

        QJsonObject jsonObj;
        jsonObj.insert("saldomuutos",saldonmuutos);
        jsonObj.insert("tiliID",idtili);
        QNetworkRequest request1((base_url+"/tili"));

          request1.setRawHeader(QByteArray("Authorization"),(token));

        request1.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
        //userid=param1;

        putmanager = new QNetworkAccessManager(this);
        connect(putmanager, SIGNAL(finished(QNetworkReply*)), this, SLOT(drawslot(QNetworkReply*)));


        reply = putmanager->put(request1, QJsonDocument(jsonObj).toJson());


}
void Restdll::drawcredit(double saldonmuutos)
{

    qDebug()<<" drawraha kohdassa";

        QJsonObject jsonObj;
        jsonObj.insert("saldomuutos",saldonmuutos);
        jsonObj.insert("tiliID",idtili);
        QNetworkRequest request1((base_url+"/credit/tili"));

          request1.setRawHeader(QByteArray("Authorization"),(token));
        request1.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");


        putmanager = new QNetworkAccessManager(this);
        connect(putmanager, SIGNAL(finished(QNetworkReply)), this, SLOT(drawslot(QNetworkReply)));


        reply = putmanager->put(request1, QJsonDocument(jsonObj).toJson());


}

void Restdll::drawslot(QNetworkReply *reply1)
{

        response_data=reply->readAll();
        qDebug()<<"draw slotissa";

        emit returnvalues(response_data);
         reply1->deleteLater();
         putmanager->deleteLater();
}

void Restdll::logout()
{

    qDebug()<<"Logout";
    token=0;
    idkortti="0";
    idtili="0";
    idasiakas="0";

}


