#include <stdio.h>

int main( int argc, char** argv ){

	if( argc != 3 ){

		fprintf( stderr, "Worng!\n" );

		exit( -1 );
	}


	fprintf( stdout, "Hello, World\n" );

	return 0;

}
