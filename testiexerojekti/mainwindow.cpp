#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    objectlogin=new Login;
}

MainWindow::~MainWindow()
{
    delete ui;
    delete objectlogin;
    ui=nullptr;
    objectlogin=nullptr;
}


void MainWindow::on_pushButton_clicked()
{
    objectlogin->show();
}

