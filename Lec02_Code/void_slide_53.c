#include <stdio.h>
#include <stdlib.h>

int main(void){
	
	/* Deliberate logic error to show students importance of data types */
	int size = -1 * 13 * sizeof(char);

	void* hello = malloc( size );

	fprintf( stdout, "Working Memory: %p\n", &hello );
	fprintf( stdout, "Long-term Memory: %p\n", hello ); 
	
	free( hello );
	
	return 0;
}
