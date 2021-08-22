#include <stdio.h>
#include <stdlib.h>

struct simple{
	
	int int_data;
	double double_data;
	
};

int main(){
	
	/* Must use struct keyword since we do not reserve compiler space */
	struct simple example_struct = { 1, -13.4 };
	
	fprintf( stdout, "%d %lf\n", example_struct.int_data, example_struct.double_data );
	
	return 0;
}