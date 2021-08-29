#include <stdio.h>
#include <stdlib.h>

int main(void){
	
	/* Deliberate logic error to show students importance of data types */
	long unsigned int size = 13 * sizeof(char);

	void* hello = malloc( size );

	*( (char *)( hello + 2*sizeof(char) ) ) = 'l';

	fprintf( stdout, "Working Memory: %p\n", &hello );
	fprintf( stdout, "Long-term Memory: %p\n", (char *)( hello + 2*sizeof(char) ) );
	fprintf( stdout, "char = %x\n", *( (char *)( hello + 2*sizeof(char) ) ) ); 
	
	free( hello );
	
	return 0;
}
