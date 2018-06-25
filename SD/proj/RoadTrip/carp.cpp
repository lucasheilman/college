#include "carp.h"
#include "ui_carp.h"
#include "setcar.h"
#include "carlist.h"
#include "page2.h"
#include<QtCore>
#include<QtGui>
#include<partList.h>
Carp::Carp(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Carp)
{
    ui->setupUi(this);
//    ui->listWidget->addItem("Hello");
}

Carp::~Carp()
{
    delete ui;
}

void Carp::on_pushButton_clicked()
{
    CarList carl;
    carl.setModal(true);
    carl.exec();
}

void Carp::on_pushButton_2_clicked()
{
    partList partl;
    partl.setModal(true);
    partl.exec();
}

void Carp::on_pushButton_5_clicked()
{
    Page2 p;
    p.setModal(true);
    p.exec();
}
