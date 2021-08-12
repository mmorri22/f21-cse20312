#include <stdio.h>
#include <stdlib.h>

int main(void){
	
	/* Logic error fixed and long unsigned int properly used */
	long unsigned int size = 13 * sizeof(char);

	void* hello = malloc( size );

	fprintf( stdout, "Working Memory: %p\n", &hello );
	fprintf( stdout, "Long-term Memory: %p\n", hello );

	*( (char *)(hello + 2*sizeof(char)) ) = 'l';

	fprintf( stdout, "Address of third char: %p\n", hello + 2*sizeof(char) );
	fprintf( stdout, "Address of third char with context: %p\n", (char *)(hello + 2*sizeof(char)) );	

	fprintf( stdout, "De-referenced third char: %c\n", *( (char *)(hello + 2*sizeof(char)) ) );
	// fprintf(stdout, "Hello, World\n");
	
	free( hello );
	
	return 0;
}
