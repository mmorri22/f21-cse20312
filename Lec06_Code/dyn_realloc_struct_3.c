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
	
	// If it gets here, there is at least one element
	if( int_dyn_array->length == int_dyn_array->capacity ){
		
		// Multiply the capacity by two
		int_dyn_array->capacity *= 2;
		
		// Point to the old memory
		int* reference = int_dyn_array->the_array;

		// Re-allocate
		int_dyn_array->the_array = (int *)malloc( int_dyn_array->capacity * sizeof( int ) );
		
		// Copy
		long unsigned int copy_iter;
		for( copy_iter = 0; copy_iter < int_dyn_array->length; ++copy_iter ){
			
			int_dyn_array->the_array[copy_iter] = reference[ copy_iter ];
			
		}
		
		// Free memory pointed to by reference 
		free( reference );		
		
	}
	
	// Insert the element in the next available location
	int_dyn_array->the_array[ int_dyn_array->length ] = read_int;
	
	// Increment the length of the array 
	++(int_dyn_array->length);
		
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

	/* Note: This code will segfault with more than two entries */
	char read_char = 'y';
	while( read_char == 'y' ){

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

		fprintf( stdout, "Do you wish to continue? (y for yes): ");
		fscanf( stdin, "%c", &read_char );
	}
	

	// Free the array 
	free( int_dyn_array->the_array );
	
	// Free the dynamically allocated struct 
	free( int_dyn_array );

	return 0;

}
