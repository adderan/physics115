#include <stdio.h>
#include <math.h>

double secant(double f(double), double x0, double x1, double TOL) {

	double x_2 = x0;
	double x_1 = x1;

	double x = 0;
	printf("    x(n-2)          x(n-1)      |x(n-1) - x(n-2)| \n");  
	while(fabs(x_2 - x_1) > TOL) {
		x = (x_2*f(x_1) - x_1*f(x_2))/(f(x_1) - f(x_2));
		x_2 = x_1;
		x_1 = x;
		printf("%5.12f %5.12f %5.12f \n", x_2, x_1, fabs(x_1 - x_2));
	}

	printf("Found root at x = %5.12f \n", x_1);
}

double f(double x) {
	return tanh(2*x) - x;
}

main() {
	double rootguess1 = 1.1;
	double rootguess2 = 1.0;
	secant(f, rootguess1, rootguess2, 1.e-12);
}




