#include "group.h"
#include "ui_group.h"
#include<iostream>
#include<cmath>
#include<vector>
#include<cstdarg>
#include<Windows.h>
#include<cmath>
#include<vector>
#include<QChart>
#include<qvalueaxis.h>
#include<QPainter>
#include<QValueAxis>
#include<cmath>
#include<add.h>
double TIME;
inline double rand01() {
    return ((double)(rand() % 20000)) / 20000.0;
}
double rate[10][10];
class gcreature {
public:
    double num;
    double birth_rate, death_rate;
    double energy;
    double total;
    int type;
    int is_producer;
    void predate();
    void born();
    void die();
    std::string name;
};
std::vector<gcreature*> species;
int total_num =0;
void gcreature::predate() {
    if (is_producer == 1) {
        total += cos(TIME / 10) * 100000 + 180000;
        return;
    }
    for (int i = 0; i < total_num; i++) {
        double r = rate[this->type][species[i]->type];
        double tmp = species[i]->total * r * rand01();
        this->total += tmp * 0.015;
        species[i]->total -= tmp * 0.1;

    }
}
void gcreature::born() {
    num += birth_rate * num;
    num = (num + total / energy) / 2;
}
void gcreature::die() {
    double r = death_rate * rand01();
    num -= (double)num * r;
    total -= total * r;
}
void adds(std::string name, double br, double dr, double e, int n, int isproducer = 0) {
    species.push_back(new gcreature);
    species[total_num]->name = name;
    species[total_num]->is_producer = isproducer;
    species[total_num]->birth_rate = br;
    species[total_num]->death_rate = dr;
    species[total_num]->energy = e;
    species[total_num]->num = n;
    species[total_num]->total = species[total_num]->num * species[total_num]->energy;
    species[total_num]->type = total_num;
    total_num++;

}
void born_all() {
    for (int i = 0; i < total_num; i++) {
        species[i]->born();
    }
}
void die_all() {
    for (int i = 0; i < total_num; i++) {
        species[i]->die();
    }
}
void predate_all() {
    for (int i = 0; i < total_num; i++) {
        species[i]->predate();
    }
}
group::group(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::group)
{
    ui->setupUi(this);
    s= new setting();
    a= new add();

    QChart *chart = new QChart();
    for(int i=0;i<5;i++){
        series[i] = new QLineSeries();
        chart->addSeries(series[i]);
        series[i]->setPointsVisible(false);
    }
    series[0]->setName("grass");
    series[1]->setName("fish");
    series[2]->setName("crab");
    series[3]->setName("shark");
    series[4]->setName("whale");

    adds("grass", 0.5, 0.1, 10, 10000, 1);
    adds("fish", 0.2, 0.5, 50, 100);
    adds("shark", 0.08, 0.5, 10, 20);
    adds("crab",0.1,0.5,50,100);
    adds("whale",0.06,0.2,10,20);

    rate[1][0] = 0.2;
    rate[2][1] = 0.3;
    rate[3][2] = 0.3;
    rate[4][2] = 0.1;
    rate[4][3] = 0.1;
    rate[4][1] = 0.1;
    rate[3][0] = 0.2;
    chart->setTitle("number graph");
    // 将Chart添加到ChartView
    ui->graphicsView->setChart(chart);
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);

    // 设置图表主题色
    ui->graphicsView->chart()->setTheme(QChart::ChartTheme(0));



    // 创建坐标轴
    QValueAxis *axisX = new QValueAxis;    // X轴
    axisX->setRange(1, 2000);               // 设置坐标轴范围
    axisX->setTitleText("evolution time");         // 标题


    QValueAxis *axisY = new QValueAxis;    // Y轴
    axisY->setRange(0, 14);               // Y轴范围(-0 - 20)
    axisY->setTitleText("creature number");         // 标题

    for(int i=0;i<5;i++){
        chart->setAxisX(axisX, series[i]);   // 为序列设置坐标轴
        chart->setAxisY(axisY, series[i]);
    }
}

group::~group()
{
    delete ui;
}
int rounds=1;
int flag=0;
void group::on_pushButton_clicked()
{
    flag=1;
    int t0 = clock();
    for (TIME = 0;TIME<=50; TIME += 1) {

        //while (clock() - t0 < CLOCKS_PER_SEC / 4);
        t0 = clock();
        predate_all();
        born_all();
        die_all();
        for (int i = 0; i < total_num; i++) {
            //std::cout<<total_num<<std::endl;
            //std::cout << species[i]->name << " " << species[i]->num << " " << species[i]->total << std::endl;
            rounds++;
            for(int j=0;j<5;j++)series[j]->append(rounds,qreal(log(species[j]->num)));
        }
    }
}


void group::on_pushButton_2_clicked()
{
    this->close();
}


void group::on_pushButton_3_clicked()
{
    s->show();
}


void group::on_pushButton_4_clicked()
{
    if(a->flag==1){
        species[a->type]+=a->num;
        a->flag=0;
    }
    for(int j=0;j<5;j++)series[j]->clear();
    rounds=0;
    species.clear();
    total_num=0;
    adds("grass", 0.5, s->birth[4], 10, 10000, 1);
    adds("fish", 0.2, s->birth[0], 50, 100);
    adds("shark", 0.08, s->birth[1], 10, 20);
    adds("crab", 0.2, s->birth[2], 50, 100);
    adds("whale", 0.05, s->birth[3], 10, 20);

}


void group::on_pushButton_5_clicked()
{
    a->show();
}

