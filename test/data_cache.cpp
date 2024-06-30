#ifndef DATA_CACHE_H
#define DATA_CACHE_H
#include "data_loader.cpp"
#include<qdebug.h>
class data_cache {
private:
	double** data_x;
	double** data_y;
	int amount;
	int x_size;
	int y_size;
	int ptr;
	bool full;
	double forget_rate;
public:
    int test;
	void set_rate(double r) {
		forget_rate = r;
	}
	data_cache(int n = 50, int x = 4, int y = 1, double r = 1) :amount(n), x_size(x), y_size(y), forget_rate(r) {
		data_x = new double* [n];
		data_y = new double* [n];
        test=1;
		for (int i = 0; i < n; i++) {
			data_x[i] = new double[x_size];
			data_y[i] = new double[y_size];
		}
		ptr = full = 0;
	}
	bool isfull() {
		return full;
	}
	int range() {
		return full ? amount : ptr;
	}
	void forget() {
		int tmp = range();
		for (int i = 0; i < tmp; i++) {
			for (int j = 0; j < y_size; j++) {
				data_y[i][j] *= forget_rate;
			}
		}
	}
	void save(double* p) {
		forget();
		for (int i = 0; i < x_size; i++) {
			data_x[ptr][i] = p[i];
		}
		for (int i = 0; i < y_size; i++) {
			data_y[ptr][i] = 1;
		}
		ptr++;
		if (ptr == amount) {
			ptr = 0;
			full = 1;
		}
	} 
	void clear() {
		ptr = full = 0;
	}
	void add(double* value, data_loader* data) {
		int tmp = range();
		for (int i = 0; i < tmp; i++) {
            for(int k=0;k<x_size;k++){
            }
			for (int k = 0; k < y_size; k++) {
				data_y[i][k] *= value[k];
            }
			data->insert(data_x[i], data_y[i]);
		}
		clear();
	}
};
#endif
