/********************************************************************************
** Form generated from reading UI file 'read.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_READ_H
#define UI_READ_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_readme
{
public:
    QWidget *centralwidget;
    QTextBrowser *textBrowser;
    QLabel *readme_label;
    QLabel *readme_label_2;
    QMenuBar *menubar;
    QMenu *menureadme;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *readme)
    {
        if (readme->objectName().isEmpty())
            readme->setObjectName("readme");
        readme->resize(411, 571);
        centralwidget = new QWidget(readme);
        centralwidget->setObjectName("centralwidget");
        textBrowser = new QTextBrowser(centralwidget);
        textBrowser->setObjectName("textBrowser");
        textBrowser->setGeometry(QRect(40, 20, 331, 491));
        readme_label = new QLabel(centralwidget);
        readme_label->setObjectName("readme_label");
        readme_label->setGeometry(QRect(40, 100, 331, 201));
        readme_label_2 = new QLabel(centralwidget);
        readme_label_2->setObjectName("readme_label_2");
        readme_label_2->setGeometry(QRect(40, 300, 331, 201));
        readme->setCentralWidget(centralwidget);
        menubar = new QMenuBar(readme);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 411, 17));
        menureadme = new QMenu(menubar);
        menureadme->setObjectName("menureadme");
        menureadme->setTearOffEnabled(false);
        readme->setMenuBar(menubar);
        statusbar = new QStatusBar(readme);
        statusbar->setObjectName("statusbar");
        readme->setStatusBar(statusbar);

        menubar->addAction(menureadme->menuAction());
        menureadme->addSeparator();

        retranslateUi(readme);

        QMetaObject::connectSlotsByName(readme);
    } // setupUi

    void retranslateUi(QMainWindow *readme)
    {
        readme->setWindowTitle(QCoreApplication::translate("readme", "MainWindow", nullptr));
        textBrowser->setHtml(QCoreApplication::translate("readme", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Microsoft YaHei UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">#######################################</p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:10pt; font-weight:700; font-style:italic;\">hello!</span></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -"
                        "qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:10pt; font-weight:700; font-style:italic;\">This is a simulator for marine ecosystems, </span></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:10pt; font-weight:700; font-style:italic;\">which includes six species of creature: </span></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:10pt; font-weight:700; font-style:italic;\">seaweed, fish, crabs, shrimp, squid, and shark. </span></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:10pt; font-weight:700; font-style:italic;\">If a creature does not prey for a long time, </span></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-botto"
                        "m:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:10pt; font-weight:700; font-style:italic;\">we will consider it dead and delete it. </span></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:10pt; font-weight:700; font-style:italic;\">At the same time, </span></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:10pt; font-weight:700; font-style:italic;\">we also simulated the reproductive process of the creature.</span></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:10pt; font-weight:700; font-style:italic;\"> We tried to pass on the hyperparameters of the parent neural network to see if the offsp"
                        "ring could better adapt to the environment, </span></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:10pt; font-weight:700; font-style:italic;\">even if it was a bit ahead of time for non intelligent creature. </span></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:10pt; font-weight:700; font-style:italic;\">We hope to train various animals </span></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:10pt; font-weight:700; font-style:italic;\">through neural networks to better prey and avoid risks. </span></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><spa"
                        "n style=\" font-size:10pt; font-weight:700; font-style:italic;\">In addition, you can initialize the population size yourself to study the evolution process of the population. </span></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:10pt; font-weight:700; font-style:italic;\">In order to better demonstrate the changes in biological numbers, </span></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:10pt; font-weight:700; font-style:italic;\">we also created a chart to make the simulation process more intuitive. </span></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:10pt; font-weight:700; font-style:italic;\">by wmh  csw szh</span></p>\n"
"<p align=\"c"
                        "enter\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">#######################################</p></body></html>", nullptr));
        readme_label->setText(QString());
        readme_label_2->setText(QString());
        menureadme->setTitle(QString());
    } // retranslateUi

};

namespace Ui {
    class readme: public Ui_readme {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_READ_H
