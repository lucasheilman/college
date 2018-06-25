#ifndef FRONT_H
#define FRONT_H

#include <QMainWindow>
#include<QPushButton>
namespace Ui {
class front;
}

class front : public QMainWindow
{
    Q_OBJECT

public:
    explicit front(QWidget *parent = 0);
    ~front();

private slots:
    void on_pushButton_clicked();


private:
    Ui::front *ui;
    void writefile();
};

#endif // FRONT_H
