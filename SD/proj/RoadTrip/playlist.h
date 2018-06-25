#ifndef PLAYLIST_H
#define PLAYLIST_H

#include <QDialog>

namespace Ui {
class playlist;
}

class playlist : public QDialog
{
    Q_OBJECT

public:/*void playlist::on_pushButton_clicked()
    {
        setcar car;
        car.setModal(true);
        car.exec();
    }
*/
    explicit playlist(QWidget *parent = 0);
    ~playlist();

private slots:
    void on_pushButton_clicked();

private:
    Ui::playlist *ui;
};

#endif // PLAYLIST_H
