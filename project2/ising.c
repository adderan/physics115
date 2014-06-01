#include <rand.h>;
#include <math.h>;

double J = 1.0;
double k = 1.38*pow(10, -23);

int main() {
	srand(time(NULL));
	int[][] lattice = calloc(L*L, sizeof(int));
	int i,j;
	for(i = 0; i < L; i++) {
		for(j = 0; j < L; j++) {
			lattice[i][j] = 1;
		}
	
	}


}

	
void sweep(int[][] lattice, double T, int L) {
	double B = 1.0/(k*T); 
	int i, j;

	for(i = 0; i < L; i++) {
		for(j = 0; j < L; j++) {
			double r = rand()/ (RAND_MAX + 1.0);
			int[] neighbors = calloc(4, sizeof(int));
			neighbors[0] = lattice[i][j+1];
			neighbors[1] = lattice[i][j-1];
			neighbors[2] = lattice[i+1][j];
			neighbors[3] = lattice[i-1][j];
			int Si = neighbors[i][j];
			double met = exp(-1*B*energy(neighbors[]. Si));

			if(r < met) {
				neighbors[i][j] *= -1.0;
			}

		}
	}
}
	
double energy(int[] neighbors, int Si) {
	double e = 0.0;
	int i;
	for(i = 0; i < 3; i++) {
		e += (-2.0)*J*Si*neighbors[i];
	}
	return e;
}

