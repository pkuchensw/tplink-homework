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
    QWidget *widget;
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

    void setupUi(QDialog *setting)
    {
        if (setting->objectName().isEmpty())
            setting->setObjectName("setting");
        setting->resize(469, 338);
        buttonBox = new QDialogButtonBox(setting);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(-10, 290, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        widget = new QWidget(setting);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(20, 20, 261, 181));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        label = new QLabel(widget);
        label->setObjectName("label");

        horizontalLayout->addWidget(label);

        initial_num = new QSpinBox(widget);
        initial_num->setObjectName("initial_num");
        initial_num->setToolTipDuration(-7);
        initial_num->setValue(30);

        horizontalLayout->addWidget(initial_num);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label_2 = new QLabel(widget);
        label_2->setObjectName("label_2");

        horizontalLayout_2->addWidget(label_2);

        initial_num_2 = new QSpinBox(widget);
        initial_num_2->setObjectName("initial_num_2");
        initial_num_2->setToolTipDuration(-7);
        initial_num_2->setValue(10);

        horizontalLayout_2->addWidget(initial_num_2);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        label_3 = new QLabel(widget);
        label_3->setObjectName("label_3");

        horizontalLayout_3->addWidget(label_3);

        initial_num_3 = new QSpinBox(widget);
        initial_num_3->setObjectName("initial_num_3");
        initial_num_3->setToolTipDuration(-7);
        initial_num_3->setValue(50);

        horizontalLayout_3->addWidget(initial_num_3);


        verticalLayout->addLayout(horizontalLayout_3);


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
    } // retranslateUi

};

namespace Ui {
    class setting: public Ui_setting {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTING_H
