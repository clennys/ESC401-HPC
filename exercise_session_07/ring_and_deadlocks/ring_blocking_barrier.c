#include "mpi.h"
#include <stdio.h>

int main(int argc, char** argv) {
    // Initialize the MPI environment
    MPI_Init(&argc, &argv);

    // Get the number of processes and rank of the process
    int size, my_rank;
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);

    int my_sum = 0;

    int send_rank = my_rank;  // Send    buffer
    int recv_rank = 0;        // Receive buffer

    // Compute the ranks of left/right neighbours 
    int left_rank, right_rank;

	left_rank = ((my_rank - 1)%size + size)%size;
	right_rank = ((my_rank + 1)%size + size)%size;

    // Loop over the number of processes
    //     send to right, receive from left
    //     update the send buffer
    //     update the local sum
	
	for (int i = 0; i < size; i++) {
		if (my_rank%2 == 0) {
			MPI_Ssend(&send_rank, 1, MPI_INT, right_rank, 0, MPI_COMM_WORLD); 
		}
		else {
			MPI_Recv(&recv_rank, 1, MPI_INT, left_rank, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
			my_sum += recv_rank;
			// printf("Loop: %d :: %d -> %d :: recv_rank %d :: sum %d\n", i, left_rank, my_rank, recv_rank, my_sum);
		}
		MPI_Barrier(MPI_COMM_WORLD);

		if (my_rank%2 == 1) {
			MPI_Ssend(&send_rank, 1, MPI_INT, right_rank, 0, MPI_COMM_WORLD); 
			send_rank = recv_rank;
		}
		else {
			MPI_Recv(&recv_rank, 1, MPI_INT, left_rank, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
			my_sum += recv_rank;
			send_rank = recv_rank;
			// printf("Loop: %d :: %d -> %d :: recv_rank %d :: sum %d\n", i, left_rank, my_rank, recv_rank, my_sum);
		}
	}
	printf("I am processor %d out of %d, and the sum is %d\n", my_rank, size, my_sum);

    // Finalize the MPI environment.
    MPI_Finalize();
}
