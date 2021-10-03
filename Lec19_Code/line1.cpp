/**********************************************
* File: line1.cpp
* Author: Matthew Morrison
* Email: matt.morrison@nd.edu
*  
* Fundamental Class Example
**********************************************/

#include "line1.h"

line::line() : origin( point(0, 0) ), destin( point(0, 0) ) {}

line::line(point originIn, point destinIn) : origin(originIn), destin(destinIn) {}
	
	
point line::getOrigin() const{
	
	return origin;
}

point line::getDestin() const{
	
	return destin;
}


std::ostream& operator<<( std::ostream& output, const line& l){
	
	output << l.origin << ", " << l.destin;
	
	return output;
}