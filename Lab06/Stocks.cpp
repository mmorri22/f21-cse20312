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
	
	if( stocks.size() == 0 ){
		
		COUT << "No values to calculate" << ENDL;
		
		return;
	}
	
	long unsigned int local_min_loc = 0; 
	long unsigned int global_min_loc = 0; 
	long unsigned int local_max_loc = 0; 
	long unsigned int global_max_loc = 0; 
	
	int local_min_val = stocks.at(0);
	int global_min_val = stocks.at(0);
	int local_max_val = stocks.at(0);
	int global_max_val = stocks.at(0);
	
	/* Remember, access the registers for speed compared to the array on the Heap */
	for(long unsigned int iter = 1; iter < stocks.size(); iter++){
		
		// If the value is less than the global min, update the local min
		if( stocks.at(iter) < global_min_val ){
			
			local_min_loc = iter;
			local_min_val = stocks.at(iter);
			local_max_loc = iter;
			local_max_val = stocks.at(iter);
			
		}
		
		if( stocks.at(iter) > local_max_val ){
			
			local_max_loc = iter;
			local_max_val = stocks.at(iter);
			
		}
		
		// >= so we get the initial updates as well. Ties are fine
		if( local_max_val - local_min_val >= global_max_val - global_min_val ){
			
			// Use registers instead of arrays to improve performance
			global_max_loc = local_max_loc;
			global_max_val = local_max_val;
			global_min_loc = local_min_loc;
			global_min_val = local_min_val;			
			
		}

	}
	
	// Print the output stock 
	
	// If global_max_loc <= global_min_loc, then we did not find a good stock
	if( global_max_loc <= global_min_loc ){
		
		COUT << "Stock: 0" << ENDL;
		COUT << "Explanation: In this case, no transaction is done, i.e. max profit = 0." << ENDL;
		
	}
	
	else{
		COUT << "Stock: " << global_max_val - global_min_val << ENDL; 
		
		/* Add 1 to translate from C++ 0 base to human-based day 1 */
		COUT << "Explanation: Sell at " << global_min_loc + 1 << " when stock is " << global_min_val << ENDL;
		COUT << "             Buy at " << global_max_loc + 1 << " when stock is " << global_max_val << ENDL;
		
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