#include "creature.h"
#include<network.h>
#include"fun.cpp"
creature::creature(int x,int y,QWidget *parent)
    : QWidget{parent}
{
    life=1;
    age=0;
    hp=7;
    labelx=x;
    labely=y; //初始坐标
}
int value(creature* i, creature* j){
    return (i->type)-(j->type);
}
double * get_status(creature* t,std::vector<creature*>::iterator st,std::vector<creature*>::iterator ed, int k){
    double *p=new double[6]{0,0,0,0,0,0};
    for(auto i=st;i!=ed;i++){
        if(*i==t)continue;
        double dx=((*i)->labelx-t->labelx);
        double dy=((*i)->labely-t->labely);
        double dis=sqrt(dx*dx+dy*dy);
        //    if(dis > t->eyesight) continue;
        double dvx=0;
        double dvy=0;
        p[0]+=dx/Pow(dis,k+1)*value(t,*i);
        p[1]+=dy/Pow(dis,k+1)*value(t,*i);
        p[2]+=(dx*dvx+dy*dvy)*dx/Pow(dis,k+2)*value(t,*i);
        p[3]+=(dx*dvx+dy*dvy)*dy/Pow(dis,k+2)*value(t,*i);
        p[4]+=(dx*dvy-dy*dvx)*dx/Pow(dis,k+2)*value(t,*i);
        p[5]+=(dx*dvy-dy*dvx)*dy/Pow(dis,k+2)*value(t,*i);
    }
    return p;
}
void creature::set_speed(std::vector<creature*>::iterator st,std::vector<creature*>::iterator en){
    //double theta=rand01()*3.1416*2;
    std::pair<double,double> tmp=dec->strategy((get_status( this,st,en,3)),V);
    vx=tmp.first;
    vy=tmp.second;
}
creature::creature(const creature &a,QWidget *parent)
{
    life=1;
    V=a.V;
    double theta=rand01()*3.1416*2;
    vx=V*cos(theta);
    vy=V*sin(theta);
    breedrate=a.breedrate;
    type=a.type;
    labelx=a.labelx+2;
    labely=a.labely+2;
    orgx=a.orgx;
    orgy=a.orgy;
    age=0;
    hp=5;
    dec=new decision(0.03);
    //nn=new network(50);
    //nn->add_layer(4, 6, 8, 15, 10, 7, 3, 1, -1);
    dec=new decision(0.03);
    label = new QLabel(parent);
    label->setGeometry(QRect(labelx, labely, labelx+50, labely+25)); //初始位置
    label->resize(orgx,orgy);
    if(type==1)movie =new QMovie("://image/fish.png");
    if(type==3)movie =new QMovie("://image/shark.png");
    if(type==4)movie =new QMovie("://image/whale.png");
    if(type==2)movie =new QMovie("://image/crab.png");
    if(type==5)movie =new QMovie("://image/inkfish.png");
    label->setScaledContents(true);
    label->setMovie(movie);
    label->move(labelx,labely);
    label->show();
    movie->start();    
}
void creature::foraging(){
    for(int i=-3;i<=3;i++){
        for(int j=-3;j<=3;j++){
            if(labelx+i<1||labely+j<1)continue;

        }
    }
}
fish::fish(int x,int y,QWidget *parent)
    : creature(x,y,parent)
{
    V=rand01()*20+10;
    double theta=rand01()*3.1416*2;
    vx=V*cos(theta);
    vy=V*sin(theta);
    type=1;
    breedrate=5;
    //nn=new network(50);
    //nn->add_layer(4, 6, 8, 15, 10, 7, 3, 1, -1);
    dec=new decision(0.03);
    label = new QLabel(parent);
    label->setGeometry(QRect(x, y, x+50, y+25)); //初始位置
    label->resize(30,25);
    orgx=30;
    orgy=25;

    QPixmap pixmap("://image/fish.png"); // 替换为你的图片路径
    label->setPixmap(pixmap);
    label->setScaledContents(true);
    label->show();
}

