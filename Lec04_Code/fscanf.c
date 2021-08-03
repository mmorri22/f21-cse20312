#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main( void ){

	int the_int;
	float the_float;
	long unsigned int the_lui;
	char* the_string = (char *)malloc( 25 * sizeof(char) );

	fscanf( stdin, "%d %f %ld %s", &the_int, &the_float, &the_lui, the_string );

	fprintf( stdout, "%d %f %ld %s\n", the_int, the_float, the_lui, the_string );

	return 0;

}
