#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QObject>
#include <random>
#include <QButtonGroup>
#include <QDialog>
#include <QThread>
#include <QPropertyAnimation>
#include <QTimer>
#include <QPainter>
#include <QVBoxLayout>
#include <QMovie>
#include<ctime>
#include<cmath>
#include<cstdlib>
#include"mainwindow.h"
#include"home.h"
#include"mymove.h"
#include"fun.cpp"
#include<creature.h>
#include <QtCharts>
typedef std::vector<creature* >::iterator itc;
typedef std::vector<mymove* >::iterator itmv;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    a=new add();
    timer = new QTimer(this);
    timer2 = new QTimer(this);
    timer3 = new QTimer(this);
    rounds=0;
    this->setWindowTitle("Population Evolution Simulator");

    //t1 = new gifThread(":/image/ocean.png",1331,751);
    ui->background_label->lower();
    //t1->label = ui->background_label;//label的内容显示
    //开启线程
    //t1->start();


    QChart *chart = new QChart();
    chart->setTitle("number graph");

    // 将Chart添加到ChartView
    ui->graphicsView->setChart(chart);
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);

    // 设置图表主题色
    ui->graphicsView->chart()->setTheme(QChart::ChartTheme(0));

    for(int i=0;i<5;i++){
        series[i] = new QLineSeries();
        chart->addSeries(series[i]);
        series[i]->setPointsVisible(false);
        //ui->graphicsView->chart()->addSeries(series[i]);

    }

    series[0]->setName("grass");
    series[1]->setName("fish");
    series[2]->setName("crab");
    series[3]->setName("shark");
    series[4]->setName("whale");

    // 序列添加到图表



    // 创建坐标轴
    QValueAxis *axisX = new QValueAxis;    // X轴
    axisX->setRange(1, 100);               // 设置坐标轴范围
    axisX->setTitleText("revolution time");         // 标题


    QValueAxis *axisY = new QValueAxis;    // Y轴
    axisY->setRange(0, 50);               // Y轴范围(-0 - 20)
    axisY->setTitleText("creature number");         // 标题


    // 设置X于Y轴数据集
    for(int i=0;i<5;i++){
    chart->setAxisX(axisX, series[i]);   // 为序列设置坐标轴
    chart->setAxisY(axisY, series[i]);
    }

    s= new setting;
    for(int i=1;i<=s->initial[0];i++){
        creature* an=new grass(rand()%700,rand()%700,this);
        c.push_back(an);
    }
    for(int i=1;i<=s->initial[1];i++){
        creature* an=new fish(rand()%700,rand()%700,this);
        c.push_back(an);
        mymove *m=new mymove(an,c.begin(),c.end());
        mv.push_back(m);
        connect(timer2, &QTimer::timeout, m, &mymove::moves);
    }
    for(int i=1;i<=s->initial[2];i++){
        creature* an=new crab(rand()%700,rand()%700,this);
        c.push_back(an);
        mymove *m=new mymove(an,c.begin(),c.end());
        mv.push_back(m);
        connect(timer2, &QTimer::timeout, m, &mymove::moves);
    }
    for(int i=1;i<=s->initial[3];i++){
        creature* an=new shark(rand()%700,rand()%700,this);
        c.push_back(an);
        mymove *m=new mymove(an,c.begin(),c.end());
        mv.push_back(m);
        connect(timer2, &QTimer::timeout, m, &mymove::moves);
    }
    for(int i=1;i<=s->initial[4];i++){
        creature* an=new whale(rand()%700,rand()%700,this);
        c.push_back(an);
        mymove *m=new mymove(an,c.begin(),c.end());
        mv.push_back(m);
        connect(timer2, &QTimer::timeout, m, &mymove::moves);
    }
    rounds++;
    for(int i=0;i<3;i++){
        series[i]->append(rounds,qreal(s->initial[i]));
    }
    connect(timer2, &QTimer::timeout, this, &MainWindow::mvupdate);
    connect(timer2, &QTimer::timeout, this, &MainWindow::destruct);
    connect(timer, &QTimer::timeout, this, &MainWindow::forage);
    connect(timer3, &QTimer::timeout, this, &MainWindow::update);
}

