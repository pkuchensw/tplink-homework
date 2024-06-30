/********************************************************************************
** Form generated from reading UI file 'group.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GROUP_H
#define UI_GROUP_H

#include <QtCharts/QChartView>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_group
{
public:
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QChartView *graphicsView;

    void setupUi(QDialog *group)
    {
        if (group->objectName().isEmpty())
            group->setObjectName("group");
        group->resize(588, 418);
        pushButton = new QPushButton(group);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(480, 140, 91, 31));
        pushButton_2 = new QPushButton(group);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(479, 237, 91, 31));
        graphicsView = new QChartView(group);
        graphicsView->setObjectName("graphicsView");
        graphicsView->setGeometry(QRect(0, 0, 461, 421));

        retranslateUi(group);

        QMetaObject::connectSlotsByName(group);
    } // setupUi

    void retranslateUi(QDialog *group)
    {
        group->setWindowTitle(QCoreApplication::translate("group", "Dialog", nullptr));
        pushButton->setText(QCoreApplication::translate("group", "start", nullptr));
        pushButton_2->setText(QCoreApplication::translate("group", "quit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class group: public Ui_group {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GROUP_H
