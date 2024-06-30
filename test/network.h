/*#ifndef NETWORK_H
#define NETWORK_H
#include<iostream>
#include<cmath>
#include<vector>
#include<cstdarg>
#include<random>
using std::cin;
using std::cout;
using std::endl;
inline double rand01() {
    return ((double)(rand() % 20000)) / 20000.0;
}
class data_loader {
    friend class network;
public:
    data_loader() {
        amount = x_size = y_size = 0;
        ptr = full = 0;
    }
    data_loader(int n, int x, int y) :amount(n), x_size(x), y_size(y) {
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
            double theta = 3.1415926 * rand01();
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
    network(int n) :num(n) {
        N = new neuro[n * 2];
        //srand(time(NULL));
        lr = 0.03;
        layer_num = 0;
        num = 0;
        loss = 0;
        first = N;
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
        for (int i = 0; i < num; i++) {
            if (N[i].type == 1) continue;
            N[i].change(Lr);
        }
    }
    void adjust() {
        for (int i = 0; i < num; i++) {
            if (N[i].type == 1) continue;
            N[i].change(lr);
        }
    }
    void anneal(double r) {
        lr -= lr * r;
    }
    void train(double* v1, double* v2) {
        cout << "no" << endl;
        cal(v1);
        back(v2);
        adjust();
    }
    void train(data_loader* data, int batch_size = 1, int epoch = 1) {
        while (epoch--) {
            int sz = data->range();
            for (int i = 0; i < sz; i++) {
                //	cout << i << endl;
                cal(data->data_x[i]);
                back(data->data_y[i]);
                if (i % batch_size == 0) {
                    adjust(lr / batch_size);
                }
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
    double Loss() {
        return loss;
    }
private:
    neuro* N;
    neuro* first;
    int num;
    int layer_num;
    std::vector<int> layer_size;
    double loss;
    double lr;

};

#endif // NETWORK_H
*/
