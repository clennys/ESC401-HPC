#include <stdio.h>
#include "mpi.h"

int main (int argc, char *argv[])
{
	int rank, size, value, tag=100;;
	MPI_Status status;

	MPI_Init(&argc, &argv);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);

	if (rank == 2) {
		value = 1000;
		MPI_Send(&value, 1, MPI_INTEGER, 5, 100, MPI_COMM_WORLD);
	}
	else if (rank==5) {
		MPI_Recv(&value, 1, MPI_INTEGER, 2, tag, MPI_COMM_WORLD, &status);
		printf("Process %d, received %d from process 2\n", rank, value);
	
	}

	

	MPI_Finalize();
	return 0;
}
