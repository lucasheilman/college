#ifndef PLAN_H
#define PLAN_H

#include <QDialog>

namespace Ui {
class plan;
}

class plan : public QDialog
{
    Q_OBJECT

public:
    explicit plan(QWidget *parent = 0);
    ~plan();

private:
    Ui::plan *ui;
};

#endif // PLAN_H
