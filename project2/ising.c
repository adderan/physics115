#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define J 1.0
#define k 1.0


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
		e += 2.0*J*Si*neighbors[i];
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
void initializeSpins(int **lattice, int L) {
	int i, j;
	for(i = 0; i < L; i++) {
		for(j = 0; j < L; j++) {
		  /*
			double r = rand()/(RAND_MAX + 1.0);
			if(r >= 0.5) {
				lattice[i][j] = -1;
			}
			else {
				lattice[i][j] = 1;
			}
		  */
		  lattice[i][j] = 1;
		}
	}
}
void printLattice(int **lattice, int L) {
	int i,j;
	for(i = 0; i < L; i++) {
		for(j = 0; j < L; j++) {
			if(lattice[i][j] == 1) {
				printf("+ ");
			}
			else {
				printf("- ");
			}
			//printf("%2d ", lattice[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}
double* stats(double T, int N, double X[N]) {
	double mean = 0;
	int i;
	for(i = 0; i < N; i++) {
		mean += X[i];
	}
	mean /= N;

	double ssquared = 0;
	for(i = 0; i < N; i++) {
		ssquared += pow((X[i] - mean), 2);
	}
	ssquared /= N;

	double sigma = sqrt(ssquared)/sqrt(N - 1);
	double *results = (double*)malloc(sizeof(double)*2);
	results[0] = mean;
	results[1] = sigma;
	//printf("<m^2> = %5.6f +- %5.6f \n", mean, sigma);
	printf("%2.4f %5.6f  %5.6f \n", T, mean, sigma);
	return results;
}
void run(int **lattice, double T, int L, int N, int mdrop, int sweeps) {
	int i,j;
	double m2measurements[N];
	for(j = 0; j < N; j++) {
		initializeSpins(lattice, L);
		//printLattice(lattice, L);

		//equilibrate
		for(i = 0; i < mdrop; i++) {
			sweep(L, lattice, T);
		}
		//printLattice(lattice, L);

		//measure <m^2>
		double m2 = 0;
		for(i = 0; i < sweeps; i++) {
			sweep(L, lattice, T);
			m2 += pow(magnetization(lattice, L), 2);
		}
		m2 /= sweeps;
		m2measurements[j] = m2;
	}
	stats(T, N, m2measurements);
}
	
int main(int argc, char **argv) {
	srand(time(NULL));
	int L = atoi(argv[1]);
	int **lattice = (int**)malloc(sizeof(int*)*L);
	int i;
	
	for(i = 0; i < L; i++) {
		lattice[i] = (int*)malloc(sizeof(int)*L);
	
	}

	int sweeps = 1000;
	int N = 100;
	int mdrop = 100;
	double Tmin = 0.0;
	double Tmax = 3.0;
	double Tstep = 0.05;
	double T = Tmin;
	while(T < Tmax) {
		run(lattice, T, L, N, mdrop, sweeps);
		T += Tstep;
	}
	return 0;
}

