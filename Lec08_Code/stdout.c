#include <stdio.h>
#include <stdlib.h>

int main()
{
    
	/* Variables */
	FILE* stdout_ptr = stdout;
	FILE* input_file = fopen( "input.txt", "r" );
	FILE* output_file = fopen( "output.txt", "w" );
	char std_array[25];

    /* Print the initial locations */
	fprintf( stdout_ptr, "stdout_ptr at %p, stdout at %p, input_file at %p\n", 
	    stdout_ptr, stdout, input_file );

    /* Iterate through the while loop */
    while( input_file != NULL ){

    	fscanf( input_file, "%s", std_array );
    
    	fprintf( stdout_ptr, "%s ", std_array );
		
		fprintf( output_file, "%s ", std_array );
    	
    	char check_new_line = (char)fgetc( input_file );
    	
    	/* Print a new line if pointed */
    	if( check_new_line == '\n' ){
    	    fprintf( stdout_ptr, "\n" );
			fprintf( output_file, "\n" );
		}
    	
    	/* Break when we reach the end of the FILE* */
    	if(input_file->_IO_read_ptr == input_file->_IO_read_end)
            break;
	
    }

	fclose( input_file );

    return 0;
	
}