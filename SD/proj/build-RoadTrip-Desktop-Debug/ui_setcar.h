/********************************************************************************
** Form generated from reading UI file 'setcar.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETCAR_H
#define UI_SETCAR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_setcar
{
public:
    QLabel *label;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QDialog *setcar)
    {
        if (setcar->objectName().isEmpty())
            setcar->setObjectName(QStringLiteral("setcar"));
        setcar->resize(400, 300);
        label = new QLabel(setcar);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(30, 50, 67, 21));
        lineEdit = new QLineEdit(setcar);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(210, 50, 113, 33));
        lineEdit_2 = new QLineEdit(setcar);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(210, 110, 113, 33));
        lineEdit_3 = new QLineEdit(setcar);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(210, 180, 113, 33));
        label_2 = new QLabel(setcar);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(40, 110, 67, 21));
        label_3 = new QLabel(setcar);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(40, 180, 67, 21));
        pushButton = new QPushButton(setcar);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(50, 240, 95, 31));
        pushButton_2 = new QPushButton(setcar);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(250, 240, 95, 31));

        retranslateUi(setcar);
        QObject::connect(pushButton_2, SIGNAL(clicked()), setcar, SLOT(close()));

        QMetaObject::connectSlotsByName(setcar);
    } // setupUi

    void retranslateUi(QDialog *setcar)
    {
        setcar->setWindowTitle(QApplication::translate("setcar", "Dialog", 0));
        label->setText(QApplication::translate("setcar", "Car Brand", 0));
        label_2->setText(QApplication::translate("setcar", "Model", 0));
        label_3->setText(QApplication::translate("setcar", "Year", 0));
        pushButton->setText(QApplication::translate("setcar", "Save", 0));
        pushButton_2->setText(QApplication::translate("setcar", "Cancel", 0));
    } // retranslateUi

};

namespace Ui {
    class setcar: public Ui_setcar {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETCAR_H
