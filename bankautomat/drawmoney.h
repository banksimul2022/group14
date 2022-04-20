#ifndef DRAWMONEY_H
#define DRAWMONEY_H

#include <QDialog>

#include "ui_drawmoney.h"
#include "mainwindow.h"

namespace Ui {
class Drawmoney;
}

class Drawmoney : public QDialog
{
    Q_OBJECT

public:
    explicit Drawmoney(QWidget *parent = nullptr);
    ~Drawmoney();

private slots:
    void on_btndraw20_clicked();

    void on_btndraw40_clicked();

    void on_btndraw60_clicked();

    void on_btndraw100_clicked();

    void on_btndraw200_clicked();

    void on_btndraw500_clicked();

    void on_btnback_clicked();

    void on_btndraw_clicked();

public slots:
    void button_press();
private:
    Ui::Drawmoney *ui;
};

#endif // DRAWMONEY_H
