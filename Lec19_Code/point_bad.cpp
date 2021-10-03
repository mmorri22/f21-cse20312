/**********************************************
* File: classIntro.cpp
* Author: Matthew Morrison
* Email: matt.morrison@nd.edu
* 
* This file contains examples of class constructor calls 
**********************************************/

#include "../inc/point.h"

int main(){

	point point1();	/* Deliberate Logic Error */
	
	std::cout << "point1 is ";
	point1.printPoint();
	std::cout << std::endl;
	
	/* Update values */
	point1.setX( (COORDINATE)3.1 );
	point1.setY( (COORDINATE)6.2 );
	
	std::cout << "After update: point1 is ";
	point1.printPoint();
	std::cout << std::endl;
	
	/* Second constructor for point */
	point point2( (COORDINATE)-1.1, (COORDINATE)5.3 );
	std::cout << "point2 is ";
	
	point2.printPoint();
	std::cout << std::endl;
	
	return 0;
}
