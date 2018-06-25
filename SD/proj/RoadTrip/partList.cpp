#include "partList.h"
#include "ui_partList.h"
#include "setpart.h"
#include "carp.h"
#include<QtCore>
#include<QtGui>
#include<QListWidget>
partList::partList(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::partList)
{
    ui->setupUi(this);
}

partList::~partList()
{
    delete ui;
}

void partList::on_pushButton_clicked()
{
    setpart part;
    part.setModal(true);
    part.exec();
    QListWidgetItem *item = new QListWidgetItem(part.part);
    item -> setFlags(item->flags()|Qt::ItemIsEditable);
    ui->listWidget->addItem(item);
}

void partList::on_pushButton_2_clicked()
{

}
