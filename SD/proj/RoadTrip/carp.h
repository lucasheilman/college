#ifndef CARP_H
#define CARP_H

#include <QDialog>

namespace Ui {
class Carp;
}

class Carp : public QDialog
{
    Q_OBJECT

public:
    explicit Carp(QWidget *parent = 0);
    ~Carp();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_5_clicked();

private:
    Ui::Carp *ui;
};

#endif // CARP_H
