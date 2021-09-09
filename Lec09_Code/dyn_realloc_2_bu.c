#include <stdio.h>
#include <stdlib.h>

int main( void ){

	long unsigned int init_len = 5;
	int* dyn_int_array = (int *)malloc( init_len * sizeof(int) );

	char read_char = 'y';
	long unsigned int num_read = 0;

	while( read_char == 'y' ){

		int read_int;
		fprintf( stdout, "Enter an integer: ");
		fscanf( stdin, "%d", &read_int );

		dyn_int_array[ num_read ] = read_int;

		++num_read;	

		long unsigned int iter;
		for( iter = 0; iter < num_read; ++iter ){
		
			fprintf( stdout, "Allocated length = %lu, dyn_int_array[ %lu ] = %d,\t&dyn_int_array[ %lu ] = %p \n", 
					init_len, iter, dyn_int_array[iter], iter, &dyn_int_array[iter] );
				
		}
		
		// Initial attempt to re-allocate 
		if( num_read == init_len ){
			// Double the length
			init_len *= 2;
			// 
			dyn_int_array = (int *)realloc( dyn_int_array, init_len ); 
		}

		// Flush the input buffer
		getchar();

		fprintf( stdout, "Do you wish to continue? (y for yes): ");  
		fscanf( stdin, "%c", &read_char ); 
	}

	// Free the Dynamically Allocated Array
	free( dyn_int_array );

	return 0;

}
