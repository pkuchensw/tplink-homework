#ifndef SETTING_H
#define SETTING_H

#include <QDialog>

namespace Ui {
class setting;
}

class setting : public QDialog
{
    Q_OBJECT

public:
    int initial[20];
    double birth[20];
    explicit setting(QWidget *parent = nullptr);
    ~setting();

private slots:
    void on_initial_num_valueChanged(int arg1);


    void on_initial_num_2_valueChanged(int arg1);

    void on_initial_num_3_valueChanged(int arg1);

    void on_initial_num_7_valueChanged(int arg1);

    void on_initial_num_8_valueChanged(int arg1);

    void on_buttonBox_accepted();

    void on_doubleSpinBox_2_valueChanged(double arg1);

    void on_doubleSpinBox_4_valueChanged(double arg1);

    void on_doubleSpinBox_5_valueChanged(double arg1);

    void on_doubleSpinBox_3_valueChanged(double arg1);

    void on_doubleSpinBox_valueChanged(double arg1);

private:
    Ui::setting *ui;
};

#endif // SETTING_H
