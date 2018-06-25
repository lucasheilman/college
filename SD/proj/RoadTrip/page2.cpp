#include "page2.h"
#include "ui_page2.h"
#include "carp.h"
#include "muzak.h"
#include "plan.h"
Page2::Page2(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Page2)
{
    ui->setupUi(this);
}

Page2::~Page2()
{
    delete ui;
}

void Page2::on_pushButton_clicked()
{
    Carp carp;
    carp.setModal(true);
    carp.exec();

}

void Page2::on_pushButton_2_clicked()
{
    plan p;
    p.setModal(true);
    p.exec();
}


void Page2::on_pushButton_3_clicked()
{
    muzak m;
    m.setModal(true);
    m.exec();

}


void Page2::on_pushButton_4_clicked()
{

}


void Page2::on_pushButton_5_clicked()
{
//	writefile();
}


void Page2::on_pushButton_6_clicked()
{

}


