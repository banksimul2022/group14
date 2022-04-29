#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    pRest = new Restdll(this);



    connect(pRest,SIGNAL(returnvalues(QString)),
            this,SLOT(returnpostslot(QString)));


}


MainWindow::~MainWindow()
{

    delete ui;
    delete pRest;
    pRest= nullptr;
    ui= nullptr;
}


void MainWindow::on_function_clicked()
{
    //pInterface->generateRandomNumber();
}



void MainWindow::recvNumberFunction(short num)
{
    ui->lineEdit->setText(QString::number(num));
}

void MainWindow::recvNumberSignal(short num)
{
    ui->lineEdit2->setText(QString::number(num));
}

void MainWindow::returnpostslot(QString return_data)
{

    ui->lineEdit_4->setText(return_data);


}



void MainWindow::on_Signal_clicked()
{
    connect(this,SIGNAL(sendparams(QString,QString)),
            pRest,SLOT(recvpostvalues(QString,QString)));


    param1 = ui->lineEdit_2->text();
    param2 = ui->lineEdit_3->text();
   emit sendparams(param1,param2);

    disconnect(this,SIGNAL(sendparams(QString,QString)),
            pRest,SLOT(recvpostvalues(QString,QString)));
}


void MainWindow::on_getbtn_clicked()
{
    connect(this,SIGNAL(getparams()),
            pRest,SLOT(getsaldo()));


   emit getparams();

    disconnect(this,SIGNAL(getparams()),
            pRest,SLOT(getsaldo()));
}


void MainWindow::on_pushButton_clicked()
{
    connect(this,SIGNAL(getparams()),
            pRest,SLOT(recvgetAsiakas()));


   emit getparams();

    disconnect(this,SIGNAL(getparams()),
            pRest,SLOT(recvgetAsiakas()));
}


void MainWindow::on_pushButton_2_clicked()
{
    connect(this,SIGNAL(getparams()),
            pRest,SLOT(recvgetKortti()));


   emit getparams();

    disconnect(this,SIGNAL(getparams()),
            pRest,SLOT(recvgetKortti()));
}




void MainWindow::on_pushButton_3_clicked()
{
    connect(this,SIGNAL(senddouble(double)),
            pRest,SLOT(drawraha(double)));

    double saldonmuutos= ui->lineEdit_2->text().toDouble();
   emit senddouble(saldonmuutos);

    disconnect(this,SIGNAL(senddouble(double)),
            pRest,SLOT(drawraha(double)));
}


void MainWindow::on_pushButton_4_clicked()
{
    connect(this,SIGNAL(getparams()),
            pRest,SLOT(logout()));

   emit getparams();

    disconnect(this,SIGNAL(getparams()),
            pRest,SLOT(logout()));
}


void MainWindow::on_pushButton_5_clicked()
{
    connect(this,SIGNAL(senddouble(double)),
            pRest,SLOT(tilidraw(double)));

    emit sendfloat(float1,float2);

    disconnect(this,SIGNAL(senddouble(double)),
            pRest,SLOT(tilidraw(double)));
}

