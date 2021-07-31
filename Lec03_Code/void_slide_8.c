#include <stdio.h>
#include <stdlib.h>

int main(void){
	
	/* Deliberate logic error to show students importance of data types */
	int size = 13 * sizeof(char);

	void* hello = malloc( size );

	fprintf( stdout, "Working Memory: %p\n", &hello );
	fprintf( stdout, "Long-term Memory: %p\n", hello );

	/* Deliberate compiler error here to emphasize DATA vs STRUCTURE */
	fprintf( stdout, "Address of third char: %c\n", hello + 2*sizeof(char) );
	// fprintf(stdout, "Hello, World\n");
	
	free( hello );
	
	return 0;
}
