#include <stdio.h>
#include <stdlib.h>

void print_hello( void* reference, long unsigned int size ){
	
	long unsigned int iter;
	for( iter = 0; iter < size; ++iter ){
		
		fprintf( stdout, "%c %p\n", *( (char *)reference ), reference );
		
		reference += sizeof(char);
		
	}
	
}

int main(void){
	
	/* Deliberate logic error to show students importance of data types */
	long unsigned int size = 13 * sizeof(char);

	void* hello = malloc( size );
	void* reference = hello;

	fprintf( stdout, "Working Memory: %p\n", &hello );
	fprintf( stdout, "Long-term Memory: %p\n", hello ); 
	
	*( (char *) reference) = 0x48;
	reference += sizeof(char);

	*( (char *) reference) = 101;
	reference += sizeof(char);

	*( (char *) reference) = 0x6c;
	reference += sizeof(char);
	
	*( (char *) reference) = 108;
	reference += sizeof(char);

	*( (char *) reference) = 0x6f;
	reference += sizeof(char);
	
	*( (char *) reference) = 0x2c;
	reference += sizeof(char);
	
	*( (char *) reference) = 32;
	reference += sizeof(char);

	*( (char *) reference) = 87;
	reference += sizeof(char);

	*( (char *) reference) = 0x6f;
	reference += sizeof(char);

	*( (char *) reference) = 114;
	reference += sizeof(char);

	*( (char *) reference) = 0x6c;
	reference += sizeof(char);
	
	*( (char *) reference) = 100;
	reference += sizeof(char);
	
	*( (char *) reference) = 0x0a;
	reference += sizeof(char);
	
	/* Reset reference */
	reference = hello;
	
	/* Print the array */
	print_hello( reference, 20 );

	free( hello );
	
	return 0;
}
