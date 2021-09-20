#include <stdio.h>
#include <stdlib.h>

int main( void ){

	long unsigned int init_len = 5;
	int* dyn_int_array = (int *)malloc( init_len * sizeof(int) );

	// Allocate a second dynamic array
	// char* dyn_int_array_2 = (char *)malloc( init_len * sizeof(char) );

	// Print the addresses of both
	// fprintf( stdout, "Array 1 is at %p, and Array 2 is at %p\n\n", dyn_int_array, dyn_int_array_2 );

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

		// Initial attempt to re-allocate
		// If the number read is equal to the length
		if( num_read == init_len ){

			// Multiply the length by two
			init_len *= 2;

			// Re-allocate
			dyn_int_array = (int *)realloc( dyn_int_array, init_len );
		}

		// Flush the input buffer
		getchar();

		fprintf( stdout, "Do you wish to continue? (y for yes): ");
		fscanf( stdin, "%c", &read_char );
	}

	// Free the Dynamically Allocated Arrays
	free( dyn_int_array );
	// free( dyn_int_array_2 );

	return 0;

}
