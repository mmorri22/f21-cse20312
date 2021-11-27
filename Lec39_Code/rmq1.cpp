#include <iostream>

#define COUT std::cout
#define ENDL std::endl 
  
// Structure to represent a query range 
struct RMQuery 
{ 
    unsigned int left, right; 
	
	RMQuery(unsigned int leftIn, unsigned int rightIn) : left(leftIn), right(rightIn) {}
}; 
  
// Fills lookup array lookup[n][n] for all possible values of 
template< class T >
unsigned int** preprocess(T arr[], long unsigned int arraySize) 
{ 

	// Create the array of pointers to allocate the memory
	unsigned int** lookup = (unsigned int **)malloc( arraySize * sizeof(unsigned int *) );
	
	// Allocate the array for each element
	for( long unsigned int iter = 0; iter < arraySize; iter++ ){
		
		lookup[iter] = (unsigned int *)malloc( arraySize * sizeof(unsigned int) );
	}

    // Initialize lookup[][] for the intervals with length 1 
    //for (int i = 0; i < (int)arraySize; i++) 
        //lookup[i][i] = i; 
  
    // Fill rest of the entries in bottom up manner 
    for (int iter = (int)arraySize - 1; iter >= 0; iter--) 
    { 
        for (int jter = iter; jter <= (int)arraySize - 1; jter++) {
			
			if( jter == iter ){
				
				lookup[iter][jter] = iter;
			}
			else{
				
				if( arr[ lookup[iter][ jter - 1 ] ] < arr[jter] ){
					
					lookup[iter][jter] = lookup[iter][jter - 1]; 
					
				}
				else{
					
					lookup[iter][jter] = jter;
				}
			}
		}		   
    } 
	
	
	for(int i=0; i< (int)arraySize; i++) 
    { 
		for(long unsigned int j=0; j<arraySize; j++) 
		{ 
			std::cout << lookup[i][j] << " ";
		}
		std::cout << std::endl;
	}
	
	return lookup;
} 
  
// Prints minimum of given m query ranges in arr[0..n-1] 
template< class T >
void RMQ( T arr[], unsigned int** lookup, RMQuery theQuery ) 
{ 

	// Print sum of current query range 
	COUT << "Minimum of [" << theQuery.left << ", " << theQuery.right << "] is ";  
	COUT << arr[ lookup[ theQuery.left ][ theQuery.right ] ] << ENDL; 
		 
} 

void test1(){
	
	// Initialize the array length 
    int rmqArray[] = {31, 41, 59, 26, 53, 58, 97, 93}; 
	
	// How to obtain the size of the array when we use {} initializer
    long unsigned int n = sizeof(rmqArray)/sizeof(rmqArray[0]); 
	
	// Fill lookup table for all possible input queries 
	unsigned int** lookup = preprocess(rmqArray, n);

	RMQuery q1(0, 3);	
	RMQuery q2(1, 4);
	RMQuery q3(4, 7);
	RMQuery q4(6, 7);
	
    RMQ(rmqArray, lookup, q1); 
    RMQ(rmqArray, lookup, q2);
    RMQ(rmqArray, lookup, q3); 	
    RMQ(rmqArray, lookup, q4); 
	
	std::cout << std::endl;
}


void test2(){
	
	// Initialize the array length 
    int rmqArray[] = {31, 41, 59, 26, 53, 58, 97, 93, 18, 46, 99, 5, 22, 17, 85, 42, 7}; 
	
	// How to obtain the size of the array when we use {} initializer
    long unsigned int n = sizeof(rmqArray)/sizeof(rmqArray[0]); 
	
	// Fill lookup table for all possible input queries 
	unsigned int** lookup = preprocess(rmqArray, n);

	RMQuery q1(6, 7);	
	RMQuery q2(1, 4);
	RMQuery q3(4, 7);
	RMQuery q4(1, 15);
	
    RMQ(rmqArray, lookup, q1); 
    RMQ(rmqArray, lookup, q2);
    RMQ(rmqArray, lookup, q3); 	
    RMQ(rmqArray, lookup, q4); 
	
	std::cout << std::endl;
}


void test3(){
	
	// Initialize the array length 
    char rmqArray[] = {'N', 'o', 't', 'r', 'e', 'D', 'a', 'm', 'e'}; 
	
	// How to obtain the size of the array when we use {} initializer
    long unsigned int n = sizeof(rmqArray)/sizeof(rmqArray[0]); 
	
	// Fill lookup table for all possible input queries 
	unsigned int** lookup = preprocess(rmqArray, n);

	RMQuery q1(0, 1);	
	RMQuery q2(0, 4);
	RMQuery q3(1, 4);
	RMQuery q4(4, 7);
	
    RMQ(rmqArray, lookup, q1); 
    RMQ(rmqArray, lookup, q2);
    RMQ(rmqArray, lookup, q3); 	
    RMQ(rmqArray, lookup, q4); 
	
	std::cout << std::endl;
}
  
// Driver program 
int main() 
{ 
	// Initial 8 integer from slides
	test1();
	
	// Next 16 integer array from slides 
	test2();
	
	// Character test with letters from Notre Dame
	test3();
} 
