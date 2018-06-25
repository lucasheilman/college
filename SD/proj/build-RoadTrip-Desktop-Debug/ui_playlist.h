/********************************************************************************
** Form generated from reading UI file 'playlist.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PLAYLIST_H
#define UI_PLAYLIST_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_playlist
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QPlainTextEdit *plainTextEdit;
    QPlainTextEdit *plainTextEdit_2;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QDialog *playlist)
    {
        if (playlist->objectName().isEmpty())
            playlist->setObjectName(QStringLiteral("playlist"));
        playlist->resize(400, 300);
        label = new QLabel(playlist);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(170, 10, 67, 21));
        label_2 = new QLabel(playlist);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(20, 50, 131, 21));
        label_3 = new QLabel(playlist);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(20, 110, 161, 21));
        plainTextEdit = new QPlainTextEdit(playlist);
        plainTextEdit->setObjectName(QStringLiteral("plainTextEdit"));
        plainTextEdit->setGeometry(QRect(220, 50, 151, 41));
        plainTextEdit_2 = new QPlainTextEdit(playlist);
        plainTextEdit_2->setObjectName(QStringLiteral("plainTextEdit_2"));
        plainTextEdit_2->setGeometry(QRect(220, 110, 141, 41));
        pushButton = new QPushButton(playlist);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(30, 240, 95, 31));
        pushButton_2 = new QPushButton(playlist);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(240, 240, 91, 31));

        retranslateUi(playlist);

        QMetaObject::connectSlotsByName(playlist);
    } // setupUi

    void retranslateUi(QDialog *playlist)
    {
        playlist->setWindowTitle(QApplication::translate("playlist", "Dialog", 0));
        label->setText(QApplication::translate("playlist", "Playlist", 0));
        label_2->setText(QApplication::translate("playlist", "Name this Playlist:", 0));
        label_3->setText(QApplication::translate("playlist", "Author of this playlist: ", 0));
        pushButton->setText(QApplication::translate("playlist", "OK", 0));
        pushButton_2->setText(QApplication::translate("playlist", "Cancel", 0));
    } // retranslateUi

};

namespace Ui {
    class playlist: public Ui_playlist {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLAYLIST_H
