#ifndef CREATURE_H
#define CREATURE_H
#include<random>
#include<QObject>
#include<QMovie>
#include<QLabel>
#include<qdebug.h>
#include<network.h>
#include<decision.cpp>
class creature : public QWidget
{
    Q_OBJECT
public:
    explicit creature(int x,int y,QWidget *parent = nullptr);

signals:
public:
    decision *dec;
    int type,life;
    int age,orgx,orgy,hp;
    double labelx,labely;
    int breedrate;
    int distance,eyesight;
    double V;
    double vx,vy;
    QLabel *label;
    QMovie *movie;


public:
    void foraging();
    creature(const creature& a,QWidget *parent=nullptr);
    void set_speed(std::vector<creature*>::iterator st,std::vector<creature*>::iterator en);
    //virtual predation()=0;
    //virtual reproduction()=0;

};

class fish:public creature{
public:
    explicit fish(int x,int y,QWidget *parent = nullptr);
};
class crab:public creature{
public:
    explicit crab(int x,int y,QWidget *parent = nullptr);
};
class shrimp:public creature{
public:
    explicit shrimp(int x,int y,QWidget *parent = nullptr);
};
class inkfish:public creature{
public:
    explicit inkfish(int x,int y,QWidget *parent = nullptr);
};
class shark:public creature{
public:
    explicit shark(int x,int y,QWidget *parent = nullptr);
};
class grass:public creature{
public:
   explicit grass(int x,int y,QWidget *parent = nullptr);
};

class whale:public creature{
public:
    explicit whale(int x,int y,QWidget *parent = nullptr);
};

#endif // CREATURE_H
