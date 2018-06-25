#include "muzak.h"
#include "ui_muzak.h"
#include "playlist.h"
muzak::muzak(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::muzak)
{
    ui->setupUi(this);
}

muzak::~muzak()
{
    delete ui;
}

void muzak::on_pushButton_clicked()
{
    playlist play;
    play.setModal(true);
    play.exec();
}
