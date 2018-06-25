/********************************************************************************
** Form generated from reading UI file 'front.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRONT_H
#define UI_FRONT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_front
{
public:
    QWidget *centralWidget;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *front)
    {
        if (front->objectName().isEmpty())
            front->setObjectName(QStringLiteral("front"));
        front->resize(400, 293);
        centralWidget = new QWidget(front);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(110, -10, 121, 41));
        label->setMaximumSize(QSize(121, 16777215));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 30, 101, 31));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 100, 101, 21));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(40, 160, 95, 31));
        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(200, 160, 95, 31));
        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(180, 30, 113, 33));
        lineEdit_2 = new QLineEdit(centralWidget);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(180, 90, 113, 33));
        front->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(front);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 400, 27));
        front->setMenuBar(menuBar);
        mainToolBar = new QToolBar(front);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        front->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(front);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        front->setStatusBar(statusBar);

        retranslateUi(front);
        QObject::connect(pushButton_2, SIGNAL(clicked()), front, SLOT(close()));
        QObject::connect(pushButton, SIGNAL(clicked()), front, SLOT(hide()));

        QMetaObject::connectSlotsByName(front);
    } // setupUi

    void retranslateUi(QMainWindow *front)
    {
        front->setWindowTitle(QApplication::translate("front", "front", 0));
        label->setText(QApplication::translate("front", "Road Trip Planner", 0));
        label_2->setText(QApplication::translate("front", "Name Your Trip", 0));
        label_3->setText(QApplication::translate("front", "Author Name", 0));
        pushButton->setText(QApplication::translate("front", "OK", 0));
        pushButton_2->setText(QApplication::translate("front", "Cancel", 0));
    } // retranslateUi

};

namespace Ui {
    class front: public Ui_front {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRONT_H
