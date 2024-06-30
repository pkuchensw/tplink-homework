#include<iostream>
#include<cmath>
#include<graphics.h>
#include<vector>
#include<cstdarg>
#include <Windows.h>
#include <cmath>
#include "MatPlot.h"
using namespace MatPlot;
using std::cin;
using std::cout;
using std::endl;
inline double rand01() {
	return ((double)(rand() % 20000)) / 20000.0;
}
#pragma region dataloader
class data_loader {
	friend class network;
public:
	/*data_loader() {
		amount = x_size = y_size = 0;
		ptr = full = 0;
	}*/
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
		int m = min(n, range());
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
	int random_rotation(int n = 9999999) { //(x,y,vx,vy)->(ans)
		if (ptr == 0 && full == 0) return -1;
		if (x_size != 4 || y_size != 1) return -1;
		if (full == 1) return 0;
		int s = 0;
		while (full == 0 && (n--)) {
			s++;
			int i = rand() % ptr;
			double* p = new double[4];
			double* q = new double[1];
			double theta = 3.1415926 * 2 * rand01();
			p[0] = data_x[i][0] * cos(theta) - data_x[i][1] * sin(theta);
			p[1] = data_x[i][0] * sin(theta) + data_x[i][1] * cos(theta);
			p[2] = data_x[i][2] * cos(theta) - data_x[i][3] * sin(theta);
			p[3] = data_x[i][2] * sin(theta) + data_x[i][3] * cos(theta);
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
#pragma endregion
#pragma region Network

inline double l_relu(double x) {
	return x > 0 ? x : 0.3 * x;
}
inline double l_relu_d(double x) {
	return x > 0 ? 1 : 0.3;
}
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
		cout << dif << ":" << endl;
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
		srand(time(NULL));
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
	void train_random(data_loader* data, int n, int batch_size = 1) {
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
#pragma endregion
network nn[100]; int Next;
data_loader dl[100];
enum colours { green, blue, red, black, yellow, magenta, cyan };
double pred_rate[10][10];
double points[10];
int Left_bound, Right_bound, Up_bound, Low_bound;
inline double dis(double x1, double yy1, double x2, double yy2) {
	return sqrt((x1 - x2) * (x1 - x2) + (yy1 - yy2) * (yy1 - yy2));
}
data_loader train_set(10000, 4, 1);
data_loader test_set(300, 4, 1);
class Ball {
public:
	colours color;
	double posx, posy;
	double radius;
	double vx, vy;
	double mass;
	bool moveable;
	double memor_x[20], memor_y[20]; int full, ptr;
	double point;
	network* brain;
	data_loader* data;
	Ball() {};
	Ball(bool type, colours Color, double Px, double Py, double Vx, double Vy, double r, double m = 1.0) :moveable(type), color(Color), posx(Px), posy(Py), vx(Vx), vy(Vy), radius(r), mass(m) {
		point = 0;
	}
	void memorize();
	void draw() {
		switch (color) {
		case red:
			setfillcolor(RED);
			break;
		case blue:
			setfillcolor(BLUE);
			break;
		case green:
			setfillcolor(GREEN);
			break;
		case black:
			setfillcolor(BLACK);
			break;
		case yellow:
			setfillcolor(YELLOW);
			break;
		case magenta:
			setfillcolor(MAGENTA);
			break;
		case cyan:
			setfillcolor(CYAN);
			break;
		}
		solidcircle(posx, posy, radius);
	}
	void clear_data() {
		ptr = 0;
		full = 0;
	}
	void add_data(double result = 0) {
		if (full == 1) {
			for (int i = 0; i < 20; i++) {
				double m = sqrt(vx * vx + vy * vy);
				data->insert(new double[4] {memor_x[i], memor_y[i], vx / m, vy / m}, new double[1] {result});
			}
		}
		else {
			for (int i = 0; i < ptr; i++) {
				double m = sqrt(vx * vx + vy * vy);
				if (memor_x[i] * memor_x[i] + memor_y[i] * memor_y[i] < 0.8) continue;
				data->insert(new double[4] {memor_x[i], memor_y[i], vx / m, vy / m}, new double[1] {result});
			}
		}
		clear_data();
		data->random_rotation(200);
	}
	void reset_speed();
	void bounce_ball(Ball* other);
	void bounce();
	void move(int Time);
	bool check_close();
	void reborn();

}balls[1000]; int top;
bool check_overlap(Ball* a, Ball* b) {

	return a->radius + b->radius >= dis(a->posx, a->posy, b->posx, b->posy);
}
void Ball::reborn() {
	bool f = 1;
	while (f) {
		posx = rand01() * 800 + 100;
		posy = rand01() * 500 + 100;
		double t = 1;
		for (int i = 1; i <= top; i++) {
			if (this == &balls[i]) continue;
			if (check_overlap(this, &balls[i])) {
				t = 0; break;
			}
		}
		if (t == 1) f = 0;
	}

}
void Ball::memorize() {
	double fx = 0, fy = 0;
	for (int i = 1; i <= top; i++) {
		if (&balls[i] == this) continue;
		double d = (dis(posx, posy, balls[i].posx, balls[i].posy)) / 100;
		fx += points[balls[i].color] * (balls[i].posx - posx) / d / d / d;
		fy += points[balls[i].color] * (balls[i].posy - posy) / d / d / d;
	}
	//std::cerr << fx << " " << fy << " " << endl;
	double m = sqrt(fx * fx + fy * fy);
	fx /= m, fy /= m;
	memor_x[ptr] = fx;
	memor_y[ptr] = fy;
	ptr++;
	if (ptr == 20) {
		ptr = 0;
		full = 1;
	}
}
void Ball::bounce_ball(Ball* other) {
	if (!check_overlap(this, other)) return;
	double delta_px = other->posx - posx;
	double delta_py = other->posy - posy;
	double delta_vx = other->vx - vx;
	double delta_vy = other->vy - vy;
	if (delta_px * delta_vx + delta_py * delta_vy < 0) {
		point += points[other->color];
		//std::cerr << points[other->color] << "--now:" << point << std::endl;
		this->add_data(points[other->color]);
		if (other->moveable == 0 && this->moveable == 1) {
			other->reborn();
		}
		double vcx = (mass * vx + other->mass * other->vx) / (mass + other->mass);
		double vcy = (mass * vy + other->mass * other->vy) / (mass + other->mass);
		//	std::cerr << mass << ", " << other->mass << endl;
		vx = 2 * vcx - vx;
		vy = 2 * vcy - vy;
		other->vx = 2 * vcx - other->vx;
		other->vy = 2 * vcy - other->vy;
	}
}
void Ball::reset_speed() {
	if (color == yellow) {
		double theta = rand01() * 3.14 * 2;
		vx = 30 * cos(theta);
		vy = 30 * sin(theta);
		return;
	}
	//return;
	if (rand01() < 0.08) add_data();
	vx = rand01() * 40 - 20;
	vy = rand01() * 40 - 20;
	double fx = 0, fy = 0;
	for (int i = 1; i <= top; i++) {
		if (&balls[i] == this) continue;
		double d = (dis(posx, posy, balls[i].posx, balls[i].posy)) / 100;
		fx += points[balls[i].color] * (balls[i].posx - posx) / d / d / d;
		fy += points[balls[i].color] * (balls[i].posy - posy) / d / d / d;
	}
	//std::cerr << fx << " " << fy << " " << endl;
	double m = sqrt(fx * fx + fy * fy);
	fx /= m, fy /= m;
	double maxm = 0; double theta = rand01() * 3.1416 * 2;
	for (double i = 0; i < 3.1514 * 2; i += 0.1) {
		brain->cal(new double[4] {fx, fy, cos(i), sin(i)});
		double tmp = brain->get_first_ans();
		//std::cerr << cos(i) << "," << sin(i) << " : " << tmp << std::endl;
		if (tmp > maxm) {
			maxm = tmp;
			theta = i;
		}
	}
	//std::cerr << theta << ":(" << cos(theta) << "," << sin(theta) << ") --" << maxm << std::endl;
	vx = 30 * cos(theta);
	vy = 30 * sin(theta);

}
void Ball::bounce() {
	bool f = 0;
	if (posx + radius >= Right_bound && vx > 0) {
		clear_data();
		vx = -vx;
	}
	if (posx - radius <= Left_bound && vx < 0) {
		clear_data();
		vx = -vx;
	}
	if (posy + radius >= Up_bound && vy > 0) {
		clear_data();
		vy = -vy;
	}
	if (posy - radius <= Low_bound && vy < 0) {
		clear_data();
		vy = -vy;
	}
	for (int i = 1; i <= top; i++) {
		if (&balls[i] != this) {
			bounce_ball(&balls[i]);
		}
	}
}
bool Ball::check_close() {
	for (int i = 1; i <= top; i++) {
		if (this == &balls[i]) continue;
		if (dis(posx, posy, balls[i].posx, balls[i].posy) < radius * 2 + balls[i].radius && (balls[i].posx - posx) * (balls[i].vx - vx) + (balls[i].posy - posy) * (balls[i].vy - vy) < 0) {
			//std::cerr << "RRR\n";
			return 1;
		}
	}
}
void Ball::move(int Time) {
	if (!moveable) {
		posx += vx * (double)Time / (double)CLOCKS_PER_SEC * 20;
		posy += vy * (double)Time / (double)CLOCKS_PER_SEC * 20;
		bounce();
		return;
	}
	//if (check_close()) reset_speed();
	else if (rand01() * (double)CLOCKS_PER_SEC <= (double)Time * 3) reset_speed();
	else if (rand01() * (double)CLOCKS_PER_SEC <= (double)Time * 100) {
		memorize();
	}
	posx += vx * (double)Time / (double)CLOCKS_PER_SEC * 20;
	posy += vy * (double)Time / (double)CLOCKS_PER_SEC * 20;
	bounce();
}
bool check_newball(Ball* x) {
	for (int i = 1; i <= top; i++) {
		if (check_overlap(x, &balls[i])) return 0;
	}
	return 1;
}
void add(double type, colours Color, double Px, double Py, double Vx, double Vy, double r, double m, int n = 100) {
	double x = rand01() * 800 + 100;
	double y = rand01() * 500 + 100;
	Ball tmp(type, Color, Px, Py, Vx, Vy, r, m);
	while (!check_newball(&tmp) && (n--)) {
		double x = rand01() * 800 + 100;
		double y = rand01() * 500 + 100;
		tmp = Ball(type, Color, Px, Py, Vx, Vy, r, m);
	}
	if (n) balls[++top] = tmp;
}
void add(double type, colours Color, double Vx, double Vy, double r, double m, int n = 100) {
	double x = rand01() * 800 + 100;
	double y = rand01() * 500 + 100;
	Ball tmp(type, Color, x, y, Vx, Vy, r, m);
	while (!check_newball(&tmp) && (n--)) {
		double x = rand01() * 800 + 100;
		double y = rand01() * 500 + 100;
		tmp = Ball(type, Color, x, y, Vx, Vy, r, m);
	}
	if (n) balls[++top] = tmp;
}
void move_all(int Time) {
	for (int i = 1; i <= top; i++) {
		balls[i].move(Time);
	}
}
void draw_all() {
	setfillcolor(WHITE);
	solidrectangle(Left_bound, Up_bound, Right_bound, Low_bound);
	for (int i = 1; i <= top; i++) {
		balls[i].draw();
	}
}
double redpoints[11000], purplepoints[11000], yellowpoints[11000];int toppp;
double ind[11000];
int main() {
	srand(time(NULL));
	for (int i = 1; i <= 5000; i++) {
		double x = rand01() * 2 - 1, y = rand01() * 2 - 1;
		double m = sqrt(x * x + y * y);
		x /= m;
		y /= m;
		double vx = rand01() * 2 - 1, vy = rand01() * 2 - 1;
		double vm = sqrt(vx * vx + vy * vy);
		vx /= vm, vy /= vm;
		double ans = 0;
		double tmp = (x * vx + y * vy) / sqrt(x * x + y * y) / sqrt(vx * vx + vy * vy);
		if (tmp > 0.5) ans = 1;
		if (tmp < -0.5) ans = -1;
		//cout << ans << endl;
		ans = tmp;
		double* p = new double[4] {x, y, vx, vy};
		double* q = new double[1] {ans};
		train_set.insert(p, q);
		delete[]p;
		delete[]q;
	}
	train_set.random_rotation();
	for (int i = 1; i <= 300; i++) {
		double x = rand01() * 2 - 1, y = rand01() * 2 - 1;
		double m = sqrt(x * x + y * y);
		x /= m;
		y /= m;
		double vx = rand01() * 2 - 1, vy = rand01() * 2 - 1;
		double vm = sqrt(vx * vx + vy * vy);
		vx /= vm, vy /= vm;
		double ans = 0;
		double tmp = (x * vx + y * vy) / sqrt(x * x + y * y) / sqrt(vx * vx + vy * vy);
		if (tmp > 0.5) ans = 1;
		if (tmp < -0.5) ans = -1;
		//cout << ans << endl;
		ans = tmp;
		double* p = new double[4] {x, y, vx, vy};
		double* q = new double[1] {ans};
		test_set.insert(p, q);
		delete[]p;
		delete[]q;
	}
	for (int i = 1; i <= 3; i++) {
		add(0, green, (rand01() - rand01()) * 3, (rand01() - rand01()) * 3, 25, 10000000);
	}
	for (int i = 1; i <= 3; i++) {
		add(0, blue, (rand01() - rand01()) * 3, (rand01() - rand01()) * 3, 30, 10000000);
	}
	for (int i = 1; i <= 5; i++) {
		add(0, black, (rand01() - rand01()) * 5, (rand01() - rand01()) * 5, 35, 10000000);
	}
	for (int i = 1; i <= 2; i++) {
		//add(0, cyan, (rand01() - rand01()) * 10, (rand01() - rand01()) * 10, 28, 10000000);
	}
	add(1, red, rand01() * 40 - 20, rand01() * 40 - 20, 20, 1, 100000);
	add(1, yellow, rand01() * 40 - 20, rand01() * 40 - 20, 20, 1, 100000);
	add(1, magenta, rand01() * 40 - 20, rand01() * 40 - 20, 20, 1, 100000);
	for (int i = 1; i <= top; i++) {
		nn[i].add_layer(4, 6, 8, 15, 10, 7, 3, 1, -1);
		balls[i].brain = &nn[i];
		balls[i].data = &dl[i];
	}

	points[red] = 0;
	points[blue] = 1;
	points[black] = -1;
	points[green] = 0.5;
	points[cyan] = -0.5;
	Up_bound = 650, Low_bound = 50, Left_bound = 50, Right_bound = 950;
	initgraph(1000, 700);
	setfillcolor(WHITE);
	rectangle(Left_bound, Up_bound, Right_bound, Low_bound);
	cleardevice();
	int t0 = clock();
	int num = 0;
	int time_0 = clock();
	while (clock()-time_0<180*CLOCKS_PER_SEC) {
		//std::cerr << clock() << endl;
		BeginBatchDraw();
		cleardevice();
		setfillcolor(RED);
		int tmp = clock() - t0;
		t0 = clock();
		move_all(tmp);
		draw_all();
		//	Sleep(10);
		if (clock() - time_0 > 10 * CLOCKS_PER_SEC)
			for (int k = 1; k <= top; k++) {
				if (balls[k].color == yellow) continue;
				if (balls[k].moveable) {
					if (balls[k].color == red) {
						balls[k].brain->train_random(balls[k].data, 1000, 1);
						//	if (rand01() < 0.01) balls[k].brain->reset();
						//if (rand01() < 0.1) std::cerr << balls[k].brain->Loss() << endl;

					}
					if (balls[k].color == magenta) {
						balls[k].brain->train_random(&train_set, 1000);
					}
					num += 1000;
				}
			}
		while (clock() - t0 < 5);
		FlushBatchDraw();
		if (rand01() < 0.03) {
			for (int k = 1; k <= top; k++) {
				if (balls[k].color == yellow) {
					std::cerr << "yellow point:" << balls[k].point << std::endl;
					yellowpoints[toppp] = balls[k].point;
				}
				if (balls[k].color == magenta) {
					std::cerr << "purple point:" << balls[k].point << std::endl;
					purplepoints[toppp] = balls[k].point;

				}
				if (balls[k].color == red) {
					std::cerr << "red point:" << balls[k].point << std::endl;
					redpoints[toppp] = balls[k].point;
					//	std::cerr << "data:" << std::endl;
				//	double loss = balls[k].brain->test(&test_set);
				//	if (loss < 0.13) balls[k].brain->close();
					//if (loss > 0.8) balls[k].brain->reset();
				//	std::cerr << "loss-test: " << loss << std::endl;
					//	balls[k].data->print();
					//	std::cerr << endl;
					//	system("pause");
				}
			}
			ind[toppp] = clock();
			toppp++;
			//std::cerr << "\n\n";

		}
	}
	/*for (int k = 1; k <= top; k++) {
		if (balls[k].color == red) {
			balls[k].data->print();
			std::cerr << endl;
				system("pause");
		}
	}
	cout << num << endl;*/
	EndBatchDraw();
	MatPlotInit();
	figure();
	plot(ind, redpoints, toppp);
	plot(ind, yellowpoints, toppp);
	plot(ind, purplepoints, toppp);
	while (1);
	MatPlotClose();
	return 0;
}