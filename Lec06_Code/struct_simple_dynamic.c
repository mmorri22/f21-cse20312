#include <stdio.h>
#include <stdlib.h>

struct simple{
	
	int int_data;
	double double_data;
	
};

int main(){
	
	/* Must use struct keyword since we do not reserve compiler space */
	struct simple* example_struct = ( struct simple* )malloc( sizeof( struct simple ) );

	/* De-reference and assign data values */
	example_struct->int_data = 1;
	example_struct->double_data = -13.4;
	
	fprintf( stdout, "%d %lf\n", example_struct->int_data, example_struct->double_data );
	
	/* Free dynamically allocated memory */
	free( example_struct );
	
	return 0;
}