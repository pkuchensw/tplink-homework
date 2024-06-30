#ifndef FUN_H
#define FUN_H
#include<cstdlib>
#include<cmath>

inline double rand01() {
	return ((double)(rand() % 20000)) / 20000.0;
}
inline double l_relu(double x) {
	return x > 0 ? x : 0.2 * x;
}
inline double l_relu_d(double x) {
	return x > 0 ? 1 : 0.2;
}
inline double sigmoid(double x) {
    return 1 / (1 + exp(-x));
}
inline double sigmoid_d(double x) {
    double s = sigmoid(x);
    return s * (1 - s);
}
inline double relu(double x) {
    return x > 0 ? x : 0;
}
inline double relu_d(double x) {
    return x > 0 ? 1 : 0;
}
inline double tanh(double x) {
    return (exp(x) - exp(-x)) / (exp(x) + exp(-x));
}
inline double tanh_d(double x) {
    return 1 - tanh(x) * tanh(x);
}
inline void rotate(double& x, double& y, double theta) {
    double tx = x, ty = y;
    x = cos(theta) * tx - sin(theta) * ty;
    y = sin(theta) * tx + cos(theta) * ty;
}
inline double product(double _x1, double _y1,double _x2,double _y2) {
    return (_x1 * _x2 + _y1 * _y2) / sqrt(_x1 * _x1 + _y1 * _y1) / sqrt(_x2 * _x2 + _y2 * _y2);
}
inline double distance(double _x1,double _y1, double _x2, double _y2){
    return sqrt((_x1-_x2)*(_x1-_x2)+(_y1-_y2)*(_y1-_y2));
}
inline double Pow(double a,double r){
    double ret=1.0;
    while(r--) ret*=a;
    return ret;
}
#endif
