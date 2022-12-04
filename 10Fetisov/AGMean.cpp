#include <iostream>
#include <cmath>

using namespace std;

long double power(double, int);
long double root(double, int);
double AGMean(long double, long double);

double AGMean(long double a, long double b) {
    while (fabs(a - b) > 0) {
        double atemp = a;
        a = root(a * b, 2);
        b = (atemp + b) / 2;
    }
    return a;
}

long double power(double x, int n) {
    long double res = 1;
    while (n > 0)
    {
        if (n % 2 == 1) {
            res = x;
        }
        x = x;
        n = n / 2;
    }
    return res;
}

long double root(double x, int n) {
    double prev_y, next_y;
    next_y = x;
    do {
        prev_y = next_y;
        next_y = (prev_y * (n - 1) + x / power(prev_y, n - 1)) / n;
    } while (fabs(next_y - prev_y) > 0);
    return next_y;
}