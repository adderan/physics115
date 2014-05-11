#include <stdio.h>
#include <math.h>

double f(double x, double y) {
	return 1 + y*y;
}




double rk4(double f(double, double), double x0, double y0, double xfinal, int n, int p) {
	double k1;
	double k2;
	double k3;
	double k4;
	double x = x0;
	double y = y0;
	double yprev = y0;

	double h = fabs(xfinal-x0)/n;

	int i;
	if(p) printf("     x            t \n");
	for(i = 0; i < n; i++) {
		k1 = f(x, y);
		k2 = f(x + 0.5*h, y + (h/2)*k1);
		k3 = f(x + (h/2), y + (h/2)*k2);
		k4 = f(x + h, y + h*k3);
		if(p) {
			printf("%12.6f %12.6f \n", y, x);
		}
		y = y + (h/6)*(k1 + 2*k2 + 2*k3 + k4);
		x = x + h;
	}
	return y;
}
double oscillator(double x, double y) {
	return 2 - (1/2)*pow(y, 4.0);
}
main() {
	printf("Question 6, anharmonic oscillator: \n");
	printf("Amplitude = 0.1: \n");
	double y1 = rk4(oscillator, 0, 0.1, 10, 20, 1);
	printf("Amplitude = 1: \n");
	double y2 = rk4(oscillator, 0, 1, 10, 20, 1);
	printf("Amplitude = 10: \n");
	double y3 = rk4(oscillator, 0, 10, 10, 20, 1);


	printf("\n \n Question 7: \n");
	int i;
	int n = 1;
	printf("Intervals    Yn      |tan(pi/4) - Y(n)| \n");
	for(i = 0; i < 10; i++) {
		double Yn = rk4(f, 0, 0, 0.7853981, n, 0);
		printf(" %5d   %12.6f   %12.6f \n", n, Yn, fabs(1 - Yn));
		n = n*2;
	}

}

