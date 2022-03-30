#include "jacobi.h"
#include <math.h>

/**
 * @brief      Computes norm of the difference between two matrices
 *
 * @param[in]  p     Parameters
 * @param      mat1  The matrix 1
 * @param      mat2  The matrix 2
 *
 * @return     Returns \sqrt{\sum(mat1_{ij} - mat2_{ij})^2/(nx*ny)}
 */
double norm_diff(params p, double** mat1, double** mat2){
	double sum = 0;
	for (int row = 0; row < p.nx ; row++) {
		for (int col = 0; col < p.ny; col++) {
			sum += pow(mat1[row][col] - mat2[row][col], 2);
		}
	}
    return sqrt(sum/(p.nx*p.ny));
}

/**
 * @brief      Compute a Jacobi iteration to solve Poisson equation. This function updates
 *             u_new and u_old in-place.
 *
 * @param[in]  p      Parameters
 * @param      u_new  The new solution
 * @param      u_old  The old solution
 * @param      f      The source term
 */
void jacobi_step(params p, double** u_new, double** u_old, double** f){
    double dx = 1.0/(double(p.nx - 1));
    double dy = 1.0/(double(p.ny - 1));

    for (int i=0; i<p.nx; i++){
        for (int j=0; j<p.ny; j++){
            u_old[i][j] = u_new[i][j];
        }
    }
	for (int row = 1; row < p.nx - 1; row++) {
		for (int col = 1; col < p.ny - 1; col++) {
			u_new[row][col] = (u_old[row-1][col] + u_old[row+1][col] + u_old[row][col-1] + u_old[row][col+1] - (dx*dy*f[row][col]))/4;
		}
	}
}
