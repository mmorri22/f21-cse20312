#include "min_heap.h" 

#include <iostream>
#include <cstdlib>
#include <vector>
#define COUT std::cout 
#define ENDL std::endl
#define VECTOR std::vector

template< class T >
void findKthLargest( VECTOR<int>* unsorted_vector, min_heap< T >* the_heap, int kTh ){
	
	if( kTh > unsorted_vector->size() ){
		
		COUT << kTh << " exceeds the array length of " << unsorted_vector->size() << ENDL;
		
		return;
	}
	
	for( int iter = 0; iter < kTh; iter++ ){
	
		the_heap->push( unsorted_vector->at( iter ) );
		
	}
	
	for( int iter = kTh; iter < unsorted_vector->size(); iter++ ){
		
		if( unsorted_vector->at( iter ) > the_heap->top() ){
			
			the_heap->pop();
			the_heap->push( unsorted_vector->at( iter ) );
		}
	}
	
	COUT << "Sorry for the bad grammar: The " << kTh << "-th largest element is " << the_heap->top() << ENDL;
}

int main( const int argc, char * argv[] ) {
	
	VECTOR<int>* unsorted_vector = new VECTOR<int>();
	
	// Insert 12 values 
	for( int iter = 1; iter < argc; ++iter ){
		
		unsorted_vector->push_back( atoi( argv[iter] ) );
		
	}
	
	// Create a MinHeap with a Default Constructor
	min_heap< int >* the_heap = new min_heap<int>();
	
	// Solve it for each kth element 
	for( int iter = 1; iter < argc; ++iter ){
		
		
		findKthLargest( unsorted_vector, the_heap, iter );
		
	}

	// Delete dynamically allocated memory
	delete the_heap;
	delete unsorted_vector;
	
	return 0;
	
}
