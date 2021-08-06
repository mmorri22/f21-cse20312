#include <stdio.h>

void print_array( int int_array[] ){

	/* Fix is here: de-reference int_array */
	long unsigned int array_size = sizeof( *int_array );

	fprintf( stdout, "Array Address in func : %p %p\n", &int_array, int_array );

	fprintf( stdout, "Number of ints in func: %lu\n", array_size );

	long unsigned int iter;
	for( iter = 0; iter < array_size; ++iter ){

		fprintf( stdout, "%d %p\n", int_array[ iter ], &int_array[iter] ); 

	}

}

int main( void ){

	int int_array[] = {33, 44, 27, 19};

	long unsigned int array_size = sizeof( int_array ) / sizeof(int);

	fprintf( stdout, "Array Address in main : %p %p\n", &int_array, int_array );
	fprintf( stdout, "Number of ints in main: %lu\n", array_size );	

	print_array( int_array );

	return 0;
}

