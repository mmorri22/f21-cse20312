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
	if( int_vector->the_array == NULL ){
		
		// Set the array size to 1
		int_vector->the_array = (int *)malloc( sizeof(int) );
		
		// Set the capacity to 1
		int_vector->capacity = 1;
		
	}
	
	if( int_vector->length == int_vector->capacity ){
		
		// Double the capacity
		int_vector->capacity *= 2;
		
		// Set a reference to the current array 
		int* reference = int_vector->the_array;
		
		// Allocate a new array to the array of the new capacity 
		int_vector->the_array = (int *)malloc( sizeof(int) * int_vector->capacity );
		
		// Copy the old elements to the new elements 
		long unsigned int iter;
		for( iter = 0; iter < int_vector->length; ++iter ){
			
			int_vector->the_array[iter] = reference[iter];
			
		}
		
		// Free the old vector 
		free( reference );
		
	}
	
	// Set the initial element equal to insert_val
	int_vector->the_array[ int_vector->length ] = insert_val;
	
	// Increment the length
	int_vector->length++;
	
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