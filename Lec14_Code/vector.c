#include <stdio.h>
#include <stdlib.h>

typedef struct vector{
	
	long unsigned int length;
	long unsigned int capacity;
	
	int* the_array;
	
} vector;


void constructor( vector* int_vector ){
	
	int_vector->length = 0;
	int_vector->capacity = 0;
	int_vector->the_array = NULL;
	
}


void destructor( vector* int_vector ){
	
	if( int_vector->the_array != NULL )
		free( int_vector->the_array );
	
}

void print_array( vector* int_vector ){
	
	long unsigned int iter;
	for( iter = 0; iter < int_vector->length; ++iter ){
		
		fprintf( stdout, "int_vector[%lu] = %d at %p\n", 
				iter, int_vector->the_array[iter], &(int_vector->the_array[iter]) );
	}
	
}


void insert( vector* int_vector, int insert_val ){
	
	// First, follow Dr. Morrison's Golden Rule of Pointers
	if(  ){
		
		// Set the array size to 1
		
		
		// Set the capacity to 1
		
		
	}
	
	if(  ){
		
		// Double the capacity
		
		
		// Set a reference to the current array 
		
		
		// Allocate a new array to the array of the new capacity 
		
		
		// Copy the old elements to the new elements 
		
		
			
			
			
		
		
		// Free the old vector 
		
		
	}
	
	// Set the initial element equal to insert_val
	
	
	// Increment the length
	
	
	return;
	
}


int main(){
	
	// malloc the struct  
	vector* int_vector = (vector *)malloc( sizeof( vector ) );	
	
	// Call the constructor 
	constructor( int_vector );
	
	// Keep looping 
	char read_char = 'y';
	while( read_char == 'y' ){
		
		/* Read in exactly one integer */
		int read_int;
		fprintf( stdout, "Enter an integer: ");
		fscanf( stdin, "%d", &read_int );


		insert( int_vector, read_int );
		
		print_array( int_vector );

		// Flush the input buffer
		getchar();

		fprintf( stdout, "Do you wish to continue? (y for yes): ");
		fscanf( stdin, "%c", &read_char );		
		
	}
	
	// Call the destructor 
	destructor( int_vector );
	
	// Free the vector 
	free( int_vector );
	
	return 0;
	
}