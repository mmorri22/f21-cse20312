#include <iostream> /*C++ version of stdio.h*/

int main(){

	int tempInt = 26;
	float tempFloat = (float)-6.2;
	
	std::cout << "This line will have two End-of-Line chars after it.\n" << std::endl;
	
	std::cout << "The values are: " 
		<< tempInt << " " << tempFloat << std::endl;
		
		
	std::cout << "The addresses are : " 
		<< &tempInt << " " << &tempFloat << std::endl;
	
	return 0;
}

