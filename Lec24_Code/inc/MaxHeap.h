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
		
		T top() const{
			
			return heapArray.at( 0 );
			
		}
		
		bool empty() const{
			
			return heapArray.empty();
			
		}
		
		void pop(){
			
			if( heapArray.empty() ){
				
				// Do nothing
				return;
			}
			
			// If there is only one element, delete it 
			if( heapArray.size() == 1 ){
				
				heapArray.pop_back();

			}
			
			else{
				
				// Copy the back to the front
				heapArray.at( 0 ) = heapArray.back();
				
				// Delete the element at the end 
				heapArray.pop_back();
				
				// Use the child rule mentioned in the slides  
				long unsigned int curr_loc = 0;
				
				while( true ){ 
				
					long unsigned int left_child = 2 * curr_loc + 1;
					long unsigned int right_child = 2 * curr_loc + 2;
					
					// Condition for both children existing 
					if( right_child < heapArray.size() ){
						
						// If the curr_loc is less than left or right
						if( heapArray.at( curr_loc ) < heapArray.at( left_child ) ||
							heapArray.at( curr_loc ) < heapArray.at( right_child ) ){
							
							// Get the swap location 
							long unsigned int swap_loc = ( heapArray.at( left_child ) > heapArray.at( right_child ) ) ?
								left_child : right_child ;
							
							// Swap the curr_loc and swap_loc
							T temp = heapArray.at( curr_loc );
							heapArray.at( curr_loc ) = heapArray.at( swap_loc );
							heapArray.at( swap_loc ) = temp;
							
							curr_loc = swap_loc;							
						}
						else{
							break;
						}
						
					}
					// Only left child 
					else if( left_child < heapArray.size() ){
						
						if( heapArray.at( curr_loc ) < heapArray.at( left_child ) ){
							
							// Swap the curr_loc and left_child
							T temp = heapArray.at( curr_loc );
							heapArray.at( curr_loc ) = heapArray.at( left_child );
							heapArray.at( left_child ) = temp;	
							
							curr_loc = left_child;
						}
						else{
							break;
						}
					}
					else{
						break;
					}
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