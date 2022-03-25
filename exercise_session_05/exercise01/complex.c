// #include <cstdlib>
// #include <iostream>
#include <stdlib.h>
#include <stdio.h>

#define SIZE 100

typedef struct complex_vector{
	int img[SIZE];
	int re[SIZE];
} complex_vector;

int linear_combination(complex_vector* x, complex_vector* y, int a, complex_vector* z){
	for (int i = 0; i < SIZE; i++) {
		z->re[i] = x->re[i] + a * y->re[i]; 
		z->img[i] = x->img[i] + a * y->img[i]; 
	}

	return 0;
}

int main (int argc, char *argv[])
{
	// complex_vector* x = new complex_vector();
	// complex_vector* y = new complex_vector();
	// complex_vector* z = new complex_vector();

	complex_vector* x = (complex_vector*) malloc(sizeof(complex_vector));
	complex_vector* y = (complex_vector*) malloc(sizeof(complex_vector));
	complex_vector* z = (complex_vector*) malloc(sizeof(complex_vector));

	int a = 2;

	for (int i = 0; i < SIZE ; i++) {
		x->img[i] = i;
		y->img[i] = i;
		x->re[i] = i;
		y->re[i] = i;
	}

	linear_combination(x, y, a, z);
	
	for (int i = 0; i < SIZE ; i++) {
		printf("%d, RE: %d IMG: %d\n", i, z->re[i], z->img[i]);
	}
	
	return 0;
}
