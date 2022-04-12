#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "drawmoney.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::runstatemachine(states s, events e)
{

    switch (s) {
    case login:
        loginhandler(e);
    break;

    case mainscreen:
        mainhandler(e);
    break;

    case acchistory:
        historyhandler(e);
    break;
    case balance:
        balancehandler(e);
    break;
    case draw:
        drawhandler(e);
    break;
    case credit:
        credithandler(e);
    break;
    case debit:
        debithandler(e);
    break;
    case start:
        starthandler(e);

    }
}

void MainWindow::on_btnlogin_clicked()
{
    event = userlogin;
    runstatemachine(state, event);
}


void MainWindow::on_btnactions_clicked()
{
    event = usebankactions;
    runstatemachine(state, event);
}


void MainWindow::on_btnnext_clicked()
{
    event = usenext10;
    runstatemachine(state, event);
}


void MainWindow::on_btnprev_clicked()
{
    event = useprev10;
    runstatemachine(state, event);
}


void MainWindow::on_btndraw_clicked()
{
    event = usedraw;
    runstatemachine(state, event);
}


void MainWindow::on_btncredit_clicked()
{
    event = usecredit;
    runstatemachine(state, event);
}


void MainWindow::on_btndebit_clicked()
{
    event = usedebit;
    runstatemachine(state, event);
}

void MainWindow::on_btnbalance_clicked()
{
    event= usebalance;
    runstatemachine(state, event);
}



void MainWindow::on_btnlogout_clicked()
{
    event = userlogout;
    runstatemachine(state, event);
}
void MainWindow::on_btnback_clicked()
{
    event = back;
    runstatemachine(state, event);
}

void MainWindow::loginhandler(events e)
{
    if (e == userlogin){
        ui->lnscreen->setText("Logged in");
    }
    else {
        ui->lnscreen->setText("Wrong from login");
    }
}

void MainWindow::mainhandler(events e)
{
    if (e == usebankactions){
        ui->lnscreen->setText("Here you can see your account actions");
        event = usebankactions;
        state = acchistory;
        ui->lnstate->setText("acchistory");
    }
    else if (e == usedraw){
        ui->lnscreen->setText("Select Credit or Debit");
        event = usedraw;
        state = draw;
        ui->lnstate->setText("draw");
    }
    else if (e == usebalance){
        ui->lnscreen->setText("Here you can see your account balance");
        event = usebalance;
        state = balance;
        ui->lnstate->setText("balance");
    }
    else if (e == userlogout){
        ui->lnscreen->setText("Logged out");
        event = userlogout;
        state = start;
        ui->lnstate->setText("start");
    }
    else if (e == back){
        ui->lnscreen->setText("back to mainscreen");
        event = back;
        state = mainscreen;
        ui->lnstate->setText("mainscreen");
    }
    else {
        ui->lnscreen->setText("Wrong from main");
    }

}

void MainWindow::historyhandler(events e)
{
    if (e == usenext10){
        ui->lnscreen->setText("next 10 actions");
        event = usenext10;
        //state = acchistory;
        //ui->lnstate->setText("acchistory");
    }
    else if (e == useprev10){
        ui->lnscreen->setText("prev 10 actions");
        event = useprev10;
        //state = acchistory;
        //ui->lnstate->setText("acchistory");
    }
    else if (e == back){
        ui->lnscreen->setText("back to mainscreen");
        event = back;
        state = mainscreen;
        ui->lnstate->setText("mainscreen");
    }
    else {
        ui->lnscreen->setText("Wrong from history");
    }
}

void MainWindow::balancehandler(events e)
{

    if (e == back){
        ui->lnscreen->setText("back to mainscreen");
        event = back;
        state = mainscreen;
        ui->lnstate->setText("mainscreen");
    }
}

void MainWindow::drawhandler(events e)
{
    if (e == usecredit){
        ui->lnscreen->setText("Selected Credit");
        Drawmoney drawmoney;
        drawmoney.setModal(true);
        drawmoney.exec();
        event = usecredit;
        //state = draw;
        //ui->lnstate->setText("draw");
    }
    else if (e == usedebit){
        ui->lnscreen->setText("Selected Debit");
        Drawmoney drawmoney;
        drawmoney.setModal(true);
        drawmoney.exec();
        event = usedebit;
        //state = draw;
        //ui->lnstate->setText("draw");
    }
    else if (e == back){
        ui->lnscreen->setText("back to mainscreen");
        event = back;
        state = mainscreen;
        ui->lnstate->setText("mainscreen");
    }


}

void MainWindow::credithandler(events e)
{
    if (e == usenext10){
        ui->lnscreen->setText("next 10 actions");
        event = usenext10;
        state = acchistory;
        ui->lnstate->setText("acchistory");
    }
    else if (e == back){
        ui->lnscreen->setText("back to mainscreen");
        event = back;
        state = mainscreen;
        ui->lnstate->setText("mainscreen");
    }
}

void MainWindow::debithandler(events e)
{
    if (e == usenext10){
        ui->lnscreen->setText("next 10 actions");
        event = usenext10;
        state = acchistory;
        ui->lnstate->setText("acchistory");
    }
    else if (e == back){
        ui->lnscreen->setText("back to mainscreen");
        event = back;
        state = mainscreen;
        ui->lnstate->setText("mainscreen");
    }
}

void MainWindow::starthandler(events e)
{
    if (e == userlogin){
        ui->lnscreen->setText("Logged in");
        ui->lnstate->setText("mainscreen");
        event = userlogin;
        state = mainscreen;

    }
    else {
        ui->lnscreen->setText("Start by logging in");
    }
}


