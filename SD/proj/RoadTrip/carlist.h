#ifndef CARLIST_H
#define CARLIST_H
#include <QDialog>
#include<QListWidgetItem>
namespace Ui {
class CarList;
}

class CarList : public QDialog
{
    Q_OBJECT

public:
    explicit CarList(QWidget *parent = 0);
    ~CarList();

private slots:
    void on_pushButton_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_2_clicked();

    void on_listWidget_itemDoubleClicked(QListWidgetItem *item);

private:
    Ui::CarList *ui;
    QListWidget *listWidget;
};

#endif // CARLIST_H
