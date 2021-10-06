/**********************************************
* File: iterator.cpp
* Author: Matthew Morrison
* Email: matt.morrison@nd.edu
* 
* Contains an example of std::vector using STL iterators
**********************************************/

#include<iostream> 
#include<vector>		// Implement Vector



template<class T>
void printValues(std::vector<T>& theList){
	std::cout << "The elements are : "; 
	
    for (T& a : theList) 
        std::cout << a << " "; 
	
    std::cout << std::endl; 
}

int main(){
	
    // Declaring forward list int and the iterators
    std::vector<int> vectorInt = {1,2,7,3,4};
	printValues(vectorInt);

	// C++ STL Iterators and helping students review pointers
	for(auto fwdPtr = vectorInt.begin(); *fwdPtr != 3; ++fwdPtr){
		if(*fwdPtr == 7){
			*fwdPtr = 1842;
		}
	}
	
	for(int& intVal : vectorInt){
		if(intVal == 3){
			intVal = 77;
		}
	}
	//vectorInt.push_front(0);
	printValues(vectorInt);
	
    // Declaring forward list std::string and the iterators
    std::vector< std::string > vecStr = {"Let's", "Go", "Irish!"};
	printValues(vecStr);
	
	for(std::string& a : vecStr){
		if(a == "Let's"){
			a = "Here We";
		}
	}
	
	vecStr.push_back("Here We Go!");
	printValues(vecStr);
	
	return 0;
}
