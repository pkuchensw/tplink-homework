#ifndef GROUP_H
#define GROUP_H

#include <QDialog>
#include<QLineSeries>
#include<setting.h>
#include<add.h>

namespace Ui {
class group;
}

class group : public QDialog
{
    Q_OBJECT

public:
    setting *s;
    add *a;
    QLineSeries *series[10];
    explicit group(QWidget *parent = nullptr);
    ~group();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

private:
    Ui::group *ui;
};

#endif // GROUP_H
