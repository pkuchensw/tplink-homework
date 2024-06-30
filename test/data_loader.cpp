#ifndef DATA_lOADER_H
#define DATA_lOADER_H
#include<iostream>
#include "fun.cpp"
//#include "network.cpp"
class data_loader {
	friend class network;
public:
	data_loader(int n = 10000, int x = 4, int y = 1) :amount(n), x_size(x), y_size(y) {
		data_x = new double* [n];
		data_y = new double* [n];
		for (int i = 0; i < n; i++) {
			data_x[i] = new double[x_size];
			data_y[i] = new double[y_size];
		}
		ptr = full = 0;
	}
	data_loader(data_loader& other) {
		for (int i = 0; i < amount; i++) {
			delete[]data_x[i];
			delete[]data_y[i];
		}
		delete[]data_x;
		delete[]data_y;
		amount = other.amount;
		x_size = other.x_size;
		y_size = other.y_size;
		data_x = new double* [amount];
		data_y = new double* [amount];
		for (int i = 0; i < amount; i++) {
			data_x[i] = new double[x_size];
			data_y[i] = new double[y_size];
		}
		for (int i = 0; i < amount; i++) {
			for (int j = 0; j < x_size; j++) {
				data_x[i][j] = other.data_x[i][j];
			}
		}
		for (int i = 0; i < amount; i++) {
			for (int j = 0; j < y_size; j++) {
				data_y[i][j] = other.data_y[i][j];
			}
		}
		ptr = other.ptr, full = other.full;
	}
	~data_loader() {
		for (int i = 0; i < amount; i++) {
			delete[]data_x[i];
			delete[]data_y[i];
		}
		delete[]data_x;
		delete[]data_y;
	}
	void insert(double* p, double* q) {
		for (int i = 0; i < x_size; i++) {
			data_x[ptr][i] = p[i];
		}
		for (int i = 0; i < y_size; i++) {
			data_y[ptr][i] = q[i];
		}
		ptr++;
		if (ptr == amount) {
			ptr = 0;
			full = 1;
		}
	}
	void print(int n = 999999) {
		int m = std::min(n, range());
		for (int i = 0; i < m; i++) {
			for (int k = 0; k < x_size; k++) {
				std::cerr << data_x[i][k] << " ";
			}
			std::cerr << " | ";
			for (int k = 0; k < y_size; k++) {
				std::cerr << data_y[i][k] << " ==";
			}
			std::cerr << data_x[i][0] * data_x[i][2] + data_x[i][1] * data_x[i][3];
			std::cerr << std::endl;
		}
	}
	int range() {
		if (full == 1) return amount;
		return ptr;
	}
    void clear(){
        ptr=full=0;
    }
	int random_rotation(int n = 9999999) { //(x,y,vx,vy)->(ans)
		if (ptr == 0 && full == 0) return -1;
		if (x_size % 2 != 0 || y_size != 1) return -1;
		if (full == 1) return 0;
		int s = 0;
		while (full == 0 && (n--)) {
			s++;
			int i = rand() % ptr;
			double* p = new double[x_size];
			double* q = new double[1];
			double theta = 3.1415927 * 2 * rand01();
			for (int k = 0; k < x_size - 1; k += 2) {
				p[k] = data_x[i][k] * cos(theta) - data_x[i][k+ 1] * sin(theta);
				p[k+1] = data_x[i][k] * sin(theta) + data_x[i][k+1] * cos(theta);
			}
			q[0] = data_y[i][0];
			insert(p, q);
			delete[]p;
			delete[]q;
		}
		return s;
	}
	int random_resize(int n = 9999999, double l = 0.5, double r = 2) {     //(x,y)->(kx,y)
		if (ptr == 0 && full == 0) return -1;
		if (full == 1) return 0;
		int s = 0;
		while (full == 0 && (n--)) {
			s++;
			int i = rand() % ptr;
			double* p = new double[x_size];
			double* q = new double[y_size];
			double rate = rand01() * (r - l) + l;
			for (int k = 0; k < x_size; k++) {
				p[k] = data_x[i][k] * rate;
			}
			for (int k = 0; k < y_size; k++) {
				q[k] = data_y[i][k];
			}
			insert(p, q);
			delete[]p;
			delete[]q;
		}
		return s;
	}
private:
	double** data_x;
	double** data_y;
	int amount;
	int x_size;
	int y_size;
	int ptr;
	bool full;
};
#endif
