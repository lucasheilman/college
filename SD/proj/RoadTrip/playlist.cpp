#include "playlist.h"
#include "ui_playlist.h"

playlist::playlist(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::playlist)
{
    ui->setupUi(this);
}

playlist::~playlist()
{
    delete ui;
}

void playlist::on_pushButton_clicked()
{

}
