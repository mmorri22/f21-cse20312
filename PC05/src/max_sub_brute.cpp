#include <vector>
#include <iostream>
#include <cstdlib>

#define COUT std::cout
#define ENDL std::endl
#define VECTOR std::vector

void printArray( VECTOR<int>& the_array ){
	
	COUT << "[";
	
	for(unsigned int iter = 0; iter < the_array.size(); iter++){
		
		COUT << the_array.at(iter);
		
		if( iter < the_array.size() - 1 ){
			
			COUT << ",";
		}
	}
	
	COUT << "]";
	
}

int maxSubArrayBrute( VECTOR<int>& the_array ) {
	
	int maxSize = -2147483648;		// Largest Negative 32 bit integer
		
	for(unsigned int iter = 0; iter < the_array.size(); iter++){
		
		int sub_size = 0;

		for(unsigned int jter = iter; jter < the_array.size(); jter++){
		
			sub_size += the_array.at(jter);
			
			if(sub_size > maxSize){
				
				maxSize = sub_size;
			}
		
		}
		
	}
	
	return maxSize;
	
}


int main( const int argc, const char* argv[] ){
	
	VECTOR<int> the_array;
	
	for( int iter = 1; iter < argc; ++iter ){
		
		int temp = atoi( argv[iter] );
		
		the_array.push_back( temp );
		
	}	
	
	printArray(the_array);
	COUT << ENDL;
	COUT << "Max Size = " << maxSubArrayBrute(the_array) << ENDL;
	
	return EXIT_SUCCESS;
}
