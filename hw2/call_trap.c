#include <math.h>

#include <stdio.h>

double f(double x) {
	return 1/(1 + x);
}

main() {
	double x, a, b, h, exact, ans, trap();

	int i, n, iter, ITERMAX;

	exact = log((double) 2.0);
	ITERMAX = 8;
	b = 1.0;
	a = 0;

	printf("        h           ans      (exact-ans)/h^2 \n");
	n = 1;
	for (iter = 0; iter < ITERMAX; iter++) {
		h = (b - a)/n;
		ans = trap(f, a, b, n);
		n *= 2;
		printf("%12.5f %12.5f %12.5f \n", h, ans, (ans - exact)/(h*h));
	}
}

