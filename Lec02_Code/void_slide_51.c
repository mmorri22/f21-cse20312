#include <stdio.h>
#include <stdlib.h>

int main(void){

	int size = 13 * sizeof(char);

	void* hello = malloc( size );

	fprintf( stdout, "Working Memory: %p\n", &hello );
	fprintf( stdout, "Long-term Memory: %p\n", hello );

	// fprintf(stdout, "Hello, World\n");
	
	free( hello );
	
	return 0;
}
