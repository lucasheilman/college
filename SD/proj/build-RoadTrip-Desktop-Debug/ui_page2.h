/********************************************************************************
** Form generated from reading UI file 'page2.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PAGE2_H
#define UI_PAGE2_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Page2
{
public:
    QLabel *label;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;

    void setupUi(QDialog *Page2)
    {
        if (Page2->objectName().isEmpty())
            Page2->setObjectName(QStringLiteral("Page2"));
        Page2->resize(400, 300);
        label = new QLabel(Page2);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(80, 20, 251, 21));
        pushButton = new QPushButton(Page2);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(30, 70, 281, 31));
        pushButton_2 = new QPushButton(Page2);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(30, 120, 281, 31));
        pushButton_3 = new QPushButton(Page2);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(30, 170, 281, 31));
        pushButton_5 = new QPushButton(Page2);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setGeometry(QRect(30, 240, 61, 31));
        pushButton_6 = new QPushButton(Page2);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        pushButton_6->setGeometry(QRect(294, 240, 41, 31));

        retranslateUi(Page2);
        QObject::connect(pushButton_6, SIGNAL(clicked()), Page2, SLOT(close()));

        QMetaObject::connectSlotsByName(Page2);
    } // setupUi

    void retranslateUi(QDialog *Page2)
    {
        Page2->setWindowTitle(QApplication::translate("Page2", "Dialog", 0));
        label->setText(QApplication::translate("Page2", "What Would You Like To Do?", 0));
        pushButton->setText(QApplication::translate("Page2", "Set Car and Participant", 0));
        pushButton_2->setText(QApplication::translate("Page2", "Set Calendar and Event", 0));
        pushButton_3->setText(QApplication::translate("Page2", "Set Playlist and Song", 0));
        pushButton_5->setText(QApplication::translate("Page2", "Save", 0));
        pushButton_6->setText(QApplication::translate("Page2", "Exit", 0));
    } // retranslateUi

};

namespace Ui {
    class Page2: public Ui_Page2 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PAGE2_H
