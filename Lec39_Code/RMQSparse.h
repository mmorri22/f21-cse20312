#ifndef RMQSPARSE_H
#define RMQSPARSE_H

#include <iostream>
#include <cmath> // For log2 in RMQ 

#define COUT std::cout
#define ENDL std::endl 

// Structure to represent a query range 
struct RMQuery 
{ 
    unsigned int left, right; 
	
	RMQuery(unsigned int leftIn, unsigned int rightIn) : left(leftIn), right(rightIn) {}
}; 


template< class T >
class RMQSparse{
	
	private:
	
		long unsigned int arrayLen;	// Length of the Array
		long unsigned int columns;	// Number of columns
		T* arr;						// Initial Array
		unsigned int** lookup;		// Pre-Processed Results
	
	public:
	
		/* Constructor */
		RMQSparse( long unsigned int lengthIn, T arrIn[] ) 
			: arrayLen( lengthIn ), // Set array len = to input length
			  columns( (long unsigned int)log2(arrayLen) + 1 ), // columns = log2(arrayLen) + 1
			  arr ( arrIn ), // arr = arrIn
			  lookup( (unsigned int **)malloc( arrayLen * sizeof(unsigned int *) ) ) {
				
			// Allocate the array for each element
			for( long unsigned int iter = 0; iter < arrayLen; iter++ ){
				
				lookup[iter] = (unsigned int *)malloc( columns * sizeof(unsigned int) );
			}

			// Initialize M for the intervals with length 1 
			for (int i = 0; i < arrayLen; i++) 
				lookup[i][0] = i; 
		  
			// Compute values from smaller to bigger intervals 
			for (int j=1; (1<<j) <= arrayLen; j++) 
			{ 
				// Compute minimum value for all intervals with size 2^j 
				for (int i=0; (i+(1<<j)-1) < arrayLen; i++) 
				{  
					// 
					if (arr[lookup[i][j-1]] < arr[lookup[i + (1<<(j-1))][j-1]]) 
						lookup[i][j] = lookup[i][j-1]; 
					else
						lookup[i][j] = lookup[i + (1 << (j-1))][j-1];       
				} 
			} 
		
		}
		
		T getRMQ( RMQuery theQuery ){
			
			// Determine the column 
			unsigned int j = (unsigned int)log2( theQuery.right - theQuery.left + 1 ); 
		  
			// Get the new left and right values
			unsigned int lookupLeft = lookup[theQuery.left][j];
			unsigned int lookupRight = lookup[theQuery.right - (1<<j) + 1][j];
			
			if ( arr[lookupLeft] <= arr[lookupRight] ){
				return arr[lookupLeft]; 
			}
		  
			else{ 
				return arr[lookupRight]; 
			}				
			
		}
	
	
		friend std::ostream& operator<<( std::ostream& output, const RMQSparse& RMQSp ){
			
			output << "Initial Array: ";
			
			for(unsigned int i=0; i < RMQSp.arrayLen; i++){
				
				output << RMQSp.arr[i] << " ";
				
			}
			
			output << ENDL << ENDL;
			
			// Print the preprocessed results to the user
			for(unsigned int i=0; i< (int)RMQSp.arrayLen; i++) 
			{ 
				for(unsigned int j=0; j < RMQSp.columns; j++) 
				{ 
					COUT << RMQSp.lookup[i][j] << " ";
				}
				COUT << ENDL;
			}			
			
			return output;
		}
		
	
	
};

#endif