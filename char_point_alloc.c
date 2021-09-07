#include <stdio.h>
#include <stdlib.h>

#define STRINGS 8
#define LENGTH 25

// Step 2, write a function alloc_array that takes in a char**
void alloc_array( char** str_array ){

	// Step 2-1 Loop through the STRINGS
	long unsigned int iter;
	for( iter = 0; iter < STRINGS; ++iter ){
		
		// Allocate a char* to the the char pointer ([] permitted)
		// Use malloc a char* where each one is of LENGTH and size of char 
		str_array[iter] = (char *)malloc( LENGTH * sizeof(char) );		

	}

}

// Step 4, write a function free_array that takes in a char**
void free_array( char** str_array ){	

	// Step 4-1 Loop through the STRINGS
	long unsigned int iter;
	for( iter = 0; iter < STRINGS; ++iter ){		
		// Allocate a char* to the the char pointer ([] permitted)
		
		free( str_array[iter] );
	}
}

int main( void ){
	
	// Step 1 - Allocate a char** of length STRINGS 
	char** str_array = (char**)malloc( STRINGS * sizeof(char *) );	
	
	// Step 3 - Call the alloc_array you created in Step 2
	alloc_array( str_array );
	
	// Step 5 - Call the free_array function you created in Step 4
	free_array( str_array );
	
	// Step 6 - Free the char** 
	free( str_array );
	
	return 0;
}
