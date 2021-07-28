#include <stdio.h>
#include <stdlib.h>

int main( void ){

	long unsigned int size = 13 * sizeof(char);

	void* hello = malloc( size );

	fprintf( stdout, "Local register address is %p\n", &hello);
	fprintf( stdout, "Location in Long-term memory is %p\n", hello);
	//	fprintf(stdout, "Hello, World\n");

	*( (char *)(hello + 2*sizeof(char)) ) = 'l';

	free( hello );

	return 0;
}
