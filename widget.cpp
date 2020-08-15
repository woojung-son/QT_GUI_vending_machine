#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>
#include <string>
#include <iostream>
using namespace std;

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    ui->pbCoffee->setEnabled(false);
    ui->pbTea->setEnabled(false);
    ui->pbMilk->setEnabled(false);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_clicked()
{
    changeMoney(10);

}

void Widget::on_pushButton_2_clicked()
{
    changeMoney(50);
}

void Widget::on_pushButton_4_clicked()
{
    changeMoney(100);
}

void Widget::on_pushButton_3_clicked()
{
    changeMoney(500);
}

void Widget::on_pbCoffee_clicked()
{
    changeMoney(-100);
}

void Widget::on_pbTea_clicked()
{
    changeMoney(-150);
}

void Widget::on_pbMilk_clicked()
{
    changeMoney(-200);
}

void Widget::on_pbReset_clicked()
{
    QMessageBox m;
    QMessageBox m2;
    QMessageBox m3;
    QMessageBox m4;QMessageBox m45;
    //m.information(nullptr, "aaaa", "bbbb");
    // nullptr is reserved word.
    // these windows for alerting changes.

    int coin_500 = 0;
    int coin_100 = 0;
    int coin_50 = 0;
    int coin_10 = 0;
    // 500, 100, 50, 10
    if(money > 500){
        coin_500 += money / 500;
        moduliMoney(500);
        m.information(nullptr, "500 WON",
                      ("number of 500 coin : " + to_string(coin_500)).c_str(),
                      "GET", "DON'T GET", "DONATE");
    } if(money > 100){
        cout << "1" << endl;
        coin_100 += money / 100;
        moduliMoney(100);
        m2.information(nullptr, "100 WON",
                      ("number of 100 coin : " + to_string(coin_100)).c_str(),
                      "GET", "DON'T GET", "DONATE");
    } if(money > 50){
        coin_50 += money / 50;
        moduliMoney(50);
        m3.information(nullptr, "50 WON",
                      ("number of 50 coin : " + to_string(coin_50)).c_str(),
                      "GET", "DON'T GET", "DONATE");
    } if(money > 10){
        coin_10 += money / 10;
        moduliMoney(10);
        m4.information(nullptr, "10 WON",
                      ("number of 10 coin : " + to_string(coin_10)).c_str(),
                      "GET", "DON'T GET", "DONATE");
    }
    m45.information(nullptr, "your change : ",
                  ("number of 500 coin :" + to_string(coin_500) +"\n"+
                    "number of 100 coin :" + to_string(coin_100) +"\n"+
                    "number of 50 coin :" + to_string(coin_50) +"\n"+
                    "number of 10 coin :" + to_string(coin_10) +"\n").c_str(),
                  "GET", "DON'T GET", "DONATE");


}

