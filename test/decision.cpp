#ifndef DECISION_H
#define DECISION_H
#include "fun.cpp"
#include "network.cpp"
#include "data_loader.cpp"
#include "data_cache.cpp"
#include<qdebug.h>
class decision {
private:
	network* nn;
	data_loader* dataset;
	data_cache* cache;
	double learning_rate;
public:
    int check;
    void reset(){
        nn->reset();
        cache->clear();
        //dataset->clear();
    }
	decision(double lr):learning_rate(lr) {
        check=-1;
		nn = new network(50);
        nn->add_layer(8, 12,15,12, 10, 5, 1, -1);
		nn->set_lr(lr);
        dataset = new data_loader(10000, 8, 1);
        cache = new data_cache(20, 8, 1, 1);
        check=100000;
       // qDebug()<<cache->test;
	}
    decision(decision &x){
        check=2;
    }
	~decision() {
        //delete[]dataset;
        //delete[]cache;
        //delete[]nn;
	}
	void memorize_status(double* status, std::pair<double,double> act) {
		double* p = new double[8];
		for (int i = 0; i < 6; i++) p[i] = status[i];
		p[6] = act.first, p[7] = act.second;
		cache->save(p);
		delete[]p;
	}
	void get_points(double value) {
      //  qDebug()<<"hello";
        double* p = new double[1]{ value };

		cache->add(p, dataset);

        dataset->random_rotation(50);
        delete[]p;
	}
	double train(int num) {
		//std::cout <<"training" << std::endl;
        nn->train_random(dataset, num, 10);
		return nn->Loss();
	}
	std::pair<double, double> strategy(double* status, double velocity) {
		double theta = rand01() * 3.1415927 * 2,  ans = 0;
		double* p = new double[8];
		for (int i = 0; i < 6; i++) p[i] = status[i];
		for (int i = 0; i < 100; i++) {
			double tmp = rand01() * 3.1415927 * 2;
			p[6] = velocity * cos(tmp);
			p[7] = velocity * sin(tmp);
			nn->cal(p);
			if (nn->get_first_ans() > ans) {
				theta = tmp, ans = nn->get_first_ans();
			}
		}
		return std::make_pair(velocity * cos(theta), velocity * sin(theta));
	}
	
};
#endif
