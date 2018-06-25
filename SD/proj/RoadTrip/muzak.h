#ifndef MUZAK_H
#define MUZAK_H

#include <QDialog>

namespace Ui {
class muzak;
}

class muzak : public QDialog
{
    Q_OBJECT

public:
    explicit muzak(QWidget *parent = 0);
    ~muzak();

private slots:
    void on_pushButton_clicked();

private:
    Ui::muzak *ui;
};

#endif // MUZAK_H
