#include <iostream>
#include <cstdlib>
#include <stdio.h>

void swap(int **mat){
	int *p = *mat;
	int *q = *(mat+1);
	q = q + 4;

	for (int i = 0; i < 5; i++) {
		int tmp = *(p + i);
		*(p + i) = *(q - i);
		*(q - i) = tmp;
	}

}


int main (int argc, char *argv[])
{
	int** M = new int *[2];
    M[0] = new int[5]{0,1,2,3,4};
    M[1] = new int[5]{5,6,7,8,9};

	swap(M);
	int *p = *M;
	int *q = *(M+1);

	for (int j = 0; j < 5; j++) {
		printf("%d", *(p + j));
	}
	printf("\n");

	for (int j = 0; j < 5; j++) {
		printf("%d", *(q + j));
	}

	return 0;
}

