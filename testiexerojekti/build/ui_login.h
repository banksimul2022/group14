/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Login
{
public:
    QLineEdit *leusername;
    QLineEdit *lepassword;
    QPushButton *loginbtn;

    void setupUi(QDialog *Login)
    {
        if (Login->objectName().isEmpty())
            Login->setObjectName(QString::fromUtf8("Login"));
        Login->resize(400, 300);
        leusername = new QLineEdit(Login);
        leusername->setObjectName(QString::fromUtf8("leusername"));
        leusername->setGeometry(QRect(120, 70, 113, 21));
        lepassword = new QLineEdit(Login);
        lepassword->setObjectName(QString::fromUtf8("lepassword"));
        lepassword->setGeometry(QRect(120, 110, 113, 21));
        loginbtn = new QPushButton(Login);
        loginbtn->setObjectName(QString::fromUtf8("loginbtn"));
        loginbtn->setGeometry(QRect(140, 160, 80, 21));

        retranslateUi(Login);

        QMetaObject::connectSlotsByName(Login);
    } // setupUi

    void retranslateUi(QDialog *Login)
    {
        Login->setWindowTitle(QCoreApplication::translate("Login", "Dialog", nullptr));
        loginbtn->setText(QCoreApplication::translate("Login", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Login: public Ui_Login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
