/**********************************************
* File: callBy.cpp
* Author: Matthew Morrison
* Email: matt.morrison@nd.edu
* 
* This file contains examples of outputting  
* pointers in C++
**********************************************/

#include <iostream> /*C++ version of stdio.h*/

/********************************************
* Function Name  : passByRef
* Pre-conditions : int* tempX, int* tempY
* Post-conditions: none
* 
* Implementation of Pass By Reference from C 
********************************************/
void passByRef(int* tempX, int* tempY){
	
	std::cout << "Pass by Reference Example" << std::endl;
	std::cout << "Addresses of tempX and tempY Registers : " << &tempX << " " << &tempY << std::endl;
	std::cout << "Addresses pointed to by tempX and tempY: " << tempX << " " << tempY << std::endl;
	std::cout << "Values pointed to by *tempX and *tempY : " << *tempX << " " << *tempY << std::endl;
	std::cout << std::endl;
}



/********************************************
* Function Name  : callByRef
* Pre-conditions : int& tempX, int& tempY
* Post-conditions: none
* 
* Implementation of Call by Reference in C++ 
********************************************/
void callByRef(int& tempX, int& tempY){

	std::cout << "Call by Reference Example" << std::endl;	
	std::cout << "Address of tempX and tempY             : " << &tempX << " " << &tempY << std::endl;
	std::cout << "Values of tempX and tempY              : " << tempX << " " << tempY << std::endl;
	std::cout << std::endl;

}

/********************************************
* Function Name  : main
* Pre-conditions : none
* Post-conditions: int
* 
* This is the main driver function 
********************************************/
int main(){

	int tempX = 10;
	int tempY = 20;
	int *ptrX, *ptrY;
	
	/* Set pointers to addresses of integers */
	ptrX = &tempX;
	ptrY = &tempY;
	
	/* Previous Pass by Reference in C */
	passByRef(ptrX, ptrY);
	
	/* New Call by Reference in C++ */
	callByRef(tempX, tempY);
	
	return 0;
}
