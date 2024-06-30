#include "move.h"
#include<QPropertyAnimation>
#include<QTimer>
#include<QWidget>
#include<QPoint>
void mymove::moves(){
    QPropertyAnimation *m_animation=new(QPropertyAnimation);
    m_animation->setTargetObject(label);    //设置使用动画的控件
    m_animation->setEasingCurve(QEasingCurve::Linear); //设置动画效果
    m_animation->setPropertyName("pos");    //指定动画属性名
    m_animation->setDuration(1000);    //设置动画时间（单位：毫秒）
    m_animation->setStartValue(label->pos());  //设置动画起始位置在label控件当前的pos
    m_animation->setEndValue(label->pos() + QPoint(rand()%100, rand()%100)); //设置动画结束位置
    m_animation->start();
    return;
}
void mymove::continuemoves(){
    int n=10;
    while(n--){
        qDebug()<<n;
        QTimer::singleShot(1000,this, SLOT(moves()));
        //this->moves();
        //QThread::sleep(1);
    }
}
void mymove::move(){
    this->continuemoves();
}
