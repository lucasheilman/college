#ifndef SETPART_H
#define SETPART_H

#include <QDialog>
#include<QPushButton>
#include<QString>
#include<partList.h>
namespace Ui {
class setpart;
}

class setpart : public QDialog
{
    Q_OBJECT

public:
    explicit setpart(QWidget *parent = 0);
    ~setpart();

private slots:
    void on_pushButton_clicked();

private:
    Ui::setpart *ui;

public:
    QString part;
    QString part2;
    QString part3;



};

#endif // SETPART_H
