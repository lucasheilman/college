/********************************************************************************
** Form generated from reading UI file 'muzak.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MUZAK_H
#define UI_MUZAK_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_muzak
{
public:
    QLabel *label;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;

    void setupUi(QDialog *muzak)
    {
        if (muzak->objectName().isEmpty())
            muzak->setObjectName(QStringLiteral("muzak"));
        muzak->resize(400, 300);
        label = new QLabel(muzak);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(100, 30, 131, 21));
        pushButton = new QPushButton(muzak);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(20, 80, 95, 31));
        pushButton_2 = new QPushButton(muzak);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(20, 130, 95, 31));
        pushButton_3 = new QPushButton(muzak);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(20, 230, 95, 31));
        pushButton_4 = new QPushButton(muzak);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(230, 230, 95, 31));

        retranslateUi(muzak);

        QMetaObject::connectSlotsByName(muzak);
    } // setupUi

    void retranslateUi(QDialog *muzak)
    {
        muzak->setWindowTitle(QApplication::translate("muzak", "Dialog", 0));
        label->setText(QApplication::translate("muzak", "Playlists and Songs", 0));
        pushButton->setText(QApplication::translate("muzak", "Set Playlist", 0));
        pushButton_2->setText(QApplication::translate("muzak", "Set Song", 0));
        pushButton_3->setText(QApplication::translate("muzak", "OK", 0));
        pushButton_4->setText(QApplication::translate("muzak", "Cancel", 0));
    } // retranslateUi

};

namespace Ui {
    class muzak: public Ui_muzak {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MUZAK_H
