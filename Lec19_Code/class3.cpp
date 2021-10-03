/**********************************************
* File: classIntro.cpp
* Author: Matthew Morrison
* Email: matt.morrison@nd.edu
* 
* This file contains examples of class constructor calls 
**********************************************/

/********************************************
* Function Name  : main
* Pre-conditions : none
* Post-conditions: int
* 
* This is the main driver function for the program 
********************************************/
#include "line1.h"
int main(){

	point point1;
	
	std::cout << "point1 is " << point1 << std::endl;
	
	/* Update values */
	point1.setX( 3.1 );
	point1.setY( 6.2 );
	
	std::cout << "After update: point1 is " << point1 << std::endl;
	std::cout << std::endl;
	
	/* Second constructor for point */
	const point point2( -1.1, 5.3 );
	
	std::cout << "point2 is " << point2 << std::endl  << std::endl;
	
	/* Default constructor for line */
	line line1;
	std::cout << "line1 is " << line1 << std::endl << std::endl;	
	
	/* Constructor qwith points for line */
	line line2(point1, point2);
	std::cout << "line2 is " << line2 << std::endl;
	
	return 0;
}
