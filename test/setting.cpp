#include "setting.h"
#include "ui_setting.h"

setting::setting(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::setting)
{
    ui->setupUi(this);
    initial[0]=50; birth[0]=0.1;
    initial[1]=30; birth[1]=0.1;
    initial[2]=10; birth[2]=0.1;
    initial[3]=10; birth[3]=0.1;
    initial[4]=3;  birth[4]=0.1;
    for(int i=5;i<20;i++)initial[i]=0;
}

setting::~setting()
{

    delete ui;
}

void setting::on_initial_num_valueChanged(int arg1)
{
    initial[1]=arg1;
}



void setting::on_initial_num_2_valueChanged(int arg1)
{
    initial[3]=arg1;
}


void setting::on_initial_num_3_valueChanged(int arg1)
{
    initial[0]=arg1;
}


void setting::on_initial_num_7_valueChanged(int arg1)
{
    initial[4]=arg1;
}


void setting::on_initial_num_8_valueChanged(int arg1)
{
    initial[2]=arg1;
}


void setting::on_buttonBox_accepted()
{

}


void setting::on_doubleSpinBox_2_valueChanged(double arg1)
{
    birth[1]=arg1;
}


void setting::on_doubleSpinBox_4_valueChanged(double arg1)
{
    birth[2]=arg1;
}


void setting::on_doubleSpinBox_5_valueChanged(double arg1)
{
    birth[3]=arg1;
}


void setting::on_doubleSpinBox_3_valueChanged(double arg1)
{
    birth[0]=arg1;
}


void setting::on_doubleSpinBox_valueChanged(double arg1)
{
    birth[4]=arg1;
}

