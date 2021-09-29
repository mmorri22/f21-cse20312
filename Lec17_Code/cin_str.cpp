/**********************************************
* File: cinStr.cpp
* Author: Matthew Morrison
* Email: matt.morrison@nd.edu
* 
* This file demonstrates the benefits of cin in C++
* while providing improved tests with the string library
**********************************************/

#include <iostream> /*C++ version of stdio.h*/
#include <cstdlib> /* Equivalent of stdlib.h */
#include <string> /* String Library */
#include <sstream> /* String Stream for inputting to variables */

bool noBadChars(std::string& testString){
	
	unsigned int i;
	for(i = 0; i < testString.length(); i++){
		
		/* Return false if - is outside of the first char */
		if(  (testString[i] < '0' || testString[i] > '9') ){
					
				/* Return false if negative sign is not at i == 0 */
				if(testString[i] == '-'){
					
					if(i != 0)
						return false;
				}
				
				/* Do not return false if there is a . here */
				else if(testString[i] != '.'){
					return false;
				} 
		}
	}
	
	return true;
}

/********************************************
* Function Name  : main
* Pre-conditions : none
* Post-conditions: int
* 
* This is the main driver function 
********************************************/
int main(){

	std::string strX;
	int tempX;
	
	std::string strUnsigX;
	unsigned int unsigX;
	
	std::string strFloatX;
	float floatY;
	
	std::cout << "Input an integer: ";
	std::cin >> strX;
	
	/* Check if the int input has no chars AND if the string contains . */
	if(std::stringstream(strX) >> tempX 
		&& noBadChars(strX)
		&& strX.find(".") == std::string::npos){
		
		std::cout << "The integer is " << tempX << std::endl;
		
	}
	else{
		std::cerr << strX << " is not a valid Integer" << std::endl;
		exit(-1);
	}	
	
	std::cout << "Input an unsigned integer: ";	
	std::cin >> strUnsigX;

	/* Check if the int input has no chars AND if the string contains . AND if the string contains -*/
	if(std::stringstream(strUnsigX) >> unsigX 
		&& noBadChars(strUnsigX)
		&& strUnsigX.find(".") == std::string::npos 
		&& strUnsigX.find("-") == std::string::npos){
			
		std::cout << "The unsigned integer value is " << unsigX << std::endl;
	
	}
	else{
		
		std::cerr << strUnsigX << " is not a valid unsigned Integer" << std::endl;
		exit(-1);
		
	}
	
	
	std::cout << "Input a float: ";
	std::cin >> strFloatX;
	if(std::stringstream(strFloatX) >> floatY
		&& noBadChars(strFloatX) ){
		
		std::cout << "The float value is " << floatY << std::endl;
		
	}
	else{
		
		std::cerr << strFloatX << " is not a valid Float" << std::endl;
		exit(-1);
		
	}
		
	return 0;
}
