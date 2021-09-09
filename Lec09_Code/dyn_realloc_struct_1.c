#include <stdio.h>
#include <stdlib.h>

typedef struct{
	
	long unsigned int length;
	long unsigned int capacity;
	
	int* the_array;
	
} dyn_array;


void insert_dyn_array( dyn_array* int_dyn_array, int read_int ){
	
	// Dr. Morrison's Golden Rule of Pointers 
	if( int_dyn_array->the_array == NULL ){
		
		// Set the array length to 1
		int_dyn_array->length = 1;
		int_dyn_array->capacity = 1;
		
		int_dyn_array->the_array = (int *)malloc( sizeof(int) );
		
		int_dyn_array->the_array[ 0 ] = read_int;
		
		return;
	}
		
		
}

void print_array( dyn_array* int_dyn_array ){
	
	long unsigned int iter;
	for( iter = 0; iter < int_dyn_array->length; ++iter ){

		fprintf( stdout, "Allocated length = %lu, int_dyn_array[ %lu ] = %d,\t&int_dyn_array[ %lu ] = %p \n",
				int_dyn_array->capacity, iter, 
				int_dyn_array->the_array[iter], iter, 
				&(int_dyn_array->the_array[iter]) );

	}
	
}

int main( void ){

	// Construct the struct 
	long unsigned int init_len = 0;
	dyn_array* int_dyn_array = (dyn_array *)malloc( sizeof( dyn_array ) );
	
	/* De-reference for memory on the Data Heap */
	int_dyn_array->length = 0;
	int_dyn_array->capacity = init_len;
	int_dyn_array->the_array = NULL;


	/* Read in exactly one integer */
	int read_int;
	fprintf( stdout, "Enter an integer: ");
	fscanf( stdin, "%d", &read_int );

	// Pass By Reference Function 
	insert_dyn_array( int_dyn_array, read_int );
	
	// Print the array structure and data
	print_array( int_dyn_array );

	// Flush the input buffer
	getchar();
	

	// Free the array 
	free( int_dyn_array->the_array );
	
	// Free the dynamically allocated struct 
	free( int_dyn_array );

	return 0;

}
