#include <stdio.h>
#include <stdlib.h>

int main( void ){


	char hello[] = "Hello, World\n";

	fprintf( stdout, "%p %p %s", &hello, (void*)hello, hello );

	fprintf( stdout, "%lu\n", sizeof( hello ) );

	return 0;

}



