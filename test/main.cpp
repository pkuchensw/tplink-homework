#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QObject>
#include <random>
#include <QButtonGroup>
#include <QDialog>
#include <QThread>
#include <QPropertyAnimation>
#include <QTimer>
#include <QVBoxLayout>
#include<QMessageBox>
#include <QMovie>
#include"mainwindow.h"
#include"home.h"
#include"mymove.h"




int main(int argc, char *argv[]) {

    srand(time(0));
    /*decision dec(0.03);
    for (int i = 0; i < 30000; i++) {
        double a = rand01() * 2 - 1, b = rand01() * 2 - 1;
        double c = rand01() * 2 - 1, d = rand01() * 2 - 1;
        double ans = product(a, b, c, d);
        for (int k = 0; k < 10; k++) {
            double theta = rand01() * 3;
            rotate(a, b, theta);
            rotate(c, d, theta);
            double* p = new double[6] {a, b, 0, 0, 0, 0};
            dec.memorize_status(p, std::make_pair(c, d));
            delete[]p;
        }
        //system("pause");
        double* q = new double[1] {ans};
        dec.get_points(ans);
        if (i % 10 == 0) {
            qDebug()<<dec.train(10);
        }
        delete[]q;
    }
    for (int i = 0; i < 1000; i++) {
        double a = rand01() * 2 - 1, b = rand01() * 2 - 1;
        double c = rand01() * 2 - 1, d = rand01() * 2 - 1;
        double* p = new double[6] {a, b, 0, 0, 0, 0};
        //cout << a<<" " << b << endl;
        std::pair<double, double> ans = dec.strategy(p, 1);
        qDebug() << ans.first << " " << ans.second ;
        qDebug() << product(a, b, ans.first, ans.second);
        delete[]p;
        //system("pause");
    }
*/
    QApplication app(argc, argv);
   // return app.exec();
    home Home;
    Home.show();
    //Home.showFullScreen();
    return app.exec();
}
