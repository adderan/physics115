#include <stdio.h>
#include <math.h>



double bisection(double f(double), double a, double b, double TOL) {
	if(fabs(f(a)) + fabs(f(b)) == fabs(f(a)+f(b))) {
		printf("Interval does not contain root.\n");
		return -99999;

	}
	printf(" a           b          (a+b)/2         f((a+b)/2) \n");
	while(fabs(b-a) > TOL) {
		printf("%12.5f %12.5f %12.5f %12.5f \n", a, b, (a+b)/2, f((a+b)/2));
		double middle = (a+b)/2;
		if(fabs(f(a)) + fabs(f(middle)) == fabs(f(a)+f(middle))) {
			a = middle;
		}
		else {
			b = middle;
		}
		
	}
	return a;
}


double bracketRoot(double f(double), double a, double step) {
	double b = a;
	//printf("%f %f %f %f \n", a, fabs(f(a)), b, fabs(f(b)));

	while(fabs(f(a)) + fabs(f(b)) == fabs(f(a)+f(b))) {
		b = b + step;
	}
	return b;
}
double f(double x) {
	return pow(x, 3.0) - 5.0*x + 3.0;
}

main() {
	double a1 = 0;
	double b1 = bracketRoot(f, a1, 0.5);
	double a2 = b1;
	double b2 = bracketRoot(f, a2, 0.5);
	//printf(" %f %f %f %f \n", a1, b1, a2, b2);
	double r1 = bisection(f, a1, b1, 1.e-5);
	printf("Root 1 at x = %3.4f \n", r1);
	double r2 = bisection(f, a2, b2, 1.e-5);
	printf("Root 2 at x = %3.4f \n", r2);
}
	
