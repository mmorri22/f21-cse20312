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
	
	// Free the array 
	free( int_dyn_array.the_array );

	return 0;
}


