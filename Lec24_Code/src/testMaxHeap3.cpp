#include "../inc/MaxHeap.h" 

#include <iostream>
#define COUT std::cout 
#define ENDL std::endl

template< class T >
void popAndPrint( MaxHeap<T>& theHeap ){
	
	// Print the result if the Heap is not empty
	if( !theHeap.empty() ){
		
		// Print the result
		COUT << "Popping " << theHeap.top() << ": ";
		
		// Push the element
		theHeap.pop( );
		
		COUT << theHeap << ENDL;
	}
	
}

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
	
	// Push and Print 9 elements 
	COUT << "Testing heap1..." << ENDL;
	pushAndPrint( heap1, 33 );
	pushAndPrint( heap1, 21 );
	pushAndPrint( heap1, 81 );
	pushAndPrint( heap1, 27 );
	pushAndPrint( heap1, 1 );
	pushAndPrint( heap1, 7 );
	pushAndPrint( heap1, 44 );
	pushAndPrint( heap1, 0 );	
	pushAndPrint( heap1, 99 );	
	
	// Pop all 9 elements
	popAndPrint( heap1 );	popAndPrint( heap1 );	popAndPrint( heap1 );
	popAndPrint( heap1 );	popAndPrint( heap1 );	popAndPrint( heap1 );
	popAndPrint( heap1 );	popAndPrint( heap1 );	popAndPrint( heap1 );
	
	// Test for a bab pop 
	popAndPrint( heap1 );
	
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
	
	// Pop all 7 elements 
	popAndPrint( heap2 );	popAndPrint( heap2 );	popAndPrint( heap2 );
	popAndPrint( heap2 );	popAndPrint( heap2 );	popAndPrint( heap2 );
	popAndPrint( heap2 );
	
	return 0;
	
}
