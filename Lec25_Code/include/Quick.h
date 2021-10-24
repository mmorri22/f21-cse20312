#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm> // std::random_shuffle
#define COUT std::cout
#define ENDL std::endl

/********************************************
* Function Name  : printArray
* Pre-conditions : T* array, const int& length
* Post-conditions: none
* 
* Prints in order the array  
********************************************/
template<typename T> 
void printArray(std::vector<T>& theArray){
	
	for (int iter = 0; iter < theArray.size(); iter++){
		
		COUT << theArray.at(iter) << " ";
		
	}
}

/********************************************
* Function Name  : swap
* Pre-conditions : T* array, int i, int j
* Post-conditions: none
* 
* This function swaps two elements at i and j 
********************************************/
template<typename T> 
void swap (std::vector<T>& theArray, int i, int j){
	
	T temp = theArray[i];
	theArray[i] = theArray[j];
	theArray[j] = temp;

}



/********************************************
* Function Name  : partition
* Pre-conditions : T* array, int min, int max
* Post-conditions: int
* 
* Performs the partitioning for the Quick Sort
* and returns the next partition point  
********************************************/
template<typename T> 
int partition(std::vector<T>& array, int min, int max){
	
	// Select Scan references
	int left = min + 1;
	int right = max;
	T reference = array[min];
	
	// We scan the elements 
	// Break the loop when one of three cases arises
	while (true){
		
			while( left < max ){
				
				// Case 1: If the left element is greater than reference
				if (array[left] > reference){
					break;
				}
				left++;
			}

			while( right > min ){
				
				// Case 2: If the right element is less than reference
				if(array[right] < reference){
					break;
				}
				right--;
			}
			
			// If left and right indicies cross
			if (left >= right){
				break;
			}
			
			// Swap the values
			swap(array, left, right);
	}
	
	// put reference at the crossing point
	swap(array, min, right);
	
	// Return the right index
	return right;
	
}

// Function: sort
// Sort the subarray from min to max
template<typename T>
void QuickSort(std::vector<T>& array, int min, int max){
	
	if (min >= max){
		return;
	}
	
	int j = partition(array, min, max);
	
	// Perform QuickSort to the left of the partition
	QuickSort(array, min, j-1);

	// Perform QuickSort to the right of the partition
	QuickSort(array,j + 1, max);
	
}

#endif