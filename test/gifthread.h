#ifndef GIFTHREAD_H
#define GIFTHREAD_H

#include <QObject>
#include <QThread>
#include <QMovie>
#include <QLabel>
#include <QDebug>

class gifThread:public QThread
{
    Q_OBJECT

public:
    gifThread(const QString gifpath,int length,int width);
    QString gifPath;
    QLabel *label;
    QMovie *gif;
    int len;
    int wid;
    void run();
};

#endif // GIFTHREAD_H