MainWindow::~MainWindow()
{
    this->close();
    delete t1;
}
void MainWindow::new_start(){
    std::vector<creature* >::iterator it=c.begin();
    std::vector<mymove* >::iterator it_=mv.begin();
    rounds=0;
    for(int i=0;i<5;i++)series[i]->clear();

    while(!c.empty()){
        (*it)->label->close();
        c.erase(it);
    }
    while(!mv.empty()){
        mv.erase(it_);
    }
    for(int i=1;i<=3*s->initial[0];i++){
        creature* an=new grass(rand()%700,rand()%700,this);
        c.push_back(an);
    }
    for(int i=1;i<=s->initial[1];i++){
        creature* an=new fish(rand()%700,rand()%700,this);
        c.push_back(an);
        mymove *m=new mymove(an,c.begin(),c.end());
        mv.push_back(m);
        connect(timer2, &QTimer::timeout, m, &mymove::moves);
    }
    for(int i=1;i<=s->initial[2];i++){
        creature* an=new crab(rand()%700,rand()%700,this);
        c.push_back(an);
        mymove *m=new mymove(an,c.begin(),c.end());
        mv.push_back(m);
        connect(timer2, &QTimer::timeout, m, &mymove::moves);
    }
    for(int i=1;i<=s->initial[3];i++){
        creature* an=new shark(rand()%700,rand()%700,this);
        c.push_back(an);
        mymove *m=new mymove(an,c.begin(),c.end());
        mv.push_back(m);
        connect(timer2, &QTimer::timeout, m, &mymove::moves);
    }
    for(int i=1;i<=s->initial[4];i++){
        creature* an=new whale(rand()%700,rand()%700,this);
        c.push_back(an);
        mymove *m=new mymove(an,c.begin(),c.end());
        mv.push_back(m);
        connect(timer2, &QTimer::timeout, m, &mymove::moves);
    }
}

void MainWindow::on_pushButton_clicked()
{
    a->show();

    if(a->flag==1){
        creature* an=new shark(rand()%700,rand()%700,this);
        c.push_back(an);
        mymove *m=new mymove(an,c.begin(),c.end());
        mv.push_back(m);
    }


}

void MainWindow::on_pushButton_2_clicked()
{
    this->close();
}

void MainWindow::mvupdate(){
    for(itmv i=mv.begin();i!=mv.end();i++){
        (*i)->st=c.begin();
        (*i)->ed=c.end();
    }
}
void MainWindow::destruct(){
    int num=c.size();
    for(itc i=c.begin();i<c.end();i++){
        for(itc j=c.begin();j<c.end();j++){
            if(i==j) continue;
            if((*j)->life==0||(*i)->life==0)continue;
            if(distance((*i)->labelx,(*i)->labely,(*j)->labelx,(*j)->labely)<=30){
                if(((*i)->type)-((*j)->type)==1 || ((*i)->type)-((*j)->type)==2){
                    (*j)->label->close();
                    (*j)->life=0;
                    (*i)->hp++;
                }
                if(((*i)->type)==0||((*j)->type)==0)continue;
                (*i)->dec->get_points(value((*i),(*j)));
            }
        }
        if((*i)->life==1 && ((*i)->age)-(((*i)->hp)*100)>=1000){
            (*i)->label->close();
            (*i)->life=0;
        }
    }
}

void MainWindow::forage(){
    int num=c.size();
    for(int i=0;i<num;i++){
        if(c[i]->life==0)continue;
        if(c[i]->type==0)continue;
        if(rand()%10+1>=c[i]->breedrate){
            int flag=0;

            for(int j=0;j<num;j++){
                if(c[j]->life==0 && c[j]->type==c[i]->type){
                    c[j]->labelx=c[i]->labelx;
                    c[j]->labely=c[i]->labely;
                    c[j]->age=0;
                    c[j]->label->move(c[j]->labelx,c[j]->labely);
                    c[j]->label->show();
                    c[j]->life=1;
                    flag=1;
                    break;
                }
            }
            if(!flag && c.size()<=250){
                creature *tmp=new creature(*c[i],this);
                c.push_back(tmp);
                mymove *m=new mymove(tmp,c.begin(),c.end());
                mv.push_back(m);
                connect(timer2, &QTimer::timeout, m, &mymove::moves);
            }
        }
    }
}
void MainWindow::update(){
    qDebug()<<c.size();
    if(c.size()<230)for(int i=0;i<=5;i++){
        creature* an=new grass(rand()%700,rand()%700,this);
        c.push_back(an);
    }
    else{
        int cnt=10;
        for(int i=0;i<c.size();i++){
            if(cnt--&&c[i]->type==0 && c[i]->life==0){
                c[i]->label->show();
                c[i]->life=1;
            }
        }
    }
    int numb[5]={0,0,0,0,0};
    for(int i=0;i<c.size();i++){
        if(c[i]->life==1)numb[c[i]->type]++;
    }
    rounds++;
    for(int i=0;i<5;i++)series[i]->append(rounds,qreal(numb[i]));
}
void MainWindow::on_movebutton_clicked()
{
    timer->start(1000);
    timer3->start(1000);
    timer2->start(10);

}


void MainWindow::on_pushButton_3_clicked()
{
    s->show();
}


void MainWindow::on_test_clicked()
{

    timer->stop();
    timer2->stop();
    timer3->stop();

}


void MainWindow::on_start_clicked()
{
    new_start();
}


