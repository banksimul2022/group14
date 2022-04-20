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
button_press();
}


void Drawmoney::on_btndraw40_clicked()
{
button_press();
}


void Drawmoney::on_btndraw60_clicked()
{
button_press();
}


void Drawmoney::on_btndraw100_clicked()
{
button_press();
}


void Drawmoney::on_btndraw200_clicked()
{
button_press();
}


void Drawmoney::on_btndraw500_clicked()
{
button_press();
}


void Drawmoney::on_btnback_clicked()
{
close();
}


void Drawmoney::on_btndraw_clicked()
{
    close();
}

void Drawmoney::button_press()
{
    QPushButton*button=(QPushButton*)sender();


        int number, number2;
        number = ui->lineEdit->text().toShort();
        number2 = button->text().toShort();

        int amount=number+number2;
        QString newamount = QString::number(amount);
        ui->lineEdit->setText(newamount);
    return;
}

