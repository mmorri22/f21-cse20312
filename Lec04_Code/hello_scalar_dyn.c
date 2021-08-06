#include <stdio.h>
#include <stdlib.h>

int main( void ){


	char hello_stat[] = "Hello, World\n";

	char* hello_dyn = "Hello, World\n";

	fprintf( stdout, "%p %p %s", &hello_stat, (void*)hello_stat, hello_stat );

	fprintf( stdout, "%lu\n", sizeof(hello_stat) );

	fprintf( stdout, "%p %p %s", &hello_dyn, (void*)hello_dyn, hello_dyn );

	fprintf( stdout, "%lu\n", sizeof(hello_dyn) );

	return 0;

}



