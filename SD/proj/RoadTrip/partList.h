#ifndef PARTLIST_H
#define PARTLIST_H

#include <QDialog>
#include<QListWidgetItem>
namespace Ui {
class partList;
}

class partList : public QDialog
{
    Q_OBJECT

public:
    explicit partList(QWidget *parent = 0);
    ~partList();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::partList *ui;
    QListWidget *listWidget;
};

#endif // PARTLIST_H
