#include <math.h>

#include <stdio.h>


void interval_doubling(double integral(double f(double), double, double, int), double f(double), double a, double b, double EPS) {

	int n = 1;
	double ans = 1.e+50;
	double prevans = 1.0;
	double h = (b - a)/n;

	while(fabs(ans - prevans) > EPS) {
		
		prevans = ans;

		ans = integral(f, a, b, n);
		n *= 2;
		printf("%12.5f %14.7f \n", h, ans);

	}

}



