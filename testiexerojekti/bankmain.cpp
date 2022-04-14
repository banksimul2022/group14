#include "bankmain.h"
#include "ui_bankmain.h"



bankmain::bankmain(QString Uname, QString Uid, QWidget *parent):
QDialog(parent),
ui(new Ui::bankmain)
{
ui->setupUi(this);
ui->labelUsername->setText(Uname);
ui->labelUserid->setText(Uid);

}




bankmain::~bankmain()
{
    delete ui;
}

void bankmain::on_bankbutton1_clicked()
{

}

