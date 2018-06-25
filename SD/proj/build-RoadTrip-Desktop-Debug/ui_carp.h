/********************************************************************************
** Form generated from reading UI file 'carp.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CARP_H
#define UI_CARP_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Carp
{
public:
    QLabel *label;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_5;

    void setupUi(QDialog *Carp)
    {
        if (Carp->objectName().isEmpty())
            Carp->setObjectName(QStringLiteral("Carp"));
        Carp->resize(400, 300);
        label = new QLabel(Carp);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(140, 30, 131, 21));
        pushButton = new QPushButton(Carp);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(20, 70, 111, 31));
        pushButton_2 = new QPushButton(Carp);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(20, 120, 111, 31));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButton_2->sizePolicy().hasHeightForWidth());
        pushButton_2->setSizePolicy(sizePolicy);
        pushButton_3 = new QPushButton(Carp);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(20, 170, 111, 31));
        pushButton_5 = new QPushButton(Carp);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setGeometry(QRect(20, 220, 111, 31));

        retranslateUi(Carp);
        QObject::connect(pushButton_5, SIGNAL(clicked()), Carp, SLOT(close()));

        QMetaObject::connectSlotsByName(Carp);
    } // setupUi

    void retranslateUi(QDialog *Carp)
    {
        Carp->setWindowTitle(QApplication::translate("Carp", "Dialog", 0));
        label->setText(QApplication::translate("Carp", "Car and Participant", 0));
        pushButton->setText(QApplication::translate("Carp", "Set Car", 0));
        pushButton_2->setText(QApplication::translate("Carp", "Set Participant", 0));
        pushButton_3->setText(QApplication::translate("Carp", "Calculate Gas", 0));
        pushButton_5->setText(QApplication::translate("Carp", "Cancel", 0));
    } // retranslateUi

};

namespace Ui {
    class Carp: public Ui_Carp {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CARP_H
