#include "engine.h"
#include "ui_engine.h"

engine::engine(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::engine)
{
    ui->setupUi(this);
    qDebug()<<"engine luotu";

}

engine::~engine()
{
    delete ui;
    qDebug()<<"engine tuhottu";
}

void engine::button_pressed()
{
    if(index > 3){
        return;
    }
        QPushButton*button=(QPushButton*)sender();

        short luku;

        luku = (button->text()).toShort();

        numbers[index]=luku;
        index++;
        ui->lineEdit->setText(ui->lineEdit->text()+"*");
        return;

}


void engine::on_pushButton_1_clicked()
{
    //1
    button_pressed();

}


void engine::on_pushButton_2_clicked()
{
    //2
    button_pressed();
}


void engine::on_pushButton_3_clicked()
{
    //3
    button_pressed();
}


void engine::on_pushButton_4_clicked()
{
    //4
    button_pressed();
}


void engine::on_pushButton_5_clicked()
{
    //5
    button_pressed();
}


void engine::on_pushButton_6_clicked()
{
    //6
    button_pressed();
}


void engine::on_pushButton_7_clicked()
{
    //7
    button_pressed();
}


void engine::on_pushButton_8_clicked()
{
    //8
    button_pressed();
}


void engine::on_pushButton_9_clicked()
{
    //9
    button_pressed();
}


void engine::on_pushButton_clear_clicked()
{
    //clear
    if(index <= 4){

        ui->lineEdit->setText("");
        index=0;
    }

}


void engine::on_pushButton_0_clicked()
{
    //0
    button_pressed();
}


void engine::on_pushButton_OK_clicked()
{
    //OK

    if(index == 4){

        pin=QString::number(numbers[0])+QString::number(numbers[1])+QString::number(numbers[2])+QString::number(numbers[3]);

        emit interfacelle(pin);

    }
    close();
}



