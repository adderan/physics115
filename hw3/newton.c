#include <stdio.h>
#include <math.h>


double newton(double f(double), double fprime(double), double root, double TOL) {
	double prevroot = root;
	double newroot = root;
	printf("     X(n-1)            X(n)      |X(n) - X(n-1)| \n");
	double r;
	while(1) {
		r = newroot - f(newroot)/fprime(newroot);
		prevroot = newroot;
		newroot = r;
		printf(" %5.14f %5.14f %5.14f \n", prevroot, newroot, fabs(newroot - prevroot));
		if(fabs(prevroot - newroot) < TOL) break;
	}
	printf("Root found at x = %5.14f \n", newroot);
	return newroot;

}
