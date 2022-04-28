#include <stdio.h>
#include "mpi.h"

int main (int argc, char *argv[])
{
	int rank, size; 

	long N = 1000000000;

	double approx_pi, sum;

	int root_proc = 0;

	MPI_Init(&argc, &argv);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);

	for (long n = rank; n < N; n+=size) {
		double term = 1.0 / (2.0 * (double)n + 1);
		if (n%2 == 0) {
			sum += term;
		}
		else {
			sum -= term;
		}
	}

	MPI_Reduce(&sum, &approx_pi, 1, MPI_DOUBLE, MPI_SUM, root_proc, MPI_COMM_WORLD);


	if (rank == 0) {
		approx_pi *= 4;
		printf("Approximation of pi with %ld iterations: %lf", N, approx_pi);
	}

	MPI_Finalize();
	return 0;
}
