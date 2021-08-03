#include <stdio.h>
#include <stdlib.h>

int main( void ){


	char hello[] = "Hello, World\n";

	fprintf( stdout, "%p %p %s", &hello, (void*)hello, hello );

	long unsigned int iter;
	for( iter = 0; hello[iter] != '\0'; ++iter ){

		fprintf( stdout, "%c %p\n", hello[iter], &hello[iter] );

	}

	return 0;

}



