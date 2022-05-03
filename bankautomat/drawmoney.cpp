#include "drawmoney.h"
double drawamount;

Drawmoney::Drawmoney(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Drawmoney)
{
    ui->setupUi(this);

    //pmain = new MainWindow;

//    connect(this,SIGNAL(senddraw(double)),
//            pmain,SLOT(receivedraw(double)));


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
ui->lineEdit->setText(0);
drawamount=0;
close();
}
void Drawmoney::on_btndraw_clicked()
{
qDebug()<<"amount drawissa"<<drawamount;
emit senddraw(drawamount);
ui->lineEdit->setText(0);
drawamount=0;
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
        drawamount = newamount.toDouble();
    return;
}

void Drawmoney::on_btncredit_clicked()
{
    qDebug()<<"amount creditissä"<<drawamount;
    emit sendcredit(drawamount);
    ui->lineEdit->setText(0);
    drawamount=0;
    close();
}

