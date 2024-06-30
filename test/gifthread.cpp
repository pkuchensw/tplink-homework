#include "gifThread.h"

gifThread::gifThread(const QString gifpath,int length,int width)
{
    gifPath = gifpath;
    label = new QLabel;
    len=length;
    wid=width;
}

void gifThread::run()
{
    gif = new QMovie(gifPath);
    label->setMovie(gif);
    gif->setScaledSize(QSize(len,wid));
    gif->setSpeed(180);
    gif->start();
    while(1)
    {
        qApp->processEvents();
    }
}

