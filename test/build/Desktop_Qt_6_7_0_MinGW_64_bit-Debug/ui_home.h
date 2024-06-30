/********************************************************************************
** Form generated from reading UI file 'home.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HOME_H
#define UI_HOME_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_home
{
public:
    QLabel *label;
    QLabel *loading;
    QLabel *pic;
    QLabel *background_label;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *individual;
    QPushButton *group;
    QPushButton *readme;
    QPushButton *quit;

    void setupUi(QDialog *home)
    {
        if (home->objectName().isEmpty())
            home->setObjectName("home");
        home->resize(738, 413);
        QFont font;
        font.setBold(false);
        font.setItalic(false);
        home->setFont(font);
        home->setCursor(QCursor(Qt::ArrowCursor));
        home->setSizeGripEnabled(false);
        home->setModal(false);
        label = new QLabel(home);
        label->setObjectName("label");
        label->setGeometry(QRect(-30, 40, 301, 101));
        label->setMinimumSize(QSize(301, 0));
        QFont font1;
        font1.setPointSize(20);
        font1.setBold(true);
        font1.setItalic(false);
        font1.setUnderline(false);
        font1.setStrikeOut(false);
        label->setFont(font1);
        loading = new QLabel(home);
        loading->setObjectName("loading");
        loading->setGeometry(QRect(100, 140, 51, 20));
        pic = new QLabel(home);
        pic->setObjectName("pic");
        pic->setGeometry(QRect(260, 140, 121, 121));
        background_label = new QLabel(home);
        background_label->setObjectName("background_label");
        background_label->setGeometry(QRect(0, 0, 741, 421));
        layoutWidget = new QWidget(home);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(40, 170, 161, 161));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        individual = new QPushButton(layoutWidget);
        individual->setObjectName("individual");

        verticalLayout->addWidget(individual);

        group = new QPushButton(layoutWidget);
        group->setObjectName("group");

        verticalLayout->addWidget(group);

        readme = new QPushButton(layoutWidget);
        readme->setObjectName("readme");
        readme->setEnabled(true);

        verticalLayout->addWidget(readme);

        quit = new QPushButton(layoutWidget);
        quit->setObjectName("quit");

        verticalLayout->addWidget(quit);

        layoutWidget->raise();
        background_label->raise();
        pic->raise();
        label->raise();
        loading->raise();

        retranslateUi(home);

        QMetaObject::connectSlotsByName(home);
    } // setupUi

    void retranslateUi(QDialog *home)
    {
        home->setWindowTitle(QCoreApplication::translate("home", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("home", "<html><head/><body><p align=\"center\">welcome to </p><p align=\"center\">home</p></body></html>", nullptr));
        loading->setText(QCoreApplication::translate("home", "Loading.....", nullptr));
        pic->setText(QString());
        background_label->setText(QString());
        individual->setText(QCoreApplication::translate("home", "individual", nullptr));
        group->setText(QCoreApplication::translate("home", "group", nullptr));
        readme->setText(QCoreApplication::translate("home", "readme", nullptr));
        quit->setText(QCoreApplication::translate("home", "quit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class home: public Ui_home {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HOME_H
