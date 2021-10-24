#ifndef TWOSUMS_H
#define TWOSUMS_H

#include <iostream>
#include <vector>
#include <unordered_map>

#define COUT std::cout
#define ENDL std::endl
#define VECTOR std::vector

void TwoSums( std::vector<int>& theValue, int target ){
	
	COUT << "Target is " << target << ", Array = ";
	
	for( long unsigned int iter = 0; iter < theValue.size(); iter++ ){
		
		COUT << theValue.at(iter) << " ";
	}
	
	COUT << ENDL;
	
	std::unordered_map<int, long unsigned int> theHash;
	
	for( long unsigned int iter = 0; iter < theValue.size(); iter++ ){
		
		theHash.insert( { theValue.at(iter), iter } );
		
	}
	
	
	for( long unsigned int iter = 0; iter < theValue.size(); iter++ ){
		
		if( theHash.count( target - theValue.at(iter) ) != 0 ){
			
			COUT << "Sum found at elements [" << iter << ", " << theHash[ target - theValue.at(iter) ] << "]" << ENDL;
			
			// May assume exactly one solution, so return
			return;
		}
		
	}
	
	// If we get here, there is no solution
	COUT << "No pair adds to " << target << ENDL;
}


VECTOR< VECTOR<int> > ThreeSums( std::vector<int>& theValues ){
	
	VECTOR< VECTOR<int> > results;

	for (int i = 0; i < (int)theValues.size(); ++i) {
		
		// Never let i refer to the same value twice to avoid duplicates.
		if (i != 0 && theValues[i] == theValues[i - 1]) 
			continue;
		
		int j = i + 1;
		int k = (int)theValues.size() - 1;
		
		while (j < k) {
			if (theValues[i] + theValues[j] + theValues[k] == 0) {
				results.push_back({theValues[i], theValues[j], theValues[k]});
				++j;
				
				// Never let j refer to the same value twice (in results) to avoid duplicates
				while (j < k && theValues[j] == theValues[j-1]) 
					++j;
			} 
			else if (theValues[i] + theValues[j] + theValues[k] < 0) {
				++j;
			} 
			else {
				--k;
			}
		}
	}
	
	return results;

}


void printVecVec( const VECTOR< VECTOR<int> >& results ){
	

	for( long unsigned int iter = 0; iter < results.size(); iter++ ){
		
		for( long unsigned int jter = 0; jter < results.at(iter).size(); jter++ ){
			
			COUT << results.at(iter).at(jter) << " ";
		}
		COUT << ENDL;
	}
	
}


#endif