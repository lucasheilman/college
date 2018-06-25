#include "front.h"
#include "ui_front.h"
#include<QString>
#include<QFile>
#include<QTextStream>
#include "page2.h"

front::front(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::front)
{
    ui->setupUi(this);

}

front::~front()
{
    delete ui;
}



void front::on_pushButton_clicked()
{
    writefile();
}
void front::writefile(){
    QString str = ui->lineEdit->text();
    QString str2 = ui->lineEdit_2->text();
    QString filename = "data.txt";
    QFile file(filename);
    file.open(QIODevice::WriteOnly|QIODevice::Text);
    QTextStream out(&file);
    out << "Your trip is: "<<str << "\nYour name is: "<<str2<< endl;
    Page2 page2;
    page2.setModal(true);
    page2.exec();
    //file.close();Í
}


