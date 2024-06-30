#ifndef READ_H
#define READ_H

#include <QMainWindow>
#include "gifThread.h"
#include<Qpainter>

namespace Ui {
class readme;
}

class readme : public QMainWindow
{
    Q_OBJECT

public:
    explicit readme(QWidget *parent = nullptr);
    ~readme();
    gifThread *t1,*t2;
protected:
    void paintEvent(QPaintEvent *event) override {
        QPainter painter(this);
        QPixmap pixmap(":/image/ocean_2.gif"); // 替换为你的图片路径
        pixmap = pixmap.scaled(this->size(), Qt::KeepAspectRatio);
        painter.drawPixmap(0, 0, this->width(), this->height(), pixmap);
    }
private slots:

private:
    Ui::readme *ui;
};

#endif // READ_H
