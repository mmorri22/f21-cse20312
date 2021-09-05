#include <stdio.h>
#include <stdlib.h>

typedef struct{
	
	long unsigned int length;
	long unsigned int capacity;
	
	int* the_array;
	
} dyn_array;


int main( void ){
	
	// Construct the struct 
	long unsigned int init_len = 0;
	dyn_array* int_dyn_array = (dyn_array *)malloc( sizeof( dyn_array ) );
	
	/* De-reference for memory on the Data Heap */
	int_dyn_array->length = 0;
	int_dyn_array->capacity = init_len;
	int_dyn_array->the_array = (int *)malloc( init_len * sizeof( int ) );

	// Free the array 
	free( int_dyn_array->the_array );
	
	// Free the dynamically allocated struct 
	free( int_dyn_array );

	return 0;
}