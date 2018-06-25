/********************************************************************************
** Form generated from reading UI file 'plan.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PLAN_H
#define UI_PLAN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_plan
{
public:
    QLabel *label;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;

    void setupUi(QDialog *plan)
    {
        if (plan->objectName().isEmpty())
            plan->setObjectName(QStringLiteral("plan"));
        plan->resize(400, 300);
        label = new QLabel(plan);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(100, 10, 151, 31));
        QFont font;
        font.setPointSize(16);
        label->setFont(font);
        pushButton = new QPushButton(plan);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(30, 210, 95, 31));
        pushButton_2 = new QPushButton(plan);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(30, 70, 95, 31));
        pushButton_3 = new QPushButton(plan);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(30, 130, 95, 31));
        pushButton_4 = new QPushButton(plan);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(230, 210, 95, 31));

        retranslateUi(plan);

        QMetaObject::connectSlotsByName(plan);
    } // setupUi

    void retranslateUi(QDialog *plan)
    {
        plan->setWindowTitle(QApplication::translate("plan", "Dialog", 0));
        label->setText(QApplication::translate("plan", "Calendar Event", 0));
        pushButton->setText(QApplication::translate("plan", "OK", 0));
        pushButton_2->setText(QApplication::translate("plan", "Set Calendar", 0));
        pushButton_3->setText(QApplication::translate("plan", "Set Event", 0));
        pushButton_4->setText(QApplication::translate("plan", "Cancel", 0));
    } // retranslateUi

};

namespace Ui {
    class plan: public Ui_plan {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLAN_H
