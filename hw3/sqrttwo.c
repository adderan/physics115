#include <math.h>
#include <stdio.h>


double f(double x) {
	return x*x - 2;
}
double fprime(double x) {
	return 2*x;
}
main() {
	double rootguess = 1.4;
	newton(f, fprime, rootguess, 1.e-14);
}

