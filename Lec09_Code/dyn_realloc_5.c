#include <stdio.h>
#include <stdlib.h>

int main( void ){

	long unsigned int init_len = 5;
	int* dyn_int_array = (int *)malloc( init_len * sizeof(int) );
	int* dyn_int_array_2 = (int *)malloc( init_len * sizeof(int) );
	
	fprintf( stdout, "array_1 at %p, array_2 at %p\n", dyn_int_array, dyn_int_array_2 );

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
			init_len *= 2;
			
			int* reference = dyn_int_array;
			
			dyn_int_array = (int *)malloc( init_len * sizeof( int ) ); 
			
			long unsigned int copy_iter;
			for( copy_iter = 0; copy_iter < num_read; ++copy_iter ){
				
				dyn_int_array[ copy_iter ] = reference[ copy_iter ];
				
			}
			
			free( reference );
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
