#ifndef NETWORK_H
#define NETWORK_H
#include <iostream>
#include <vector>
#include <cstdarg>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include "data_loader.cpp"
#include "fun.cpp"
class neuro;
struct edge {
private:
	friend class neuro;
	friend class network;
	neuro* to;
	double w;
	double dif;

	edge(neuro* p) {
		to = p;
		w = (rand01() - rand01());
		dif = 0;
	}
	edge() {
		to = NULL;
		w = (rand01() - rand01());
		dif = 0;
	}
};
class neuro {
public:
	friend class network;
	edge* adj;
	double value;
	double dif;
	int layer;
	int type;
	int num;
	neuro() {
		adj = new edge;
		value = 0;
	}
	void init(int Layer, int Type, int N, neuro* start) {
		layer = Layer;
		type = Type;
		num = N;
		value = dif = 0;
		if (Type == 1) {
			num = 0;
			//	adj = new edge;
		}
		adj = new edge[num];
		for (int i = 0; i < num; i++) {
			adj[i] = edge(start);
			start++;
		}
	}
	~neuro() {
		delete[] adj;
	}
	inline void forward() {
		if (type == 1) {
			value = 1;
			return;
		}
		value = 0;
		for (int i = 0; i < num; i++) {
			value += adj[i].to->value * adj[i].w;
		}
		value = l_relu(value);
	}
	inline void backward() {
		//	cout << layer << " " << dif << endl;
		dif = dif * l_relu_d(value);
		for (register int i = 0; i < num; ++i) {
			//	cout << i << ".." << endl;
			neuro* tmp = (adj[i].to);
			//		cout << tmp->layer << ";" ;
			tmp->dif += adj[i].w * dif;
			adj[i].dif = tmp->value * dif;
		}
		//	cout << endl;
	}
	inline void change(double rate) {
		dif = 0;
		for (register int i = 0; i < num; ++i) {
			adj[i].w -= adj[i].dif * rate;
			adj[i].dif = 0;
		}
	}
	inline void reset() {
		for (register int i = 0; i < num; ++i) {
			adj[i].w = rand01() - rand01();
			adj[i].dif = 0;
		}
	}
	void print_weight() {
		for (register int i = 0; i < num; ++i) {
			std::cout << adj[i].w << " ";
		}
		std::cout << std::endl;
	}
	void print_dif() {
		std::cout << dif << ":" << std::endl;
		for (register int i = 0; i < num; ++i) {
			std::cout << adj[i].dif << " ";
		}
        std::cout << std::endl;
	}
};
class network {
public:
	network(int n = 50) :num(n) {
        N = new neuro[n * 2];
		lr = 0.03;
		layer_num = 0;
		num = 0;
		loss = 0;
		first = N;
		closed = 0;
	}
	void add_layer(int n) {
		if (n <= 0) return;
		int tmp = 0;
		if (layer_num > 0) tmp = layer_size.back();
		layer_size.push_back(n + 1);
		layer_num++;
		for (int i = 0; i < n; i++) {
			N[num++].init(layer_num, 0, tmp, first);
		}
		N[num++].init(layer_num, 1, 0, first);
		first = &N[num - n - 1];
	}
	double learning_rate() {
		return lr;
	}
	void print_weight() {
		for (int i = 0; i < num; i++) {
			N[i].print_weight();
		}
	}
	void print_dif() {
		for (int i = 0; i < num; i++) {
			N[i].print_dif();
		}
	}
	void add_layer(int a1, int a2, ...) {
		va_list a;
		va_start(a, a2);
		add_layer(a1);
		add_layer(a2);
		for (int i = 1; ; i++) {
			int t = va_arg(a, int);
			if (t <= 0) break;
			add_layer(t);
		}
		va_end(a);
	}
	~network() {
		delete[]N;
	}
	void cal(double* v) {
		int first_layer_num = layer_size.front() - 1;
		for (int i = 0; i < first_layer_num; i++) {
			if (N[i].type == 1) {
				continue;
			}
			N[i].value = v[i];
		}
		N[first_layer_num].value = 1;

		for (int i = first_layer_num + 1; i < num; i++) {
			N[i].forward();
		}
	}
	void back(double* v) {
		loss = 0;
		int last_layer_num = layer_size.back();
		int j = 0;
		for (int i = num - last_layer_num; i < num; i++) {
			if (N[i].type == 1) continue;
			N[i].dif = (N[i].value - v[j]);
			loss += (N[i].value - v[j]) * (N[i].value - v[j]);
			j++;
			//	cout << i << ",";
		}
		//	cout << endl;
		for (int i = num - 1; i >= 0; i--) {
			if (N[i].layer == 1) break;
			if (N[i].type == 1) continue;
			N[i].backward();
		}
		for (int i = 0; i < num; i++) {
			N[i].dif = 0;
		}
	}
	void cal_loss(double* v) {
		loss = 0;
		int last_layer_num = layer_size.back();
		int j = 0;
		for (int i = num - last_layer_num; i < num; i++) {
			if (N[i].type == 1) continue;
			loss += (N[i].value - v[j]) * (N[i].value - v[j]);
			//	cout << i << ",";
		}
	}
	void adjust(double Lr) {
		if (closed) return;
		for (int i = 0; i < num; i++) {
			if (N[i].type == 1) continue;
			N[i].change(Lr);
		}
	}
	void adjust() {
		if (closed) return;
		for (int i = 0; i < num; i++) {
			if (N[i].type == 1) continue;
			N[i].change(lr);
		}
	}
	void reset() {
		for (int i = 0; i < num; i++) {
			N[i].reset();
		}
	}
	void anneal(double r) {
		lr -= lr * r;
	}
	void train(double* v1, double* v2) {
		if (closed) return;
		cal(v1);
		back(v2);
		adjust();
		if (loss > 10000) reset();
	}
	void train(data_loader* data, int batch_size = 1, int epoch = 1) {
		if (closed) return;
		while (epoch--) {
			int sz = data->range();
			for (int i = 0; i < sz; i++) {
				//	cout << i << endl;
				cal(data->data_x[i]);
				back(data->data_y[i]);
				if (i % batch_size == 0) {
					adjust(lr / batch_size);
				}
				if (loss > 10000) reset();
			}
		}
	}
	void train_random(data_loader* data, int n, int batch_size=1) {
		int sz = data->range();
		if (sz == 0) return;
		int k = 0;
		while (n--) {
			int i = rand() % sz;
			cal(data->data_x[i]);
			back(data->data_y[i]);
			k++;
			if (k % batch_size == 0) {
				adjust(lr);
				if (loss > 10000) reset();
			}
		}
	}
	double test(data_loader* data) {
		int sz = data->range();
		double tot_loss = 0;
		for (int i = 0; i < sz; i++) {
			//	cout << i << endl;
			cal(data->data_x[i]);
			cal_loss(data->data_y[i]);
			tot_loss += loss;
		}
		return tot_loss / sz;
	}
	void set_lr(double r) {
		lr = r;
	}
	double learing_rate() {
		return lr;
	}
	std::vector<double> get_ans() {
		std::vector<double> v;
		int last_layer_num = layer_size.back();
		for (int i = num - last_layer_num; i < num; i++) {
			if (N[i].type == 1) continue;
			v.push_back(N[i].value);
		}
		return v;
	}
	double get_first_ans() {
		int last_layer_num = layer_size.back();
		for (int i = num - last_layer_num; i < num; i++) {
			if (N[i].type == 1) continue;
			return N[i].value;
		}

	}
	double Loss() {
		return loss;
	}
	void close() {
		closed = 1;
	}
	void reopen() {
		closed = 10;
	}
	bool ifclose() {
		return closed;
	}
private:
	neuro* N;
	neuro* first;
	int num;
	int layer_num;
	bool closed;
	std::vector<int> layer_size;
	double loss;
	double lr;

};
#endif
