#include <stdlib.h>
#include <stdio.h>

int main(void)
{
	// Size of the first array we malloc - 5 elements
	long unsigned int initial_size = 5;

	int *the_array = (int *) malloc (sizeof(int) * initial_size);
	if (the_array == NULL)
	{
		printf("Error allocating memory: exiting\n");
		return 1;
	}
	// just set each element of the array to its index - e.x. the_array[0] = 0, the_array[1] = 1, ...
	long unsigned int iter = 0;
	for (iter = 0; iter < initial_size; iter++)
	{
		the_array[iter] = (int) iter;
	}

	// print out the contents of the array
	printf("First malloc (array has 5 elements): ");
	for (iter = 0; iter < initial_size; iter++)
	{
		printf("%d %p\n", the_array[iter], &the_array[iter]);
	}
	printf("\n");

	// reallocate the memeory of the array to have 5 * 2 = 10 elements and then set the value of each element equal to its index
	the_array = realloc((void *) the_array, sizeof(int) * initial_size * 2);
	if (the_array == NULL)
	{
		printf("Error reallocating memory: exiting\n");
		return 1;
	}
	for (iter = 0; iter < initial_size * 2; iter++)
	{
		printf("%d %p\n", the_array[iter], &the_array[iter]);
	}
	
	// print out the contents of the array
	printf("First realloc (array lengthened to 10 elements): ");
	for (iter = 0; iter < initial_size * 2; iter++)
	{
		printf("%d %p\n", the_array[iter], &the_array[iter]);
	}
	printf("\n");

	// reallocate memory as above, except this time we do 5 * 10 = 50 total elements and then set each element to the value of its index
	the_array = realloc((void *) the_array, sizeof(int) * initial_size * 10);
	if (the_array == NULL)
	{
		printf("Error reallocating memory: exiting\n");
		return 1;
	}
	for (iter = 0; iter < initial_size * 10; iter++)
	{
		the_array[iter] = (int) iter;
	}
	
	printf("Second realloc (array lengthened to 50 elements): ");
	for (iter = 0; iter < initial_size * 10; iter++)
	{
		printf("%d %p\n", the_array[iter], &the_array[iter]);
	}
	printf("\n");
	
	free( the_array );
	
	return 0;
}