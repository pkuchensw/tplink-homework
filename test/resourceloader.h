#ifndef RESOURCELOADER_H
#define RESOURCELOADER_H

#include <QThread>
#include <QObject>

class ResourceLoader : public QThread
{
    Q_OBJECT

public:
    explicit ResourceLoader(QObject *parent = nullptr);

signals:
    void resourcesPrepared();

protected:
    void run() override;
};

#endif // RESOURCELOADER_H
