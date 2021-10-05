#include <vector>
#include <iostream>

#define COUT std::cout
#define ENDL std::endl
#define VECTOR std::vector

void printArray( VECTOR<int>& theArray ){
	
	COUT << "[";
	
	for(long unsigned int iter = 0; iter < theArray.size(); iter++){
		
		COUT << theArray.at(iter);
		
		if( iter < theArray.size() - 1 ){
			
			COUT << ",";
		}
	}
	
	COUT << "]";
	
}

int maxSubArrayDyn( VECTOR<int>& theArray ) {
	
	int currMax = theArray.at(0);
	int globalMax = theArray.at(0);
		
	for(unsigned int iter = 1; iter < theArray.size(); iter++){
		
		// Get the intermediate sum
		int sum = theArray.at(iter) + currMax;
		
		// Select the current Max
		// Using Ternary Conditional
		currMax = (sum > theArray.at(iter)) ? sum : theArray.at(iter);
		
		// Update the global max 
		// Using Ternary Conditional
		globalMax = ( currMax > globalMax ) ? currMax : globalMax;
			
	}
	
	return globalMax;
	
}


int main( const int argc, const char* argv[] ){
	
	VECTOR<int> the_array;
	
	for( int iter = 1; iter < argc; ++iter ){
		
		int temp = atoi( argv[iter] );
		
		the_array.push_back( temp );
		
	}	
	
	printArray(the_array);
	COUT << ENDL;
	COUT << "Max Size = " << maxSubArrayDyn(the_array) << ENDL;
	
	return EXIT_SUCCESS;
}

