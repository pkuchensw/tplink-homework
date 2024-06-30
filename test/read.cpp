#include "read.h"
#include "ui_read.h"

readme::readme(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::readme)
{
    ui->setupUi(this);


}

readme::~readme()
{
    delete ui;
    delete t1;
    delete t2;
}



