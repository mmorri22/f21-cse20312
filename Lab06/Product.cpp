#include "../classes/DynArr.h"
#include <iostream>

#define COUT std::cout
#define ENDL std::endl

void printArray( DynArr<int>& theArray ){
	
	COUT << "[";
	
	for(unsigned int iter = 0; iter < theArray.length(); iter++){
		
		COUT << theArray[iter];
		
		if( iter < theArray.length() - 1 ){
			
			COUT << ",";
		}
	}
	
	COUT << "]";
	
}


DynArr<int> solveArray( DynArr<int>& theArray ){

	// Create an array to store the solution
	DynArr<int> solution( theArray.length() );
	
	// Forward Iteration
	solution[ 0 ] = 1;
	for(unsigned int iter = 1; iter < theArray.length(); iter++){
		
		solution[ iter ] = solution[ iter - 1 ] * theArray[ iter - 1 ];
	
	}
	
	// Create a reverse value for the multiplication
	int tempBackward = 1;
	for(unsigned int iter = theArray.length() - 1; iter > 0; iter--){
		
		tempBackward *= theArray[iter];
		
		solution[iter - 1] *= tempBackward;
		
	}
	
	return solution;
	
}

void runSolution( DynArr<int>& theArray ) {
	
	// Print the Initial Input
	COUT << "Input : ";
	printArray( theArray );
	COUT << "\n";

	// Run the Solution and Print the Output
	COUT << "Output: ";
	DynArr<int> solution = solveArray( theArray );
	printArray( solution );
	COUT << ENDL << ENDL;	
	
}



int main(){
	
	int numVals = 5;
	
	// Create first array
	DynArr<int> array1( numVals );
	
	array1[0] = 1;
	array1[1] = 2;
	array1[2] = 3;
	array1[3] = 4;
	array1[4] = 5;
	
	runSolution(array1);
	
	// Create second array
	
	DynArr<int> array2( numVals - 1);
	
	array2[0] = 1;
	array2[1] = 2;
	array2[2] = 3;
	array2[3] = 4;
	
	runSolution(array2);
	
	// Create third array 
	
	DynArr<int> array3( numVals + 1);
	
	array3[0] = 22;
	array3[1] = 18;
	array3[2] = 5;
	array3[3] = 33;
	array3[4] = 9;
	array3[5] = 101;
	
	runSolution(array3);
	
	return 0;
}
