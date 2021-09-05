#include <stdio.h>
#include <stdlib.h>

int main( const int argc, const char* argv[] ){

	FILE* the_input = fopen( "test.txt", "r" );

	// Remember Dr. Morrison's Golden Rule of Pointers
	if( the_input == NULL ){
		fprintf( stderr, "When NULL, the_input = %p\n", the_input );
		fprintf( stderr, "stderr is at %p\n", stderr );
		fprintf( stdout, "stdout is at %p\n", stdout );

		FILE* the_output = fopen( "test.txt", "w");

		fprintf( stdout, "After w, the_output is now at %p\n", the_output );

		int iter;
		for( iter = 0; iter < argc; ++iter ){

			fprintf( the_output, "%p, %s\n", &argv[iter], argv[iter] );

		}

		fclose( the_output );

		exit( EXIT_FAILURE );
	}

	fclose( the_input );

	return EXIT_SUCCESS;

}
