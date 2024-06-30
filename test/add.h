#ifndef ADD_H
#define ADD_H

#include <QDialog>

namespace Ui {
class add;
}

class add : public QDialog
{
    Q_OBJECT

public:
    int num,type,flag;
    explicit add(QWidget *parent = nullptr);
    ~add();

private slots:
    void on_buttonBox_accepted();

    void on_comboBox_currentTextChanged(const QString &arg1);

    void on_comboBox_currentIndexChanged(int index);

    void on_buttonBox_rejected();

    void on_spinBox_valueChanged(int arg1);

private:
    Ui::add *ui;
};

#endif // ADD_H
