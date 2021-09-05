#include <stdio.h>
#include <stdlib.h>

int main ( void ){
	
	long unsigned int hello_size = 13;
	void* hello = malloc( hello_size * sizeof(char) );
	void* reference = hello;
	
	*( (char *)( hello + 0*sizeof(char) ) ) = 0x48;
	*( (char *)( hello + 1*sizeof(char) ) ) = 101;
	*( (char *)( hello + 2*sizeof(char) ) ) = 0x6c;
	*( (char *)( hello + 3*sizeof(char) ) ) = 108;
	*( (char *)( hello + 4*sizeof(char) ) ) = 0x6f;
	*( (char *)( hello + 5*sizeof(char) ) ) = 44;
	*( (char *)( hello + 6*sizeof(char) ) ) = 0x20;
	*( (char *)( hello + 7*sizeof(char) ) ) = 87;
	*( (char *)( hello + 8*sizeof(char) ) ) = 111;
	*( (char *)( hello + 9*sizeof(char) ) ) = 0x72;
	*( (char *)( hello + 10*sizeof(char) ) ) = 0x6c;
	*( (char *)( hello + 11*sizeof(char) ) ) = 100;
	*( (char *)( hello + 12*sizeof(char) ) ) = 0xa;
	
	long unsigned int iter;
	for( iter = 0; iter < hello_size; ++iter ){
		
		fprintf( stdout, "%c %p\n", *( (char *)reference ), 
			(char *)reference );
			
		reference += sizeof(char);
	}
	
	/* fprintf( stdout, "%c %p\n",
		*( (char *)( hello + 0*sizeof(char) ) ),
		(char *)( hello + 0*sizeof(char) ) ); */
	
	
	// free( hello );
	reference = hello;
	// free( reference + 1 );
	// free( hello );
	
	return 0;
	
}