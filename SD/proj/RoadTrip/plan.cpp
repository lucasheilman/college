#include "plan.h"
#include "ui_plan.h"

plan::plan(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::plan)
{
    ui->setupUi(this);
}

plan::~plan()
{
    delete ui;
}
