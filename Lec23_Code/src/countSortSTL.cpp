/**********************************************
* File: countSort.cpp
* Author: Matthew Morrison
* Email: matt.morrison@nd.edu
* 
* Shows a basic example of Counting Sort
* using the C++ STL Libraries
**********************************************/
#include <unordered_map>
#include <vector>
#include <string>
#include <iostream>

void printHash(std::unordered_map< int, int >& countSort, int largestNum){

	for(int i = 0; i <= largestNum; i++){
		
		for(int j = 0; j < countSort[i]; ++j){
			
			std::cout << i << " ";
		}

	}
	
	std::cout << std::endl;
	
	std::cout << "Number of buckets at end of iteration: "; 
	std::cout << countSort.bucket_count() << std::endl;
	
}

/********************************************
* Function Name  : main
* Pre-conditions :
* Post-conditions: int
*
* Main driver function. Solution  
********************************************/
int main(){

	/* The Hash Table for the Counting Sort */
	std::unordered_map<int, int> countSort;
	
	/* A vector of values to sort */
	std::vector<int> theVals{7, 1, 5, 7, 1, 4, 100, 44, 9};
	
	/* Get the largest number, which is the number of buckets */
	int largestNum = 0;
	for(unsigned int iter = 0; iter < theVals.size(); iter++){
		
		if( countSort.count( theVals[iter] ) == 0 ){
			
			// Increment the value
			countSort[ theVals[iter] ]++;
			
		}
		else{
			// Initialize the count at 1
			countSort.insert( {theVals[iter], 1} );
		}
		
		// Keep track of the largest value
		if(theVals[iter] > largestNum){
			largestNum = theVals[iter];
		}
		
	}
	
	std::cout << "Initial buckets: " << countSort.bucket_count() << std::endl;

	/* Print the Hash */
	printHash(countSort, largestNum);

	return 0;
}
