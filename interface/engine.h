#ifndef ENGINE_H
#define ENGINE_H

#include <QDialog>
#include <QDebug>
#include <QPushButton>

namespace Ui {
class engine;
}

class engine : public QDialog
{
    Q_OBJECT

public:
    explicit engine(QWidget *parent = nullptr);
    ~engine();

private slots:
    void on_pushButton_0_clicked();

    void on_pushButton_1_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_clear_clicked();

    void on_pushButton_OK_clicked();


public slots:
    void button_pressed();

private:
    Ui::engine *ui;
    int numbers[4];
    int index = 0;
    QString pin;

signals:
    void interfacelle(QString);
};

#endif // ENGINE_H
