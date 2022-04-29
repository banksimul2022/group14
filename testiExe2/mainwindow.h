#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "restdll.h"
#include "qstring.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_function_clicked();




    void on_Signal_clicked();

    void on_getbtn_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();



    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

public slots:
    void recvNumberFunction(short);
    void recvNumberSignal(short);
    void returnpostslot(QString);
 signals:
    void generateNumber();
    void sendparams(QString param1,QString param2);
    void sendfloat(float float1,float float2);
    void senddouble(double);
    void getparams();

private:
    Ui::MainWindow *ui;
    Restdll * pRest;
    QString param1;
    QString param2;
    float float1;
    float float2;
};
#endif // MAINWINDOW_H
