#include <stdio.h>
#include <stdlib.h>

typedef struct{
	
	long unsigned int length;
	long unsigned int capacity;
	
	int the_array[];
	
} dyn_array;

int main( void ){
	
	// Construct the struct 
	// We will see later on the benefits of initializing Dynamic Arrays to a length of 0
	long unsigned int init_len = 0;
	dyn_array int_static_array = { 0, init_len };	// Leaving static array empty
	
	// Print struct addresses
	fprintf( stdout, "Register containing address of struct: %p\n", &int_static_array );
	fprintf( stdout, "Location in memory of the length     : %lu %p\n", int_static_array.length, &(int_static_array.length) );
	fprintf( stdout, "Location in memory of the capacity   : %lu %p\n", int_static_array.capacity, &(int_static_array.capacity) );
	fprintf( stdout, "Location in memory of the array      : %p\n", &(int_static_array.the_array) );
	
	// Can't free the array, since it is not a Heap object.
	// Uncommenting will produce a compiler error
	// free( int_static_array.the_array );

	return 0;
}