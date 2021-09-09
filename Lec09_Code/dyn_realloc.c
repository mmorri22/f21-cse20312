#include <stdio.h>
#include <stdlib.h>

int main( void ){

	// Allocate a dynamic array of integer
	long unsigned int init_len = 5;
	int* dyn_int_array = (int *)malloc( init_len * sizeof(int) );

	// Used as the while loop input
	char read_char = 'y';
	long unsigned int num_read = 0;

	while( read_char == 'y' ){

		int read_int;
		fprintf( stdout, "Enter an integer: ");
		fscanf( stdin, "%d", &read_int );

		dyn_int_array[ num_read ] = read_int;

		++num_read;

		long unsigned int iter;
		for( iter = 0; iter < num_read; ++iter ){

			fprintf( stdout, "Allocated length = %lu, dyn_int_array[ %lu ] = %d,\t&dyn_int_array[ %lu ] = %p \n",
					init_len, iter, dyn_int_array[iter], iter, &dyn_int_array[iter] );

		}

		// Flush the input buffer
		getchar();

		// Get the next input char from the user
		fprintf( stdout, "Do you wish to continue? (y for yes): ");
		fscanf( stdin, "%c", &read_char );
	}

	// Free the Dynamically Allocated Array
	free( dyn_int_array );

	return 0;

}
