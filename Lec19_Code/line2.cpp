/**********************************************
* File: line2.cpp
* Author: Matthew Morrison
* Email: matt.morrison@nd.edu
*  
* Fundamental Class Example
**********************************************/

#include "line2.h"

line::line() : origin( point(0, 0) ), destin( point(0, 0) ) {}

line::line(point originIn, point destinIn) : origin(originIn), destin(destinIn) {}

/* Modification: New Constructor */
line::line(COORDINATE orgX, COORDINATE orgY, COORDINATE desX, COORDINATE desY) : 
	origin( point(orgX, orgY) ), destin( point(desX, desY) ) {}
	
	
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