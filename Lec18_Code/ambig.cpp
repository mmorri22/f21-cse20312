/**********************************************
* File: ambig.cpp
* Author: Matthew Morrison
* Email: matt.morrison@nd.edu
* 
* This file demonstrates an example of ambiguous 
* overloading, where you cannot tell what the 
* output will be. Contains deliberate compiler errors
**********************************************/

#include <iostream> /*C++ version of stdio.h*/

/********************************************
* Function Name  : PrintMe
* Pre-conditions : std::string s
* Post-conditions: none
* 
* Overloaded Function that prints a string  
********************************************/
void PrintInt (int i) {
   i = i + 2;
   std::cout << i << std::endl;
}

/********************************************
* Function Name  : PrintMe
* Pre-conditions : int& i
* Post-conditions: none
* 
* Overloaded Function the Prints an integer 
********************************************/
void PrintInt (int& i) {
   i = i + 2;
   std::cout << i << std::endl;
}


/********************************************
* Function Name  : PrintMe
* Pre-conditions : const int i
* Post-conditions: none
* 
* Overloaded Function the Prints an integer 
********************************************/

/* DELIBERATE COMPILER ERROR 
	/escnfs/home/mmorri22/cse20133/25-AdvCPPIntro/ambig.cpp: In function ‘void PrintInt(int)’:
	/escnfs/home/mmorri22/cse20133/25-AdvCPPIntro/ambig.cpp:53:6: error: redefinition of ‘void PrintInt(int)’
	 void PrintInt (const int i) {
		  ^
	/escnfs/home/mmorri22/cse20133/25-AdvCPPIntro/ambig.cpp:20:6: error: ‘void PrintInt(int)’ previously defined here
	 void PrintInt (int i) { */
void PrintInt (const int i) {
	
   /* Another deliberate compiler error */
   /* const variables cannot be changed */
   /* /escnfs/home/mmorri22/cse20133/25-AdvCPPIntro/ambig.cpp:60:6: error: assignment of 
      read-only parameter ‘i’
	  i = i + 2; */
   i = i + 2;
   std::cout << i << std::endl;
}

/********************************************
* Function Name  : main
* Pre-conditions : none
* Post-conditions: int
* 
* This is the main driver function 
********************************************/
int main(){

	int tempX = 25;

	/* Since the overload call is ambiguous, this will produce a compiler error as well */
	/* This is because it can't tell between PrintInt(int tempX) and PrintInt(int& tempX) 
	   /escnfs/home/mmorri22/cse20133/25-AdvCPPIntro/ambig.cpp: In function ‘int main()’:
       /escnfs/home/mmorri22/cse20133/25-AdvCPPIntro/ambig.cpp:86:16: error: call of overload                ed ‘PrintInt(int&)’ is ambiguous 
       PrintInt(tempX);
	   /escnfs/home/mmorri22/cse20133/25-AdvCPPIntro/ambig.cpp:86:16: note: candidates are:
	   /escnfs/home/mmorri22/cse20133/25-AdvCPPIntro/ambig.cpp:20:6: note: void PrintInt(int)
	    void PrintInt (int i) {
		/escnfs/home/mmorri22/cse20133/25-AdvCPPIntro/ambig.cpp:32:6: note: void PrintInt(int&)
              void PrintInt (int& i) */

	PrintInt(tempX);

	std::cout << tempX << std::endl;
		
	return 0;
}
