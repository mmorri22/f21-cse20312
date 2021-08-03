#include <stdio.h>
#include <string.h>

int main( void ){

	char* hello = "Hello, World";

	long unsigned int size = sizeof(hello);
	long unsigned int size_2 = strlen( hello );

	fprintf( stdout, "%s %lu %lu\n", hello, size, size_2 );

	return 0;

}
