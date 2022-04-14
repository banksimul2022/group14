/********************************************************************************
** Form generated from reading UI file 'bankmain.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BANKMAIN_H
#define UI_BANKMAIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_bankmain
{
public:
    QPushButton *bankbutton1;
    QLabel *labelUsername;
    QLabel *labelUserid;

    void setupUi(QDialog *bankmain)
    {
        if (bankmain->objectName().isEmpty())
            bankmain->setObjectName(QString::fromUtf8("bankmain"));
        bankmain->resize(400, 300);
        bankbutton1 = new QPushButton(bankmain);
        bankbutton1->setObjectName(QString::fromUtf8("bankbutton1"));
        bankbutton1->setGeometry(QRect(160, 170, 80, 21));
        labelUsername = new QLabel(bankmain);
        labelUsername->setObjectName(QString::fromUtf8("labelUsername"));
        labelUsername->setGeometry(QRect(100, 70, 47, 13));
        labelUserid = new QLabel(bankmain);
        labelUserid->setObjectName(QString::fromUtf8("labelUserid"));
        labelUserid->setGeometry(QRect(200, 70, 47, 13));

        retranslateUi(bankmain);

        QMetaObject::connectSlotsByName(bankmain);
    } // setupUi

    void retranslateUi(QDialog *bankmain)
    {
        bankmain->setWindowTitle(QCoreApplication::translate("bankmain", "Dialog", nullptr));
        bankbutton1->setText(QCoreApplication::translate("bankmain", "PushButton", nullptr));
        labelUsername->setText(QCoreApplication::translate("bankmain", "TextLabel", nullptr));
        labelUserid->setText(QCoreApplication::translate("bankmain", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class bankmain: public Ui_bankmain {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BANKMAIN_H
