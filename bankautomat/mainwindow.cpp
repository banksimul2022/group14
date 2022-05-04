#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //pRFID = new RFID;
    //pRFID->readSerial();
    //connect(pRFID,SIGNAL(sendtoexe(QByteArray)),this, SLOT(getid(QByteArray)));
    //p1=new Interface(this);
    //connect(p1,SIGNAL(testi(QString)),
    //        this,SLOT(receive(QString)));
    pRest = new Restdll;
    pdrawmoney = new Drawmoney;






    connect(pRest,SIGNAL(returnvalues(QString)),
            this,SLOT(returnpostslot(QString)));

    connect(ui->btnlogin,SIGNAL(clicked()),
            this,SLOT(maintimer()));
    connect(ui->btnbalance,SIGNAL(clicked()),
            this,SLOT(maintimer()));
    connect(ui->btnactions,SIGNAL(clicked()),
            this,SLOT(maintimer()));
    connect(ui->btnnext,SIGNAL(clicked()),
            this,SLOT(maintimer()));
    connect(ui->btnprev,SIGNAL(clicked()),
            this,SLOT(maintimer()));
    connect(ui->btndraw,SIGNAL(clicked()),
            this,SLOT(maintimer()));
    connect(ui->btnback,SIGNAL(clicked()),
            this,SLOT(maintimer()));
    connect(&timer,SIGNAL(timeout()),
            this,SLOT(handletimeout()));
    connect(ui->btnlogout,SIGNAL(clicked()),
            pRest,SLOT(logout()));

    connect(pdrawmoney,SIGNAL(senddraw(double)),
            this,SLOT(receivedraw(double)));
    connect(pdrawmoney,SIGNAL(sendcredit(double)),
            this,SLOT(receivecredit(double)));











}

MainWindow::~MainWindow()
{
    delete ui;
    delete pRFID;
    pRFID = nullptr;
    delete p1;
    p1 = nullptr;
    delete pRest;
    pRest= nullptr;
    delete pdrawmoney;
    pdrawmoney = nullptr;



}

void MainWindow::runstatemachine(states s, events e)
{

    switch (s) {
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
    case start:
        starthandler(e);

    }
}
void MainWindow::returnpostslot(QString return_data)//restdll
{
    ui->lnscreen->setText(return_data);
    if (return_data=="Forbidden"){
        event = userlogin;
        state = start;
        //ui->lnstate->setText("start");
        qDebug()<<"njet";
    }
    qDebug()<<"testidata"+return_data;
}

void MainWindow::receivedraw(double drawamount)
{
    //connect(this,SIGNAL(senddouble(double)),
    //      pRest,SLOT(drawraha(double)));
    //emit senddouble(drawamount);
    qDebug()<<"at drawrahareceive from main";
    qDebug()<<drawamount;
    pRest->drawraha(drawamount);
    ui->lnscreen->setText("Draw done");
}
void MainWindow::receivecredit(double drawamount)
{
    //connect(this,SIGNAL(senddouble(double)),
    //      pRest,SLOT(drawraha(double)));
    //emit senddouble(drawamount);
    qDebug()<<"at drawrahareceive from main";
    qDebug()<<drawamount;
    pRest->drawcredit(drawamount);
    ui->lnscreen->setText("Draw done");
}
void MainWindow::getid(QByteArray b)//RFID
{
   StringID = QString(b);
   qDebug()<<"exessä Qstringinä->:"<<StringID;
   disconnect(pRFID,SIGNAL(sendtoexe(QByteArray)),this, SLOT(getid(QByteArray)));
}

