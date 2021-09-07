#include <stdio.h>


int factorial( int num ){

	// Base Case
	if( num == 0 )
		return 1;

	// Recursive Case
	return num * factorial( num - 1 );

}

int main(){

	int value = 4;

	fprintf( stdout, "%d! = %d\n", value, factorial( value ) );

	return 0;
}
