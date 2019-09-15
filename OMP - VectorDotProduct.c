#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main(int argc, char *argv[]) {
    size_t SIZE = 100000000;
    size_t i;
    double dot = 0;
	
	//Allocate memory for array in the heap
    double *a = (double*)malloc(sizeof(double)*SIZE);
    double *b = (double*)malloc(sizeof(double)*SIZE);
    
	//Fill array with all 1's
	for (i = 0; i < SIZE; i++){
		a[i] = 1;
        b[i] = 2;
    }

	//Get current time
    double start = omp_get_wtime();

	//Parallel region starts from here
	#pragma omp parallel for schedule(static, 10000) reduction(+: dot)
		for (i = 0; i <= SIZE; i++)
			dot += a[i] * b[i];
	//Parallel region ends here

	//Get current time
	double end = omp_get_wtime();
    
	printf("Dot product = %lf, time = %.10lf", dot, end - start);
	
	//Free allocated memory
	free(a);
    free(b);
    return 0;
}