crab::crab(int x,int y,QWidget *parent)
    : creature(x,y,parent)
{
    V=rand01()*20+10;
    double theta=rand01()*3.1416*2;
    vx=V*cos(theta);
    vy=V*sin(theta);
    type=2;
    breedrate=6;
    //nn=new network(50);
    //nn->add_layer(4, 6, 8, 15, 10, 7, 3, 1, -1);
    dec=new decision(0.03);
    label = new QLabel(parent);
    label->setGeometry(QRect(x, y, x+50, y+25)); //初始位置
    label->resize(30,25);
    orgx=30;
    orgy=25;
    QPixmap pixmap("://image/crab.png"); // 替换为你的图片路径
    label->setPixmap(pixmap);
    label->setScaledContents(true);
    label->show();
}

shrimp::shrimp(int x,int y,QWidget *parent)
    : creature(x,y,parent)
{
    V=rand01()*20+10;
    double theta=rand01()*3.1416*2;
    vx=V*cos(theta);
    vy=V*sin(theta);
    type=4;
    breedrate=8;
    //nn=new network(50);
    //nn->add_layer(4, 6, 8, 15, 10, 7, 3, 1, -1);
    dec=new decision(0.03);
    label = new QLabel(parent);
    label->setGeometry(QRect(x, y, x+50, y+25)); //初始位置
    label->resize(30,25);
    orgx=30;
    orgy=25;
    QPixmap pixmap("://image/shrimp.png"); // 替换为你的图片路径
    label->setPixmap(pixmap);
    label->setScaledContents(true);
    label->show();
}

inkfish::inkfish(int x,int y,QWidget *parent)
    : creature(x,y,parent)
{
    V=rand01()*20+10;
    double theta=rand01()*3.1416*2;
    vx=V*cos(theta);
    vy=V*sin(theta);
    type=5;
    breedrate=8;
    //nn=new network(50);
    //nn->add_layer(4, 6, 8, 15, 10, 7, 3, 1, -1);
    dec=new decision(0.03);
    label = new QLabel(parent);
    label->setGeometry(QRect(x, y, x+50, y+25)); //初始位置
    label->resize(30,25);
    orgx=30;
    orgy=25;
    QPixmap pixmap("://image/inkfish.png"); // 替换为你的图片路径
    label->setPixmap(pixmap);
    label->setScaledContents(true);
    label->show();
}


shark::shark(int x,int y,QWidget *parent)
    : creature(x,y,parent)
{
    V=rand01()*20+25;
    double theta=rand01()*3.1416*2;
    vx=V*cos(theta);
    vy=V*sin(theta);
    breedrate=10;
    type=3;
    dec=new decision(0.03);
    //nn=new network(50);
    label = new QLabel(parent);
    label->setGeometry(QRect(x, y, x+40, y+40)); //初始位置
    label->resize(40,40);
    orgx=40;
    orgy=40;
    QPixmap pixmap("://image/shark.png"); // 替换为你的图片路径
    label->setPixmap(pixmap);
    label->setScaledContents(true);
    label->show();
}

whale::whale(int x,int y,QWidget *parent)
    : creature(x,y,parent)
{
    V=rand01()*10+10;
    double theta=rand01()*3.1416*2;
    vx=V*cos(theta);
    vy=V*sin(theta);
    breedrate=11;
    type=4;
    dec=new decision(0.03);
    label = new QLabel(parent);
    label->setGeometry(QRect(x, y, x+60, y+60)); //初始位置
    label->resize(60,60);
    orgx=60;
    orgy=60;

    QPixmap pixmap("://image/whale.gif"); // 替换为你的图片路径
    label->setPixmap(pixmap);
    label->setScaledContents(true);
    label->show();
}
grass::grass(int x,int y,QWidget *parent)
    : creature(x,y,parent)
{
    type=0;
    breedrate=7;
    label = new QLabel(parent);
    label->setGeometry(QRect(x, y, x+40, y+40)); //初始位置
    label->resize(20,20);
    QPixmap pixmap("://image/grass.png"); // 替换为你的图片路径
    label->setPixmap(pixmap);
    label->setScaledContents(true);
    label->show();
}
