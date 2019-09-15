#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main(int argc, char *argv[]) {
    size_t N = 10000, M = 10000;
    size_t i, j;

	//Allocate memory for array in the heap
    int *a = (int*)malloc(sizeof(int) * N * M);
    int *b = (int*)malloc(sizeof(int) * M);
    int *c = (int*)malloc(sizeof(int) * N);
    
    //Fill matrix a, vector b, and vector c (with 0s)
    for (i = 0; i < N; i++){
        for (j = 0; j < M; j++){
            a[i*N + j] = 1;
            b[j] = 1;
        }
        c[i] = 0;
    }
    
	//Get current time
    double start = omp_get_wtime();
    
	//Parallel region starts from here
	#pragma omp parallel private(i, j)
    {
        #pragma omp for 
        for (i = 0; i < N; i++)
            for(j = 0; j < M; j++)
			    c[i] += (a[i*N + j] * b[j]);
    }
	//Parallel region ends here

	//Get current time
	double end = omp_get_wtime();
    
    //Print resultant vector
    for(i = 0; i < N; i++)
        printf("%d\n", c[i]);
	printf("time = %.10lf", end - start);
	
	//Free allocated memory
	free(a);
    free(b);
    free(c);
    return 0;
}