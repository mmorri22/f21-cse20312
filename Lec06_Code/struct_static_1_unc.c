#include <stdio.h>
#include <stdlib.h>

typedef struct{
	
	long unsigned int length;
	long unsigned int capacity;
	
	// Statically Allocated Array
	int the_array[];
	
} static_array;

int main( void ){
	
	// Construct the struct 
	// We will see later on the benefits of initializing *Dynamic* Arrays to a length of 0
	long unsigned int init_len = 0;
	static_array int_static_array = { 0, init_len };	// Leaving static array empty
	
	fprintf( stdout, "%lu %lu\n", int_static_array.length, int_static_array.capacity );
	
	// We will see what happens when I uncomment this line
	free( int_static_array.the_array );

	return 0;
}


