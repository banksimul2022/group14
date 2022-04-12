#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "drawmoney.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

enum states{
    login,
    mainscreen,
    acchistory,
    balance,
    draw,
    credit,
    debit,
    start
};
enum events{
    userlogin,
    usebankactions,
    usenext10,
    useprev10,
    usedraw,
    usecredit,
    usedebit,
    userlogout,
    usebalance,
    back
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void runstatemachine(states,events);


private slots:
    void on_btnlogin_clicked();

    void on_btnactions_clicked();

    void on_btnnext_clicked();

    void on_btnprev_clicked();

    void on_btndraw_clicked();

    void on_btncredit_clicked();

    void on_btndebit_clicked();

    void on_btnlogout_clicked();

    void on_btnback_clicked();

    void on_btnbalance_clicked();

private:
    Ui::MainWindow *ui;
    states state = start;
    events event;
    void loginhandler(events e);
    void mainhandler(events e);
    void historyhandler(events e);
    void balancehandler(events e);
    void drawhandler(events e);
    void credithandler(events e);
    void debithandler(events e);
    void starthandler(events e);

};
#endif // MAINWINDOW_H
