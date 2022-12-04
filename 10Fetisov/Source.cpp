#include <iostream>
#include <cmath>
#include <cstdlib>
#include "Header.h"
using namespace std;

double Simpson(double, double, double(*)(double), double);
double fx(double);

const double eps = 1.e-10;
const double pi = 3.14159265359;
double a, b;

void main(void) {
	for (int i = 0; i < 10; i++) {
		a = rand() % 1000 + (double)(rand() % 100) / 100 + 0.01;
		b = rand() % 1000 + (double)(rand() % 100) / 100 + 0.01;
		double temp;
		if (b < a) {
			temp = a;
			a = b;
			b = temp;
		}

		// PI / 2 * M(a; b) = ∫[PI/2; 0] (dx / (a^2 * (sinx)^2 + b^2 * (cosx)^2)^0.5)
		double simpson = (2 / pi) * Simpson(0, pi / 2, fx, eps);

		cout << "[" << a << " ; " << b << "]" << endl;
		cout << "2 / (PI * Simpson): \t" << simpson << endl;
		cout << "1 / AGMean: \t\t" << 1 / AGMean(a, b) << endl;
		cout << "\n-------------------------------------------------------\n\n" << endl;
	}
}


double Simpson(double a, double b, double(* f)(double), double eps) {
	int n = 2; 
	double h = (b - a) * 0.5; 
	double ss = 0; 
	double s1 = h * (f(a) + f(b));
	double s2 = 0; 
	double s4 = 4 * h * f(a + h); 
	double s = s1 + s2 + s4;
	do {
		ss = s;
		n *= 2; 
		h /= 2; 
		s1 *= 0.5; 
		s2 = 0.5 * s2 + 0.25 * s4; 
		s4 = 0; 
		int i = 1;
		do {
			s4 = s4 + f(a + i * h); 
			i += 2;
		} while (i <= n);
		s4 = 4 * h * s4; s = s1 + s2 + s4;
	} while (fabs(s - ss) > eps);
	return s / 3;
}

double fx(double x) {
	double res = 1 / pow(pow(a, 2) * pow(sin(x), 2) + pow(b, 2) * pow(cos(x), 2), 0.5);
	return res;
}