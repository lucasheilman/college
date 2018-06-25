#ifndef PAGE2_H
#define PAGE2_H

#include <QDialog>
#include<QPushButton>
namespace Ui {
class Page2;
}

class Page2 : public QDialog
{
    Q_OBJECT

public:
    explicit Page2(QWidget *parent = 0);
    ~Page2();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

private:
    Ui::Page2 *ui;
//    void writefile();
};

#endif // PAGE2_H
