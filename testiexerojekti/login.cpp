#include "login.h"
#include "ui_login.h"
#include <QDebug>
Login::Login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
    objectmyurl=new Myurl;
    base_url=objectmyurl->getBase_url();

}

Login::~Login()
{
    delete ui;
    ui=nullptr;
    delete objectbankmain;
    objectbankmain=nullptr;
}

void Login::on_loginbtn_clicked()
{
   // qDebug()<<"base_url="+base_url;
    username =ui->leusername->text();
    password =ui->lepassword->text();
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

void Login::loginslot(QNetworkReply *reply)
{
    response_data=reply->readAll();
    qDebug()<<response_data;
    token="Bearer "+response_data;
}

