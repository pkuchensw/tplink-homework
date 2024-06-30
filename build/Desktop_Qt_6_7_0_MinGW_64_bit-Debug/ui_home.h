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
    QPushButton *readme;
    QPushButton *quit;
    QPushButton *pushButton;

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
        label->setGeometry(QRect(210, 30, 301, 101));
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
        loading->setGeometry(QRect(350, 130, 81, 20));
        pic = new QLabel(home);
        pic->setObjectName("pic");
        pic->setGeometry(QRect(460, 10, 121, 121));
        background_label = new QLabel(home);
        background_label->setObjectName("background_label");
        background_label->setGeometry(QRect(0, 0, 741, 431));
        layoutWidget = new QWidget(home);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(290, 200, 161, 181));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        individual = new QPushButton(layoutWidget);
        individual->setObjectName("individual");

        verticalLayout->addWidget(individual);

        readme = new QPushButton(layoutWidget);
        readme->setObjectName("readme");
        readme->setEnabled(true);

        verticalLayout->addWidget(readme);

        quit = new QPushButton(layoutWidget);
        quit->setObjectName("quit");

        verticalLayout->addWidget(quit);

        pushButton = new QPushButton(home);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(290, 180, 161, 20));
        layoutWidget->raise();
        background_label->raise();
        pic->raise();
        label->raise();
        loading->raise();
        pushButton->raise();

        retranslateUi(home);

        QMetaObject::connectSlotsByName(home);
    } // setupUi

    void retranslateUi(QDialog *home)
    {
        home->setWindowTitle(QCoreApplication::translate("home", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("home", "<html><head/><body><p align=\"center\">welcome to home</p></body></html>", nullptr));
        loading->setText(QCoreApplication::translate("home", "Loading.....", nullptr));
        pic->setText(QString());
        background_label->setText(QString());
        individual->setText(QCoreApplication::translate("home", "individual", nullptr));
        readme->setText(QCoreApplication::translate("home", "readme", nullptr));
        quit->setText(QCoreApplication::translate("home", "quit", nullptr));
        pushButton->setText(QCoreApplication::translate("home", "group", nullptr));
    } // retranslateUi

};

namespace Ui {
    class home: public Ui_home {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HOME_H
