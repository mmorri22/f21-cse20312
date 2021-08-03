#include <stdio.h>
#include <stdlib.h>

int main( void ){


	char* hello = "Hello, World";

	fprintf( stdout, "%s %p %p\n", hello, &hello, (void*)hello );

	/* Will uncomment in lecture */
	free( hello );

	return 0;

}
