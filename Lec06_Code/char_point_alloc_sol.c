#include <stdio.h>
#include <stdlib.h>

#define STRINGS 8
#define LENGTH 25

void alloc_array( char** the_char_ptr ){
	
	long unsigned int iter;
	for( iter = 0; iter < STRINGS; ++iter ){
		
		the_char_ptr[iter] = (char *)malloc( LENGTH * sizeof( char ) );
		
	}
	
}

void free_array( char** the_char_ptr ){
	
	long unsigned int iter;
	for( iter = 0; iter < STRINGS; ++iter ){
		
		free( the_char_ptr[ iter ] );
		
	}
}

int main( void ){
	
	char** the_char_ptr = (char **)malloc( STRINGS * sizeof( char *) );
	
	alloc_array( the_char_ptr );
	
	free_array( the_char_ptr );
	
	free( the_char_ptr );
	
	return 0;
}