#include <stdio.h>
#include <stdlib.h>

void print_inputs( int argc, char* argv[] ){

	fprintf( stdout, "argc = %d\n", argc );

	int iter;
	for( iter = 0; iter < argc; ++iter ){

		fprintf( stdout, "argv[%d] = %s\tat %p\n", 
				iter, argv[iter], &argv[iter] );

	}

}

int main( int argc, char* argv[] ){

	fprintf( stdout, "Initial argc: %d\n", argc );

	print_inputs( argc, argv );

	argc -= 1;
	print_inputs( argc, argv );
	
	// argc += 40 will NOT segfault. Information to the screen
	argc += 40;

	// But uncommenting 41 will segfault because the NULL after the information
	argc += 41;

	print_inputs( argc, argv );

	return 0;
}
