#include "ResourceLoader.h"
#include <QDebug>

ResourceLoader::ResourceLoader(QObject *parent) : QThread(parent)
{
}

void ResourceLoader::run()
{
    // 模拟加载资源的过程，例如加载图片、数据等
    qDebug() << "ResourceLoader is running in a separate thread...";

    // 假设这里有一些耗时的操作
    for (int i = 0; i < 5; ++i) {
        QThread::sleep(1); // 休眠1秒来模拟加载时间
        qDebug() << "Preparing resource " << i + 1;
    }

    // 加载或准备完成后发出信号
    emit resourcesPrepared();
}
