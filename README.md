# Introduction to OpenMP
 - OpenMP is an API (Application Programming Interface) for shared memory model programming in C, C++, and Fortran.

 - OpenMP is based on Fork-Join model.

 - OpenMP is thread based.

 - OpenMP is cross-platform i.e., it is not specific to any particular OS.

## Using OpenMP with GCC compiler

Let's take a basic OpenMP code in C language which sums up all values in an array.

```c
#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main(int argc, char *argv[]) {
	int SIZE = 1000000000;
	int i, sum = 0;

	//Allocate memory for array in the heap
	int *arr = (int*)malloc(sizeof(int)*SIZE);

	//Fill array with all 1's
	for (i = 0; i < SIZE; i++) 
	arr[i] = 1;

	//Get current time
	double start = omp_get_wtime();

	//Parallel region starts from here
	#pragma omp parallel for default(shared) reduction(+: sum)
		for (i = 0; i <= SIZE; i++)
			sum += arr[i];
	//Parallel region ends here

	//Get current time
	double end = omp_get_wtime();

	printf("Sum = %d, time = %.10lf", sum, end - start);

	//Free allocated memory
	free(arr);
	return 0;
}
```

Let's name this file _main.c_

Now, open up a terminal and execute the following command to run your code with OpenMP support enabled

```sh
$ gcc -fopenmp main.c
$ ./a.out
```
