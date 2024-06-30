#include "mymove.h"
#include<creature.h>
#include"creature.cpp"
mymove::mymove(creature* movec_, std::vector<creature*>::iterator st_, std::vector<creature*>::iterator ed_, QObject *parent)
    : QObject{parent}
{
    movec=movec_;
    st=st_;
    ed=ed_;
}
#include "move.h"
#include<QPropertyAnimation>
#include<QTimer>
#include<QWidget>
#include<QPoint>
#include<mainwindow.h>
#include<mainwindow.cpp>

void mymove::moves(){
    if(movec->life==0)return;
    QPropertyAnimation *m_animation=new(QPropertyAnimation);
    m_animation->setTargetObject(movec->label);
    m_animation->setEasingCurve(QEasingCurve::Linear);
    m_animation->setPropertyName("pos");
    m_animation->setDuration(10);
    m_animation->setStartValue(movec->label->pos());
    //int dx=rand()%70-35,dy=rand()%70-35;
    if(rand01()<0.002){
        movec->set_speed(st,ed);
    }
    double dx=movec->vx*0.1,dy=movec->vy*0.1;
    int nx=movec->labelx+dx;
    int ny=movec->labely+dy;
    m_animation->setEndValue(movec->label->pos() + QPoint(nx-(int)movec->labelx,ny-(int)movec->labely));
    (movec->labelx)+=dx;
    (movec->labely)+=dy;
    if(movec->labelx<=0 && movec->vx<=0){
        movec->vx*=-1;
    }
    if(movec->labely<=0 && movec->vy<=0){
        movec->vy*=-1;
    }
    if(movec->labelx>=800 && movec->vx>=0){
        movec->vx*=-1;
    }
    if(movec->labely>=800 && movec->vy>=0){
        movec->vy*=-1;
    }
    if(rand01()<0.1){
        //movec->dec->memorize_status(get_status(movec,st,ed,3),std::make_pair(movec->vx,movec->vy));
    }
    if(rand01()<0.01){
        //qDebug()<<movec->dec->train(500);
    }
    movec->age++;
    //movec->hp--;
    movec->label->resize(movec->orgx+std::min(10,movec->age/100),movec->orgy+std::min(10,movec->age/100));
    m_animation->start();
    return;
}
void mymove::continuemoves(){

}
void mymove::move(){

}
void mymove::forage(){

}

