#include <stdio.h>
#include <stdlib.h>

int main(void){
	
	/* Deliberate logic error to show students importance of data types */
	long unsigned int size = 13 * sizeof(char);

	void* hello = malloc( size );

	fprintf( stdout, "Working Memory: %p\n", &hello );
	fprintf( stdout, "Long-term Memory: %p\n", hello ); 

	fprintf( stdout, "Address of third char: %p\n", (char *)( hello + 2*sizeof(char) ) );

	*( (char *)( hello + 2*sizeof(char) ) ) = 'l';	

	fprintf( stdout, "Third char: %c\n", *( (char *)( hello + 2*sizeof(char) ) ) );

	free( hello );
	
	return 0;
}
