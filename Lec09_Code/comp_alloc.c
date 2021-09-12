#include <stdio.h>
#include <stdlib.h>

typedef struct simple{
	
	int the_int;
	double the_double;
	float the_float;
	
} simple;

int main(){
	
	simple simple_str = { -14, 22.7, (float)9.2 };
	
	fprintf( stdout, "%p\n", &simple_str );
	fprintf( stdout, "%p\n", &(simple_str.the_int) );
	fprintf( stdout, "%p\n", &(simple_str.the_double) );
	
	simple* simple_dyn = ( simple * )malloc( sizeof(simple) );
	simple_dyn->the_int = 45;
	simple_dyn->the_double = 45.1;
	simple_dyn->the_float = (float)-1.1;
	
	fprintf( stdout, "%p\n", &simple_dyn );
	fprintf( stdout, "%p\n", &(simple_dyn->the_double) );
	fprintf( stdout, "%p\n", &(simple_dyn->the_float) );	
	
	free( simple_dyn );

	// void* the_void = malloc( sizeof(int) + sizeof(double) + sizeof(float) );

	return 0;
}