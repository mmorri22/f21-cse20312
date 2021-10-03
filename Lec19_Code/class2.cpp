/**********************************************
* File: class2.cpp
* Author: Matthew Morrison
* Email: matt.morrison@nd.edu
* 
* This file contains examples of class constructor calls 
**********************************************/
#include "point.h"

/********************************************
* Function Name  : main
* Pre-conditions : none
* Post-conditions: int
* 
* This is the main driver function for the program 
********************************************/
int main(){

	/* Default constructor */
	point point1;
	
	/* Constructor with input values */
	const point point2( 2.2, 3.7 );
	
	/* Print both points */
	std::cout << "Point1: " << point1 << std::endl;
	std::cout << "Point2: " << point2 << std::endl;
	
	/* Update values */
	point1.setX( 3.1 );
	point1.setY( 6.2 );
	
	std::cout << "Point1: " << point1 << std::endl;
	
	return 0;
}
