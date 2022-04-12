#include "drawmoney.h"

Drawmoney::Drawmoney(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Drawmoney)
{
    ui->setupUi(this);
}

Drawmoney::~Drawmoney()
{
    delete ui;
}

void Drawmoney::on_btndraw20_clicked()
{
close();
}


void Drawmoney::on_btndraw40_clicked()
{
close();
}


void Drawmoney::on_btndraw60_clicked()
{
close();
}


void Drawmoney::on_btndraw100_clicked()
{
close();
}


void Drawmoney::on_btndraw200_clicked()
{
close();
}


void Drawmoney::on_btndraw500_clicked()
{
close();
}


void Drawmoney::on_btnback_clicked()
{
close();
}


void Drawmoney::on_btndraw_clicked()
{
close();
}

