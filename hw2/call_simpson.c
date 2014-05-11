#include <stdio.h>
#include <math.h>

double f(double x) {
	return exp(-x)*sin(x);
}


double simpson(double f(double), double a, double b, int n) {

	double h = (b-a)/n;
	double sum = 0.0;
	int i;
	//sum = ((double)1/6) * (f(a) + 4*f((a+b)/2) + f(b));

	for(i = 0; i < n; i++) {
		sum += (double)(1.0/6.0) * f(a + i*h) + (double) (2.0/3.0) * f((2*a + i*h + (i+1)*h)/2) + (double)(1.0/6.0) * f(a + (i+1)*h);
	}
	return h * sum;
}


main() {

	printf("         h           ans          (ans - prev_answer) \n");

	int n = 2;
	double a = 0.0;
	double b = 2.0;
	double EPS = 1.e-8;

	double ans = 10000000.0;
	double prevans = 1.0;
	double h = (b-a)/n;
	
	while(fabs(ans - prevans) > EPS) {
		h = (b - a)/n;
		prevans = ans;

		ans = simpson(f, a, b, n);
		n = n*2;
		printf("%12.4f   %14.8f   %12.8f \n", h, ans, ans - prevans);
	}
}

		
