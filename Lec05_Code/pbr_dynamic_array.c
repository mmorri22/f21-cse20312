#include <stdio.h>
#include <stdlib.h>

void print_array( int* int_array, long unsigned int array_size ){

	fprintf( stdout, "Array Address in func : %p %p\n", &int_array, int_array );

	fprintf( stdout, "Number of ints in func: %lu\n", array_size );

	long unsigned int iter;
	for( iter = 0; iter < array_size; ++iter ){

		fprintf( stdout, "%d %p\n", int_array[ iter ], &int_array[iter] ); 

	}

}

int main( void ){

	long unsigned int array_size = 4;
	int* int_array = (int *)malloc( array_size * sizeof(int) );

	int_array[0] = 33;
	int_array[1] = 44;
	int_array[2] = 27;
	int_array[3] = 19;

	fprintf( stdout, "Array Address in main : %p %p\n", &int_array, int_array );
	fprintf( stdout, "Number of ints in main: %lu\n", array_size );	

	print_array( int_array, array_size );

	free( int_array );

	return 0;
}


