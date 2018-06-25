#include "carlist.h"
#include "ui_carlist.h"
#include "setcar.h"
#include "carp.h"
#include<QtCore>
#include<QtGui>
#include<QListWidget>

CarList::CarList(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CarList)
{
    ui->setupUi(this);
  //  ui->listWidget->addItem("hello");
}

CarList::~CarList()
{
    delete ui;
}

void CarList::on_pushButton_clicked()
{
    setcar car;
    car.setModal(true);
    car.exec();
    QListWidgetItem *item = new QListWidgetItem(car.car);
    item -> setFlags(item->flags()|Qt::ItemIsEditable);
    ui->listWidget->addItem(item);
    /*QListWidgetItem *item = new QListWidgetItem(car.car);
    item -> setFlags(item->flags()|Qt::ItemIsEditable);
    ui->listWidget->addItem(item);*/
   // ui->listWidget->currentItem()->setText("Carinfo");
  //  ui->listWidget->addItem(car.car + " "+car.car2+ " "+car.car3);
    //QListWidgetItem * itm =  ui->listWidget->currentItem();//->setText("Carinfo");
    //itm->setText("carrrrr");
    //itm -> setTextColor(Qt::red);

}

void CarList::on_pushButton_4_clicked()
{

    /*setcar car;
    QListWidgetItem *item = new QListWidgetItem(car.car+" "+car.car2+" "+car.car3);
    item -> setFlags(item->flags()|Qt::ItemIsEditable);*/
    Carp carp;
    carp.setModal(true);
    carp.exec();


}

void CarList::on_pushButton_2_clicked()
{
    //QListWidget *listWidget;
    //setcar car;
    /*QListWidgetItem *item = new QListWidgetItem(car.car);
    item -> setFlags(item->flags()|Qt::ItemIsEditable);
    ui->listWidget->addItem(item);*/
    //QListWidgetItem *item = listWidget->takeItem(listWidget->currentRow());
    listWidget->takeItem(listWidget->row(listWidget->currentItem()));
    setcar scar;
    scar.setModal(true);
    scar.exec();
    QListWidgetItem *item = new QListWidgetItem(scar.car);
    item -> setFlags(item->flags()|Qt::ItemIsEditable);
    ui->listWidget->addItem(item);


}
void CarList::on_pushButton_3_clicked(){
 listWidget->takeItem(listWidget->row(listWidget->currentItem()));
}

void CarList::on_listWidget_itemDoubleClicked(QListWidgetItem *item)
{
    ui->listWidget->editItem(item);
   /* setcar scar;
    scar.setModal(true);
    scar.exec();*/


}
