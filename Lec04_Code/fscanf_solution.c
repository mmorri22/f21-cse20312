#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main( void ){

	int the_int;
	float the_float;
	char* the_string = (char *)malloc( 25 * sizeof(char) );
	long unsigned int the_lui;

	/* Finish the code to put them in order */
	fscanf( stdin, "%d %f %s %lu", &the_int, &the_float, the_string, &the_lui );

	fprintf( stdout, "%d %f %s %lu\n", the_int, the_float, the_string, the_lui  );

	return 0;

}
