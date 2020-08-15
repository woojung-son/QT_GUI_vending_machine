#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
//#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    int money {0}; // if we declare money val as a global val, it would be shared by all widgets
    void changeMoney(int diff){ // assignment! for combining 2 lines into one
        money += diff;
        ui->lcdNumber->display(money);
        moneyWatcher();
    }
    void moduliMoney(int divisor){
        money = money % divisor;
        ui->lcdNumber->display(money);
    }
    void moneyWatcher(){
        if (money >= 200){
            ui->pbCoffee->setEnabled(true);
            ui->pbTea->setEnabled(true);
            ui->pbMilk->setEnabled(true);
        }
        else if(money >= 150){
            ui->pbCoffee->setEnabled(true);
            ui->pbTea->setEnabled(true);
            ui->pbMilk->setEnabled(false);
        }
        else if(money >= 100){
            ui->pbCoffee->setEnabled(true);
            ui->pbTea->setEnabled(false);
            ui->pbMilk->setEnabled(false);
        }
        else{
            ui->pbCoffee->setEnabled(false);
            ui->pbTea->setEnabled(false);
            ui->pbMilk->setEnabled(false);
        }
    }

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_3_clicked();

    void on_pbCoffee_clicked();

    void on_pbTea_clicked();

    void on_pbMilk_clicked();

    void on_pbReset_clicked();

private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
