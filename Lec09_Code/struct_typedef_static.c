#include <stdio.h>
#include <stdlib.h>

typedef struct simple{
	
	int int_data;
	double double_data;
	
} simple;

int main(){
	
	/* No longer need struct keyword since we reserve compiler space */
	simple example_struct = { 1, -13.4 };
	
	fprintf( stdout, "%d %lf\n", example_struct.int_data, example_struct.double_data );
	
	return 0;
}