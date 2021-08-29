#include <stdio.h>
#include <stdlib.h>

int main( void ){

	// fprintf( stdout, "Hello, World %p\n", stdout );
	int size = -13 * sizeof( char );
	void* hello = malloc( size );

	fprintf( stdout, "%p %p\n", &hello, hello );

	free( hello );

	return 0;
}
