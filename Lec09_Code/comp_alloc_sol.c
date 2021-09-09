#include <stdio.h>
#include <stdlib.h>

typedef struct simple{
	
	int the_int;
	double the_double;
	float the_float;
	
} simple;


int main(){
	
	simple static_struct = { -100, 22.7, (float)19.2 };
	
	fprintf( stdout, "&static_struct = %p\n", &static_struct );
	fprintf( stdout, "&(static_struct.the_int) = %p\n", &(static_struct.the_int) );
	fprintf( stdout, "&(static_struct.the_double) = %p\n", &(static_struct.the_double) );
	fprintf( stdout, "&(static_struct.the_float) = %p\n", &(static_struct.the_float) );
	
	void* void_struct = malloc( sizeof(int) + sizeof(double) + sizeof(float) );
	void* reference = void_struct;
	
	*( (int *)reference ) = 13;
	reference += sizeof(int);
	*( (double *)reference ) = -99.9;
	reference += sizeof(double);	
	*( (float *)reference ) = (float)7.7;
	
	reference = void_struct;
	
	fprintf( stdout, "%p\n", void_struct);
	fprintf( stdout, "%p %d\n", reference, *( (int *)reference ) );
	reference += sizeof(int);
	fprintf( stdout, "%p %lf\n", reference, *( (double *)reference ));
	reference += sizeof(double);
	fprintf( stdout, "%p %f\n", reference, *( (float *)reference ));
	

	simple* dyn_struct = (simple *)malloc( sizeof( simple ) );
	dyn_struct->the_int = 22;
	dyn_struct->the_double = 18.22;
	dyn_struct->the_float = (float)-17.36;
	
	fprintf( stdout, "dyn_struct = %p\n", dyn_struct );
	fprintf( stdout, "&(dyn_struct->the_int) = %p\n", &(dyn_struct->the_int) );
	fprintf( stdout, "&(dyn_struct->the_double) = %p\n", &(dyn_struct->the_double) );
	fprintf( stdout, "&(dyn_struct->the_float) = %p\n", &(dyn_struct->the_float) );
	
	// Free at the end to get different results
	free( void_struct );
	free( dyn_struct );
	
	return 0;
}