#include <vector>
#include <iostream>

#define COUT std::cout
#define ENDL std::endl
#define VECTOR std::vector

void printArray( const VECTOR<int>& the_array ){
	
	COUT << "[";
	
	for(unsigned int iter = 0; iter < the_array.size(); iter++){
		
		COUT << the_array.at(iter);
		
		if( iter < the_array.size() - 1 ){
			
			COUT << ",";
		}
	}
	
	COUT << "]";
	
}


VECTOR<int> solveArray( const VECTOR<int>& the_array ){
	
	if( the_array.size() == 0 ){
		
		COUT << "Cannot process 0 length vector" << ENDL;
		
		exit( EXIT_FAILURE );
		
	}

	// Create an array to store the solution that is the same size as the_array
	
	
	// Set solution's initial value equal to 1
	
	
	// Forward Iteration starting at 1 and go through all the elements
	
		
		// The solution at the iter value is the solution at iter - 1 times 
		// the_array at iter - 1 
		
	
	
	
	// Create a temp int variable to go backward equal to 1
	
	
	// Reverse Iteration starting at the_array.size() -1 and go through all the elements
	// Note: Be sure to do iter > 0, or else you will get an infinite loop!
	
		
		// Multiple the temp variable *= the_array at iter's value
		
		
		// Multiple the solution at iter - 1 by the temp variable
		
		
	
	
	// Return the solution vector
	
	
}

void runSolution( const VECTOR<int>& the_array ) {
	
	// Print the Initial Input
	COUT << "Input : ";
	printArray( the_array );
	COUT << "\n";

	// Run the Solution and Print the Output
	COUT << "Output: ";
	printArray( solveArray( the_array ) );
	COUT << ENDL << ENDL;	
	
}



int main( const int argc, const char* argv[] ){
	
	VECTOR<int> the_array;
	
	for( int iter = 1; iter < argc; ++iter ){
		
		int temp = atoi( argv[iter] );
		
		the_array.push_back( temp );
	}
	
	runSolution(the_array);
	
	return EXIT_SUCCESS;
}
