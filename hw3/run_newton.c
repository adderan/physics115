#include <math.h>
#include <stdio.h>

/*
double f(double x) {
	return pow(x, 3.0) - 5*x + 3;
}
*/
double f(double x) {
	return pow(x, 3.0) -5*x + 3;
}
double fprime(double x) {
	return 3*pow(x, 2.0) - 5;
}

main() {
	double rootguess1 = 0.6566;
	double rootguess2 = 1.8342;
	double rootprecise1 = newton(f, fprime, rootguess1, 1.e-14);
	double rootprecise2 = newton(f, fprime, rootguess2, 1.e-14);

}


