#ifndef MAXHEAP1_H
#define MAXHEAP1_H

#include <vector>
#include <iostream>

#define VECTOR std::vector

template< class T >
class MaxHeap{
	
	private:
	
		VECTOR<T> heapArray;	// Dynamic Array to Maintain the Heap
		
	public:
	
		// Default Constructor
		MaxHeap() : heapArray() {}
		
		void push( const T& element ){
			
			heapArray.push_back( element );
			
			if( heapArray.size() > 1 ){
				
				// Get the current location of the last element 
				long unsigned int curr_loc = heapArray.size() - 1;
				
				// Use the parent rule mentioned in the slides  
				while( true ){
					
					long unsigned int parent;
					
					if( curr_loc % 2 == 0 ){
						parent = curr_loc / 2 - 1;
					}
					else{
						parent = curr_loc / 2;
					}
						
					if( heapArray.at( curr_loc ) > heapArray.at( parent ) ){
						
						T temp = heapArray.at( parent );
						heapArray.at( parent ) = heapArray.at( curr_loc );
						heapArray.at( curr_loc ) = temp;
						
						curr_loc = parent;
					}
					else
						break;
					
					if( curr_loc == 0 )
						break;
						
				}
			}
		}
		
		
		// Overloaded friend operator<<
		friend std::ostream& operator<<( std::ostream& output, const MaxHeap<T>& theHeap ){
			
			for(unsigned int iter = 0; iter < theHeap.heapArray.size(); iter++ ){
				
				output << theHeap.heapArray[ iter ] << " ";
			}
			
			return output;
		}
};

#endif