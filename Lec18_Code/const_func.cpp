/**********************************************
* File: constFunc.c
* Author: Matthew Morrison
* Email: matt.morrison@nd.edu
* 
* This file contains the function definitions for the
* const variable description for Lecture 24 
**********************************************/

#include "constFunc.h"

/********************************************
* Function Name  : CircleArea
* Pre-conditions : double radius 
* Post-conditions: double
* 
* Calculates the area of a circle 
********************************************/
double CircleArea( double radius ){
	
	return PI * radius * radius;
	
}

/********************************************
* Function Name  : CircleCircumference
* Pre-conditions : double radius 
* Post-conditions: double
* 
* Calculates the circumfrence of a circle 
********************************************/
double CircleCircumference ( double radius ){
	
	return PI * radius;
	
}
