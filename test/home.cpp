#include "home.h"
#include "ui_home.h"
#include"read.h"
#include <QLabel>
#include<qpainter.h>
#include<QInputDialog>
#include<cstring>
#include"mainwindow.h"
#include <QMovie>
#include<group.h>
home::home(QWidget *parent)
    : QDialog(parent),ui(new Ui::home)
{

    ui->setupUi(this);
    t1 = new gifThread(":/image/home.png",741,550);

    ui->background_label->lower();
    t1->label = ui->background_label;//label的内容显示
    //开启线程
    t1->start();

    ui->loading->close();
}

home::~home()
{
    delete ui;
    delete t1;
}

void home::on_individual_clicked()
{

    MainWindow*m=new MainWindow(this);
    //m->showFullScreen();
    m->show();
    ui->loading->close();
}


void home::on_quit_clicked()
{
    this->close();
}



void home::on_individual_pressed()
{
    this->ui->loading->show();
}

void home::on_readme_clicked()
{
    readme* r=new readme;
    r->show();
}


void home::on_pushButton_clicked()
{
    group *g=new group();
    g->show();

}

