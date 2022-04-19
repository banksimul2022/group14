/********************************************************************************
** Form generated from reading UI file 'engine.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ENGINE_H
#define UI_ENGINE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_engine
{
public:
    QPushButton *pushButton_1;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;
    QPushButton *pushButton_8;
    QPushButton *pushButton_9;
    QPushButton *pushButton_clear;
    QPushButton *pushButton_0;
    QPushButton *pushButton_OK;
    QLineEdit *lineEdit;

    void setupUi(QDialog *engine)
    {
        if (engine->objectName().isEmpty())
            engine->setObjectName(QString::fromUtf8("engine"));
        engine->resize(314, 242);
        pushButton_1 = new QPushButton(engine);
        pushButton_1->setObjectName(QString::fromUtf8("pushButton_1"));
        pushButton_1->setGeometry(QRect(10, 40, 91, 41));
        pushButton_2 = new QPushButton(engine);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(110, 40, 91, 41));
        pushButton_3 = new QPushButton(engine);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(210, 40, 91, 41));
        pushButton_4 = new QPushButton(engine);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(10, 90, 91, 41));
        pushButton_5 = new QPushButton(engine);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setGeometry(QRect(110, 90, 91, 41));
        pushButton_6 = new QPushButton(engine);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        pushButton_6->setGeometry(QRect(210, 90, 91, 41));
        pushButton_7 = new QPushButton(engine);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));
        pushButton_7->setGeometry(QRect(10, 140, 91, 41));
        pushButton_8 = new QPushButton(engine);
        pushButton_8->setObjectName(QString::fromUtf8("pushButton_8"));
        pushButton_8->setGeometry(QRect(110, 140, 91, 41));
        pushButton_9 = new QPushButton(engine);
        pushButton_9->setObjectName(QString::fromUtf8("pushButton_9"));
        pushButton_9->setGeometry(QRect(210, 140, 91, 41));
        pushButton_clear = new QPushButton(engine);
        pushButton_clear->setObjectName(QString::fromUtf8("pushButton_clear"));
        pushButton_clear->setGeometry(QRect(10, 190, 91, 41));
        pushButton_0 = new QPushButton(engine);
        pushButton_0->setObjectName(QString::fromUtf8("pushButton_0"));
        pushButton_0->setGeometry(QRect(110, 190, 91, 41));
        pushButton_OK = new QPushButton(engine);
        pushButton_OK->setObjectName(QString::fromUtf8("pushButton_OK"));
        pushButton_OK->setGeometry(QRect(210, 190, 91, 41));
        lineEdit = new QLineEdit(engine);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(10, 10, 291, 21));

        retranslateUi(engine);

        QMetaObject::connectSlotsByName(engine);
    } // setupUi

    void retranslateUi(QDialog *engine)
    {
        engine->setWindowTitle(QCoreApplication::translate("engine", "Dialog", nullptr));
        pushButton_1->setText(QCoreApplication::translate("engine", "1", nullptr));
        pushButton_2->setText(QCoreApplication::translate("engine", "2", nullptr));
        pushButton_3->setText(QCoreApplication::translate("engine", "3", nullptr));
        pushButton_4->setText(QCoreApplication::translate("engine", "4", nullptr));
        pushButton_5->setText(QCoreApplication::translate("engine", "5", nullptr));
        pushButton_6->setText(QCoreApplication::translate("engine", "6", nullptr));
        pushButton_7->setText(QCoreApplication::translate("engine", "7", nullptr));
        pushButton_8->setText(QCoreApplication::translate("engine", "8", nullptr));
        pushButton_9->setText(QCoreApplication::translate("engine", "9", nullptr));
        pushButton_clear->setText(QCoreApplication::translate("engine", "clear", nullptr));
        pushButton_0->setText(QCoreApplication::translate("engine", "0", nullptr));
        pushButton_OK->setText(QCoreApplication::translate("engine", "OK", nullptr));
    } // retranslateUi

};

namespace Ui {
    class engine: public Ui_engine {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ENGINE_H
