#include <stdio.h>
#include <stdlib.h>

int main( void ){

	// EXIT_FAILURE is in stdlib.h
	int value = EXIT_FAILURE;

	// Since value = 1, we will exit
	if( value == EXIT_FAILURE ){
	
		fprintf( stderr, "Error Message: %d\n", EXIT_FAILURE );
		fprintf( stderr, "Success Msg! : %d\n", EXIT_SUCCESS );
	
		exit( EXIT_FAILURE );
	}

	return 0;
}
