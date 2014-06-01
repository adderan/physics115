#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define J 1.0
#define k 1.38*pow(10, -23)


double magnetization(int **lattice, int L) {
	double m = 0;
	int i,j;
	for(i = 0; i < L; i++) {
		for(j = 0; j < L; j++) {
			m += lattice[i][j];
		}
	}
	return m/(L*L);
}
		
double energy(int neighbors[], int Si) {
	double e = 0.0;
	int i;
	for(i = 0; i < 3; i++) {
		e += (-2.0)*J*Si*neighbors[i];
	}
	return e;
}

void sweep(int L, int **lattice, double T) {
	double B = 1.0/(k*T); 
	int ip, jp;
	int im = L-2;
	int jm = L-2;
	int i = L-1;
	int j = L-1;
	for(ip = 0; ip < L; ip++) {
		for(jp = 0; jp < L; jp++) {
			double r = rand()/ (RAND_MAX + 1.0);
			int neighbors[4];
			neighbors[0] = lattice[i][jp];
			neighbors[1] = lattice[i][jm];
			neighbors[2] = lattice[ip][j];
			neighbors[3] = lattice[im][j];
			int Si = lattice[i][j];
			double met = exp(-1*B*energy(neighbors, Si));

			if(r < met) {
				lattice[i][j] *= -1.0;
			}
			im = i;
			jm = j;
			i = ip;
			j = jp;


		}
	}
}

int main() {
	double T = 100.0;
	srand(time(NULL));
	int L = 10;
	int **lattice = (int**)malloc(sizeof(int*)*L);
	int i,j;
	for(i = 0; i < L; i++) {
		lattice[i] = (int*)malloc(sizeof(int)*L);
		for(j = 0; j < L; j++) {
			lattice[i][j] = 1;
		}
	
	}
	int sweeps = 100;
	for(i = 0; i < sweeps; i++) {
		sweep(L, lattice, T);
		printf("%5.6f \n", magnetization(lattice, L));
	}

	return 0;
}

