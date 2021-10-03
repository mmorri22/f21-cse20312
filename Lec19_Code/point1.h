/**********************************************
* File: point1.h
* Author: Matthew Morrison
* Email: matt.morrison@nd.edu
*  
* This file contains the method declarations for 
* class point, used in the introduction to C++ 
* classes lecture. 
**********************************************/
#ifndef POINT1_H
#define POINT1_H 

#include <iostream>

typedef double COORDINATE;

class point{
	
	private:
	
		COORDINATE x;
		COORDINATE y;
	
	public:
	
		point();
		
		point(COORDINATE inX, COORDINATE inY);
		
		COORDINATE getX() const ;
		
		COORDINATE getY() const ;
		
		void setX(COORDINATE inX);
		
		void setY(COORDINATE inY);

};

#endif
