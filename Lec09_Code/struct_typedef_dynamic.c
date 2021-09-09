#include <stdio.h>
#include <stdlib.h>

typedef struct{
	
	int int_data;
	double double_data;
	
} simple;

int main(){
	
	/* Must use struct keyword since we do not reserve compiler space */
	simple* example_struct = ( simple* )malloc( sizeof( simple ) );

	/* De-reference and assign data values */
	example_struct->int_data = 1;
	example_struct->double_data = -13.4;
	
	fprintf( stdout, "%p %p\n", &example_struct, example_struct );
	fprintf( stdout, "%d %p\n", example_struct->int_data, &(example_struct->int_data) );
	fprintf( stdout, "%lf %p\n", example_struct->double_data, &(example_struct->double_data) );
	
	/* Free dynamically allocated memory */
	free( example_struct );
	
	return 0;
}

