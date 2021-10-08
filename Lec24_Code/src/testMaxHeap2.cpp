#include "../inc/MaxHeap2.h" 

#include <iostream>
#define COUT std::cout 
#define ENDL std::endl

template< class T >
void pushAndPrint( MaxHeap<T>& theHeap, T theElem ){
	
	// Push the element
	theHeap.push( theElem );
	
	// Print the result
	COUT << "Pushing " << theElem << ": " << theHeap << ENDL;
	
}

int main() {
	
	// Create a MaxHeap with a Default Constructor
	MaxHeap< int > heap1;
	
	// Push and Print 5 elements 
	COUT << "Testing heap1..." << ENDL;
	pushAndPrint( heap1, 33 );
	pushAndPrint( heap1, 21 );
	pushAndPrint( heap1, 81 );
	pushAndPrint( heap1, 27 );
	pushAndPrint( heap1, 1 );
	pushAndPrint( heap1, 7 );
	pushAndPrint( heap1, 44 );	
	
	// Create a Max Heap with an overloaded Constructor
	COUT << "\nTesting heap2..." << ENDL;
	MaxHeap< char > heap2;
	
	pushAndPrint( heap2, 'A' );
	pushAndPrint( heap2, 'B' );
	pushAndPrint( heap2, 'C' );
	pushAndPrint( heap2, 'Z' );
	pushAndPrint( heap2, 'Y' );
	pushAndPrint( heap2, 'X' );
	pushAndPrint( heap2, 'M' );	
	
	return 0;
	
}