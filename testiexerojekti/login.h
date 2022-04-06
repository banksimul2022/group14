#ifndef LOGIN_H
#define LOGIN_H

#include "bankmain.h"
#include "myurl.h"
#include <QDialog>
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>

namespace Ui {
class Login;
}

class Login : public QDialog
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = nullptr);
    ~Login();

private slots:
    void on_loginbtn_clicked();
    void loginslot(QNetworkReply *reply);

private:
    Ui::Login *ui;
    QString username;
    QString password;
    QString id;
    bankmain *objectbankmain;
    Myurl *objectmyurl;
    QString base_url;

    QNetworkAccessManager *loginmanager;
    QNetworkReply *reply;
    QByteArray response_data;
    QByteArray token;
};

#endif // LOGIN_H