void MainWindow::receive(QString s)//PINUI
{
    //ui->lnscreen->setText(s);
    connect(this,SIGNAL(sendparams(QString,QString)),
            pRest,SLOT(recvpostvalues(QString,QString)));
    param1=StringID;
    param2=s;

    //param1 = ui->lnstate->text();//KORTTINUMERONSYÖTTÖ ILMAN RFID
    //param2 = ui->lnscreen->text();//PIN syöttö
    qDebug()<<"param1";
    qDebug()<<param1;
    qDebug()<<"param2";
    qDebug()<<param2;

   emit sendparams(param1,param2);

    disconnect(this,SIGNAL(sendparams(QString,QString)),
            pRest,SLOT(recvpostvalues(QString,QString)));
}

void MainWindow::maintimer()
{
    //qDebug() << "start timer 30s";
    timer.start(30000);

}


void MainWindow::handletimeout()
{
    qDebug()<<"at timeout";
    ui->lnscreen->setText("Insert card");
    event = userlogout;
    state = start;
    //ui->lnstate->setText("start");
    timer.stop();


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


void MainWindow::mainhandler(events e)
{
    //qDebug()<<"at main";
    maintimer();
    if (e == usebankactions){
        //ui->lnscreen->setText("Here you can see your account actions");
        event = usebankactions;
        state = acchistory;
        pRest->getsaldo();
        //ui->lnstate->setText("acchistory");
        timer.stop();
    }
    else if (e == usedraw){
        ui->lnscreen->setText("Draw money");
        event = usedraw;
        state = mainscreen;
        pdrawmoney->setModal(true);
        pdrawmoney->show();
        //ui->lnstate->setText("draw");
        timer.stop();
    }
    else if (e == usebalance){
        //ui->lnscreen->setText("Here you can see your account balance");
        event = usebalance;
        state = balance;
        //ui->lnstate->setText("balance");
        /*connect(this,SIGNAL(getparams()),
                pRest,SLOT(getsaldo()));


       emit getparams();

        disconnect(this,SIGNAL(getparams()),
                pRest,SLOT(getsaldo()));
                */
        pRest->getbalance();
        timer.stop();
    }
    else if (e == userlogout){
        ui->lnscreen->setText("Insert card");
        event = userlogout;
        state = start;
        //ui->lnstate->setText("start");
        timer.stop();
    }
    else if (e == back){
        ui->lnscreen->setText("back to mainscreen");
        event = back;
        state = mainscreen;
        //ui->lnstate->setText("mainscreen");
        timer.stop();
    }
    else {
        ui->lnscreen->setText("Wrong from main");
        timer.stop();
    }

}

void MainWindow::historyhandler(events e)
{
    if (e == usenext10){
        ui->lnscreen->setText("next 10 actions");
        event = usenext10;

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
        //ui->lnstate->setText("mainscreen");
    }
    else if (e == userlogout){
        ui->lnscreen->setText("Insert card");
        event = userlogout;
        state = start;
        //ui->lnstate->setText("start");
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
        //ui->lnstate->setText("mainscreen");
    }
    else if (e == userlogout){
       ui->lnscreen->setText("Insert card");
       event = userlogout;
       state = start;
       //ui->lnstate->setText("start");

    }
}

void MainWindow::drawhandler(events e)
{
     if (e == back){
        ui->lnscreen->setText("back to mainscreen");

        event = back;
        state = mainscreen;
        //ui->lnstate->setText("mainscreen");

    }
    else if (e == userlogout){
       ui->lnscreen->setText("Insert card");
       event = userlogout;
       state = start;
       //ui->lnstate->setText("start");

    }


}


void MainWindow::starthandler(events e)
{
    //qDebug()<<"at start";
    pRFID = new RFID;
    pRFID->readSerial();
    connect(pRFID,SIGNAL(sendtoexe(QByteArray)),this, SLOT(getid(QByteArray)));
    if (e == userlogin){
        p1=new Interface(this);
        connect(p1,SIGNAL(testi(QString)),
                this,SLOT(receive(QString)));
       //ui->lnscreen->setText(QString(StringID));
        //ui->lnstate->setText("mainscreen");
        event = userlogin;
        state = mainscreen;
    }
    else  {
        ui->lnscreen->setText("Start by logging in");
    }
}
