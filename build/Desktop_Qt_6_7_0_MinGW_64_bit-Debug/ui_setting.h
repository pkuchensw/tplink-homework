/********************************************************************************
** Form generated from reading UI file 'setting.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTING_H
#define UI_SETTING_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_setting
{
public:
    QDialogButtonBox *buttonBox;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSpinBox *initial_num;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QSpinBox *initial_num_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QSpinBox *initial_num_3;
    QWidget *layoutWidget_2;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_7;
    QSpinBox *initial_num_7;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_8;
    QSpinBox *initial_num_8;
    QHBoxLayout *horizontalLayout_9;

    void setupUi(QDialog *setting)
    {
        if (setting->objectName().isEmpty())
            setting->setObjectName("setting");
        setting->resize(598, 297);
        buttonBox = new QDialogButtonBox(setting);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(10, 230, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        layoutWidget = new QWidget(setting);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(20, 20, 261, 181));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        label = new QLabel(layoutWidget);
        label->setObjectName("label");

        horizontalLayout->addWidget(label);

        initial_num = new QSpinBox(layoutWidget);
        initial_num->setObjectName("initial_num");
        initial_num->setToolTipDuration(-7);
        initial_num->setValue(30);

        horizontalLayout->addWidget(initial_num);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName("label_2");

        horizontalLayout_2->addWidget(label_2);

        initial_num_2 = new QSpinBox(layoutWidget);
        initial_num_2->setObjectName("initial_num_2");
        initial_num_2->setToolTipDuration(-7);
        initial_num_2->setValue(10);

        horizontalLayout_2->addWidget(initial_num_2);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName("label_3");

        horizontalLayout_3->addWidget(label_3);

        initial_num_3 = new QSpinBox(layoutWidget);
        initial_num_3->setObjectName("initial_num_3");
        initial_num_3->setToolTipDuration(-7);
        initial_num_3->setValue(50);

        horizontalLayout_3->addWidget(initial_num_3);


        verticalLayout->addLayout(horizontalLayout_3);

        layoutWidget_2 = new QWidget(setting);
        layoutWidget_2->setObjectName("layoutWidget_2");
        layoutWidget_2->setGeometry(QRect(300, 20, 261, 181));
        verticalLayout_3 = new QVBoxLayout(layoutWidget_2);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        label_7 = new QLabel(layoutWidget_2);
        label_7->setObjectName("label_7");

        horizontalLayout_7->addWidget(label_7);

        initial_num_7 = new QSpinBox(layoutWidget_2);
        initial_num_7->setObjectName("initial_num_7");
        initial_num_7->setToolTipDuration(-7);
        initial_num_7->setValue(5);

        horizontalLayout_7->addWidget(initial_num_7);


        verticalLayout_3->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName("horizontalLayout_8");
        label_8 = new QLabel(layoutWidget_2);
        label_8->setObjectName("label_8");

        horizontalLayout_8->addWidget(label_8);

        initial_num_8 = new QSpinBox(layoutWidget_2);
        initial_num_8->setObjectName("initial_num_8");
        initial_num_8->setToolTipDuration(-7);
        initial_num_8->setValue(10);

        horizontalLayout_8->addWidget(initial_num_8);


        verticalLayout_3->addLayout(horizontalLayout_8);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName("horizontalLayout_9");

        verticalLayout_3->addLayout(horizontalLayout_9);


        retranslateUi(setting);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, setting, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, setting, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(setting);
    } // setupUi

    void retranslateUi(QDialog *setting)
    {
        setting->setWindowTitle(QCoreApplication::translate("setting", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("setting", "initial number of fish", nullptr));
        label_2->setText(QCoreApplication::translate("setting", "initial number of shark ", nullptr));
        label_3->setText(QCoreApplication::translate("setting", "initial number of grass ", nullptr));
        label_7->setText(QCoreApplication::translate("setting", "initial number of whale", nullptr));
        label_8->setText(QCoreApplication::translate("setting", "initial number of  crab ", nullptr));
    } // retranslateUi

};

namespace Ui {
    class setting: public Ui_setting {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTING_H
