#include <stdio.h>
#include <stdlib.h>

void insert_dyn_array( int** dyn_int_array, int read_int, long unsigned int* num_read,
	long unsigned int* init_len ){
		
		fprintf( stdout, "num_read = %lu, init_len = %lu, read_int = %d\n", *num_read, *init_len, read_int );
		
		*dyn_int_array [ *num_read ] = read_int;

		++(*num_read);
		
		fprintf( stdout, "num_read = %lu, init_len = %lu\n", *num_read, *init_len );

		long unsigned int iter;
		for( iter = 0; iter < *num_read; ++iter ){

			fprintf( stdout, "Allocated length = %lu, dyn_int_array[ %lu ] = %d,\t&dyn_int_array[ %lu ] = %p \n",
					*init_len, iter, *dyn_int_array[iter], iter, &*dyn_int_array[iter] );

		}

		// Initial attempt to re-allocate
		// If the number read is equal to the length
		if( *num_read == *init_len ){

			// Multiply the length by two
			*init_len *= 2;
			
			// Point to the old memory
			int* reference = *dyn_int_array;

			// Re-allocate
			*dyn_int_array = (int *)malloc( *init_len * sizeof( int ) );
			
			// Copy
			long unsigned int copy_iter;
			for( copy_iter = 0; copy_iter < *num_read; ++copy_iter ){
				
				*dyn_int_array[ copy_iter ] = reference[ copy_iter ];
				
			}
			
			// Free memory pointed to by reference 
			free( reference );
		}		
		
		
}

int main( void ){

	long unsigned int init_len = 5;
	int* dyn_int_array = (int *)malloc( init_len * sizeof(int) );

	char read_char = 'y';
	long unsigned int num_read = 0;
	
	fprintf( stdout, "Array initial address: %p\n", dyn_int_array );

	while( read_char == 'y' ){

		int read_int;
		fprintf( stdout, "Enter an integer: ");
		fscanf( stdin, "%d", &read_int );

		// Pass By Reference Function 
		insert_dyn_array( &dyn_int_array, read_int, &num_read, &init_len );

		// Flush the input buffer
		getchar();

		fprintf( stdout, "Do you wish to continue? (y for yes): ");
		fscanf( stdin, "%c", &read_char );
	}

	// Free the Dynamically Allocated Arrays
	free( dyn_int_array );

	return 0;

}
