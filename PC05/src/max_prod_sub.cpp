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

int max_prod_sub( VECTOR<int>& theArray ) {
	
	// Your work goes here
	
}


int main( const int argc, const char* argv[] ){
	
	VECTOR<int> the_array;
	
	for( int iter = 1; iter < argc; ++iter ){
		
		int temp = atoi( argv[iter] );
		
		the_array.push_back( temp );
		
	}	
	
	printArray(the_array);
	COUT << ENDL;
	COUT << "Max Product Subarray Solution = " << max_prod_sub(the_array) << ENDL;
	
	return EXIT_SUCCESS;
}

