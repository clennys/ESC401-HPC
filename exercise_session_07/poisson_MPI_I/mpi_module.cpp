#include "mpi.h"
#include <stdio.h>
#include "init.h"

int start_MPI(int* my_rank, int* size){
	printf("Setting MPI environment\n");
	MPI_Init(NULL,NULL);
	MPI_Comm_size(MPI_COMM_WORLD,size);
	MPI_Comm_rank(MPI_COMM_WORLD,my_rank);

	return 0;
}

int close_MPI(){
	MPI_Finalize();
	return 0;
}

int mpi_get_domain(int nx, int ny, int my_rank, int size, int* min_x, int* max_x, int* min_y, int* max_y){
	/*
	define corners or local domains
	*/

	int slice = nx/size;
	*min_x = my_rank * slice;
	*max_x = (my_rank == size - 1) ? nx : slice + *min_x;

	*max_y = ny;
	*min_y = 0;

	printf("I am rank %d and my domain is: xmin, xmax, ymin, ymax: %d %d %d %d\n",my_rank,*min_x,*max_x,*min_y,*max_y);
	return 0;
}

int halo_comm(params p, int my_rank, int size, double** u, double* fromLeft, double* fromRight){
	
	/*this function, vectors fromLeft and fromRight should be received from the neighbours of my_rank process*/
	/*if you want to implement also cartesian topology, you need fromTop and fromBottom in addition to fromLeft a
	nd fromRight*/
	for (int j=0;j<(p.ymax - p.ymin);j++) {fromLeft[j] = 0; fromRight[j] = 0;} //initialize fromLeft and fromRight
	
	double* sendRight = new double [p.ymax - p.ymin];
	for (int j=0;j<(p.ymax - p.ymin);j++) sendRight[j] = u[p.xmax - p.xmin - 1][j];
	double* sendLeft = new double [p.ymax - p.ymin];
	for (int j=0;j<(p.ymax - p.ymin);j++) sendLeft[j] = u[0][j];


	MPI_Request reqs [4];

    /* define columns to be sent to right neighbour and to the left neighbour, 
    also receive one both form left and right neighbour*/
	if (my_rank	!= size - 1)
	{
		MPI_Irecv(&fromRight, p.ymax - p.ymin, MPI_DOUBLE, my_rank + 1, 0, MPI_COMM_WORLD, &reqs[0]);
		MPI_Isend(&sendRight, p.ymax - p.ymin , MPI_DOUBLE, my_rank + 1, 0, MPI_COMM_WORLD, &reqs[1]); 
	}
	if( my_rank != 0)
	{
		MPI_Irecv(&fromLeft, p.ymax - p.ymin, MPI_DOUBLE, my_rank - 1, 0, MPI_COMM_WORLD, &reqs[2]);
		MPI_Isend(&sendLeft, p.ymax - p.ymin , MPI_DOUBLE, my_rank - 1, 0, MPI_COMM_WORLD, &reqs[3]);
	}
		MPI_Waitall(4, reqs, MPI_STATUS_IGNORE);

    /* choose either to define MPIcolumn_type (lines 43-45) or define 
    the columns to be sent manually (lines 53-56)*/

    // MPI_Datatype column_type;
    // MPI_Type_vector(p.ymax - p.ymin, 1, p.xmax - p.xmin, MPI_DOUBLE, &column_type);
    // MPI_Type_commit(&column_type);

    // ...some code goes here and then do not forget to free the column_type

    // MPI_Type_free(&column_type);

	//or alternative approach below

	// double* column_to_right = new double [p.ymax - p.ymin];
	// for (int j=0;j<(p.ymax - p.ymin);j++) column_to_right[j] = u[p.xmax - p.xmin - 1][j]; 
	// double* column_to_left = new double [p.ymax - p.ymin];
	// for (int j=0;j<(p.ymax - p.ymin);j++) column_to_left[j] = u[0][j]; 


	printf("mpi_module.cpp, define halo comm:  \n");
	return 0;
}


int ALLREDUCE(double* loc_diff, double* loc_sumdiff){

	MPI_Allreduce(loc_diff, loc_sumdiff, 1, MPI_DOUBLE, MPI_SUM, MPI_COMM_WORLD);
	return 0;

	}

