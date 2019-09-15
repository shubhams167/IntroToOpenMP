#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main(int argc, char *argv[]) {
    size_t i, SIZE = 1000000000;
    int sum = 0;
	
	//Allocate memory for array in the heap
    int *arr = (int*)malloc(sizeof(int)*SIZE);
    
	//Fill array with all 1's
	for (i = 0; i < SIZE; i++) 
		arr[i] = 1;

	//Get current time
    double start = omp_get_wtime();

	//Parallel region starts from here
	#pragma omp parallel for default(shared) reduction(+: sum)
		for (i = 0; i < SIZE; i++)
			sum += arr[i];
	//Parallel region ends here

	//Get current time
	double end = omp_get_wtime();
    
	printf("Sum = %d, time = %.10lf", sum, end - start);
	
	//Free allocated memory
	free(arr);
    return 0;
}