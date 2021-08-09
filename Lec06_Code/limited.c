#include <stdio.h>

int main( void ){

	long unsigned int the_value = 100000;

	while( the_value >= 0 ){
	
		fprintf( stdout, "%lu\n", the_value );

		--the_value;
	}

	return 0;
}
