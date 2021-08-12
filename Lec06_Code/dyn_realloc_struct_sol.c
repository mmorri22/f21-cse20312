#include <stdio.h>
#include <stdlib.h>

struct dyn_array{
	
	long unsigned int length;
	long unsigned int capacity;
	
	int* the_array;
	
};

void insert_dyn_array( struct dyn_array* int_dyn_array, int read_int ){
		
		fprintf( stdout, "length = %lu, capacity = %lu, read_int = %d\n", 
			int_dyn_array->length, int_dyn_array->capacity, read_int );
		
		int_dyn_array->the_array[ int_dyn_array->length ]  = read_int;

		++(int_dyn_array->length);
		

		long unsigned int iter;
		for( iter = 0; iter < int_dyn_array->length; ++iter ){

			fprintf( stdout, "Allocated length = %lu, int_dyn_array[ %lu ] = %d,\t&int_dyn_array[ %lu ] = %p \n",
					int_dyn_array->capacity, iter, int_dyn_array->the_array[iter], 
					iter, &(int_dyn_array->the_array[iter]) );

		}

		// Initial attempt to re-allocate
		// If the number read is equal to the capacity
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
		
		
}

int main( void ){

	long unsigned int init_len = 5;
	struct dyn_array* int_dyn_array = (struct dyn_array *)malloc( sizeof( struct dyn_array ) );
	
	int_dyn_array->length = 0;
	int_dyn_array->capacity = init_len;
	int_dyn_array->the_array = (int *)malloc( init_len * sizeof( int ) );

	char read_char = 'y';
	while( read_char == 'y' ){

		int read_int;
		fprintf( stdout, "Enter an integer: ");
		fscanf( stdin, "%d", &read_int );

		// Pass By Reference Function 
		insert_dyn_array( int_dyn_array, read_int );

		// Flush the input buffer
		getchar();

		fprintf( stdout, "Do you wish to continue? (y for yes): ");
		fscanf( stdin, "%c", &read_char );
	}

	// Free the Dynamically Allocated Arrays
	free( int_dyn_array->the_array );

	return 0;

}
