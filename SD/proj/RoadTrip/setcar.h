#ifndef SETCAR_H
#define SETCAR_H

#include <QDialog>
#include<QPushButton>
#include<QString>
#include<carlist.h>
namespace Ui {
class setcar;
}

class setcar : public QDialog
{
    Q_OBJECT

public:
    explicit setcar(QWidget *parent = 0);
    ~setcar();

private slots:
    void on_pushButton_clicked();

private:
    Ui::setcar *ui;

    void readfile();
    void writefile();
public:
    QString car;
    QString car2;
    QString car3;
};


#endif // SETCAR_H
