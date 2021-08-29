#include <stdio.h>
#include <stdlib.h>

int main( void ){


	char hello[] = "Hello, World\n";

	char* hello_2 = "Hello, World\n";

	fprintf( stdout, "hello  : %p %p %s", &hello, (void*)hello, hello );

	fprintf( stdout, "%lu\n", sizeof( hello ) );

	fprintf( stdout, "hello_2: %p %p %s", &hello_2, (void *)hello_2, hello_2 );

	fprintf( stdout, "%lu\n", sizeof( hello_2 ) );

	return 0;

}



