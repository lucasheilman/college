#include "setpart.h"
#include "ui_setpart.h"
#include<QString>
#include<QFile>
#include<QTextStream>
#include<carp.h>
#include<QMessageBox>
#include<partList.h>


setpart::setpart(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::setpart)
{
    ui->setupUi(this);
}

setpart::~setpart()
{
    delete ui;
}

void setpart::on_pushButton_clicked()
{
    part = ui->lineEdit->text();
    part2 = ui->lineEdit_2->text();
    part3 = ui->lineEdit_3->text();
}
