#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "drawmoney.h"
#include "rfid.h"
#include <QDebug>
#include <QObject>
#include <QString>
#include "interface.h"
#include <QTimer>
#include "restdll.h"
#include <QtNetwork>
#include <QNetworkAccessManager>

//class drawmoney;
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;

}
QT_END_NAMESPACE

enum states{
    mainscreen,
    acchistory,
    balance,
    draw,
    start
};
enum events{
    userlogin,
    usebankactions,
    usenext10,
    useprev10,
    usedraw,
    userlogout,
    usebalance,
    back,
    starttimer
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


public slots:
    void runstatemachine(states,events);
    void getid(QByteArray b);
    void receive(QString);
    void handletimeout();
    void maintimer();
    void returnpostslot(QString);
    void receivedraw(double);
    void receivecredit(double);





private slots:
    void on_btnlogin_clicked();
    void on_btnactions_clicked();
    void on_btnnext_clicked();
    void on_btnprev_clicked();
    void on_btndraw_clicked();
    void on_btnlogout_clicked();
    void on_btnback_clicked();
    void on_btnbalance_clicked();
signals:
   void sendparams(QString param1,QString param2);
   void senddouble(double);
   void getparams();
   void sigcredit();

private:
    Ui::MainWindow *ui;


    RFID * pRFID;
    QString StringID;
    Interface * p1;
    states state = start;
    events event;
    void mainhandler(events e);
    void historyhandler(events e);
    void balancehandler(events e);
    void drawhandler(events e);
    void credithandler(events e);
    void debithandler(events e);
    void starthandler(events e);
    QTimer  timer;
    Restdll * pRest;
    QString param1;
    QString param2;
    //Ui::Drawmoney * pdraw;
    Drawmoney * pdrawmoney;

};
#endif // MAINWINDOW_H
