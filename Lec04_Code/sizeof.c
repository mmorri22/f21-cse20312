#include <stdio.h>
#include <stdlib.h>

int main( void ){

	int* int_array = (int *)malloc( 10 * sizeof(int) );

	char* char_array = (char *)malloc( 15 * sizeof(char) );

	fprintf( stdout, "%lu\n", sizeof(int_array) );

	fprintf( stdout, "%lu\n", sizeof(char_array) );

	free( int_array );
	free( char_array );

	return 0;

}
