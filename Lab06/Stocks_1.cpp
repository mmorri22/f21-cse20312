#include <iostream>
#include <vector>

#define COUT std::cout
#define ENDL std::endl
#define VECTOR std::vector

void printArray(const VECTOR<int>& stocks){
	
	COUT << "Input: [";
	
	for(long unsigned int iter = 0; iter < stocks.size(); iter++){
		
		COUT << stocks.at(iter);
		
		if( iter < stocks.size() - 1){
			
			COUT << ",";
		}
		
	}
	
	COUT << "]" << ENDL;
	
}


void maxProfit(const VECTOR<int>& stocks){
	
	long unsigned int minimumLoc = 0; 
	int minumumVal = stocks.at(0); 
	
	long unsigned int nextLocation = stocks.size() + 1;
	int nextLargest = -1;	// Smallest Value
	
	for(long unsigned int iter = 0; iter < stocks.size(); iter++){

		if( stocks.at(iter) < minumumVal ){
			
			minimumLoc = iter;
			minumumVal = stocks.at(iter);
			
			// The largest should NOT be before the minimum location
			nextLocation = iter;
			nextLargest = stocks.at(iter);
		}
		
		// If the next location is not the smallest
		// AND if the value is bigger tha
		else if (stocks.at(iter) > nextLargest){
			
			nextLocation = iter;
			nextLargest = stocks.at(iter);
			
		}

	}
	
	// Print the output stock 
	
	COUT << "Stock: " << nextLargest - minumumVal << ENDL; 
	
	// If minimumLoc == nextLocation, then we did not find a good stock
	if( minimumLoc == nextLocation ){
		
		COUT << "Explanation: In this case, no transaction is done, i.e. max profit = 0." << ENDL;
		
	}
	
	else{
		
		/* Add 1 to translate from C++ 0 base to human-based day 1 */
		COUT << "Explanation: Sell at " << minimumLoc + 1 << " when stock is " << minumumVal << ENDL;
		COUT << "             Buy at " << nextLocation + 1 << " when stock is " << nextLargest << ENDL;
		
	}

}


int main( const int argc, const char* argv[] ){
	
	VECTOR<int> stocks;
	
	for( int iter = 1; iter < argc; ++iter ){
		
		int temp = atoi( argv[iter] );
		
		stocks.push_back( temp );
	}
	
	printArray(stocks);
	
	maxProfit(stocks);
	
	return 0;
}