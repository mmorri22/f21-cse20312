#include <stdio.h>
#include <stdlib.h>

// Step 1:
// Define a type with the name new_struct
// Internals should be long unsigned int and a float
typedef struct{
	
	long unsigned int lui_data;
	float float_data;
	
} new_struct;

int main( void ){

	// Step 2: Dynamically Allocate a new_struct
	new_struct* the_struct = (new_struct *)malloc( sizeof( new_struct ) );

	// Step 3: De-reference and set values for the lui and float
	// You can pick whatever values you want
	// Hint: Recall the Ariane 5 Explosion and Floats
	the_struct->lui_data = 100;
	the_struct->float_data = (float)13.2;

	// Step 4: Print use fprintf 
	// 1) The address of the struct 
	// 2) The value and address of the struct's long unsigned int 
	// 3) The value and address of the struct's float 
	fprintf( stdout, "struct address: %p\n", &the_struct );
	fprintf( stdout, "lui: %lu %p\n", the_struct->lui_data, &(the_struct->lui_data) );
	fprintf( stdout, "flt: %f %p\n", the_struct->float_data, &(the_struct->float_data) );
	
	// Step 5: Free the Dynamically Allocated Memory
	free( the_struct );

	return 0;

};
