#include "add.h"
#include "ui_add.h"

add::add(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::add)
{
    ui->setupUi(this);
}

add::~add()
{
    delete ui;
}

void add::on_comboBox_currentIndexChanged(int index)
{
    type=index;
}


void add::on_buttonBox_accepted()
{
    flag=1;
}


void add::on_buttonBox_rejected()
{
    flag=0;
}


void add::on_spinBox_valueChanged(int arg1)
{
    num=arg1;
}

