#include "setcar.h"
#include "ui_setcar.h"
#include<QString>
#include<QFile>
#include<QTextStream>
#include<carp.h>
#include<QMessageBox>
#include<carlist.h>


setcar::setcar(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::setcar)
{
    ui->setupUi(this);
}

setcar::~setcar()
{
    delete ui;
}

void setcar::on_pushButton_clicked()
{
    //readfile();
      //writefile();
    car = ui->lineEdit->text();
    car2 = ui->lineEdit_2->text();
    car3 = ui->lineEdit_3->text();
    //CarList carl;
    //carl.setModal(true);
    //carl.exec();

}
void setcar::readfile(){
    QString filename = "data.txt";
    QFile file(filename);
    if(!file.open(QIODevice::ReadOnly)){
        QMessageBox::information(0, "info", file.errorString());

    }
    QTextStream in(&file);
    //ui->textBrowser -> setText(in.readAll());
}

void setcar::writefile(){
    QString filename = "data.txt";
    QFile file(filename);
    if(!file.open(QIODevice::ReadOnly)){
        QMessageBox::information(0, "info", file.errorString());

}
    QTextStream in(&file);

    //ui->textBrowser -> setText(in.readAll());
    QString str = ui->lineEdit->text();
    QString str2 = ui->lineEdit_2->text();
    QString str3 = ui->lineEdit_3->text();
   // QString filename = "data.txt";
  //  QFile file(filename);
    file.open(QIODevice::WriteOnly|QIODevice::Text);
    QTextStream out(&file);
    out <<"Your car is a "<<str3 << " "<<str<< " "<<str2<<endl;


    CarList carl;
    carl.setModal(true);
    carl.exec();

    //file.close();Í
}
