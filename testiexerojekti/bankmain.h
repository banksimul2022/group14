#ifndef BANKMAIN_H
#define BANKMAIN_H

#include <QDialog>

namespace Ui {
class bankmain;
}

class bankmain : public QDialog
{
    Q_OBJECT

public:
    explicit bankmain(QString Uname,QString Uid,QWidget *parent = nullptr);
    ~bankmain();

private slots:
    void on_bankbutton1_clicked();

private:
    Ui::bankmain *ui;

};

#endif // BANKMAIN_H
