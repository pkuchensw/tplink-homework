#ifndef MYMOVE_H
#define MYMOVE_H
#include <QObject>
#include<creature.h>
#include<vector>
class mymove : public QObject
{
    Q_OBJECT
public:
    explicit mymove(creature* movec_ ,std::vector<creature*>::iterator st_,std::vector<creature*>::iterator ed_,QObject *parent = nullptr);
public:
    creature* movec;
    std::vector<creature*>::iterator st,ed;
public slots:
    void moves();
    void continuemoves();
    void move();
    void forage();
signals:
};

#endif // MYMOVE_H
