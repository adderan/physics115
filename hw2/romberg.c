#include <stdio.h>

#include <math.h>

double romberg(double f(double), double a, double b, int n, int m) {
	if((n == 0) && (m == 0)) {
		return (double)(1/2) * (b - a) * (f(a) + f(b));
	}
	else if(m == 0) {
		double coefficient = (b - a)/pow(2, n);
		double sum = 0;
		int k;
		for(k = 0; k < (pow(2, n-1)+1); k++) {
			sum += f(a + (2*k - 1)*coefficient);
		}
		return 0.5 * romberg(f, a, b, n-1, 0) + coefficient*sum;
	}
	double r1 = romberg(f, a, b, n, m-1);
	double r2 = romberg(f, a, b, n-1, m-1);

	double coefficient = 1/(pow(4,(double)m) - 1);
	return coefficient * (pow(4,m)*r1 - r2);
}

double f(double x) {
	return exp(-x*x/2.0);
}

main() {

	double EPS = 1.e-12;
	double ans = 10000000;
	double prevans = 1;
	int n = 1;
	int m = 2;
	double a = 0.0;
	double b = 1.0;

	printf("    m      n       ans         (anser - prev answer) \n");
	while(fabs(ans - prevans) > EPS) {
		prevans = ans;
		ans = romberg(f, a, b, n, m);
		printf(" %d %d %12.8f %12.8f \n", m, n, ans, ans - prevans);
		n = n*2;
	}
}


