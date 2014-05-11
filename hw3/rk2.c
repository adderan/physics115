#include <math.h>
#include <stdio.h>

double rk2(double f(double, double), double x0, double y0, double xfinal, int n) { 
	double xnew = x0;
	double ynew = y0;
	double k1;
	double k2;
	int i;
	double h = fabs(xfinal-x0)/n;
	for(i = 0; i < n; i++) {
		k1 = f(xnew, ynew);
		k2 = f(xnew + h, ynew + h*k1);
		ynew = ynew + h*(0.5*k1 + 0.5*k2);
		xnew = xnew + h;
		//printf("%12.6f %12.6f \n", xnew, ynew);
	}
	return ynew;
}

double f(double x, double y) {
	return 1 + y*y;
}

main() {
	int i;
	double yfinal = 0;
	double yprevious;
	int n = 2;
	printf("Intervals    Yn(x)     |Yn(x) - Yn-1(x)|  |tan(pi/4) - Yn(x)| \n");
	for(i = 0; i < 10; i++) {
		yprevious = yfinal;
		yfinal = rk2(f, 0, 0, 0.785398, n);
		n = n*2;
		printf("%5d   %12.6f    %12.6f  %12.6f \n", n, yfinal, fabs(yprevious - yfinal), fabs(1 - yfinal));
	}
}
