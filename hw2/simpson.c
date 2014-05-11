#include <stdio.h>

double simpson(double f(double), double a, double b, int n) {

	double h = (b-a)/n;
	double sum = 0.0;
	int i;
	//sum = ((double)1/6) * (f(a) + 4*f((a+b)/2) + f(b));

	for(i = 0; i < n; i++) {
		sum += (double)(1.0/6.0) * f(a + i*h) + (double) (2.0/3.0) * f((2*a + i*h + (i+1)*h)/2) + (double)(1.0/6.0) * f(a + (i+1)*h);
		//printf("sum = %f \n", sum);
	}
	printf("h*sum %f \n", h*sum);
	return h * sum;
}

	
