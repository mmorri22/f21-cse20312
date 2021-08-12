#include <stdio.h>
#include <stdlib.h>

struct dyn_array{
	
	long unsigned int length;
	long unsigned int capacity;
	
	int* the_array;
	
};

int main( void ){
	
	// Construct the struct 
	long unsigned int init_len = 5;
	struct dyn_array int_dyn_array = { 0, init_len, (int *)malloc( init_len * sizeof(int) ) };
	
	// Print struct addresses
	fprintf( stdout, "Register containing address of struct: %p\n", &int_dyn_array );
	fprintf( stdout, "Location in memory of the length     : %lu %p\n", int_dyn_array.length, &(int_dyn_array.length) );
	fprintf( stdout, "Location in memory of the capacity   : %lu %p\n", int_dyn_array.capacity, &(int_dyn_array.capacity) );
	fprintf( stdout, "Location in memory of the array      : %p\n", &(int_dyn_array.the_array) );
	
	// Free the array 
	free( int_dyn_array.the_array );

	return 0;
}