/**********************************************
* File: line1.h
* Author: Matthew Morrison
* Email: matt.morrison@nd.edu
*  
**********************************************/

#ifndef LINE1_H
#define LINE1_H 

#include "point.h"

class line{
	
	private:
		point origin;
		point destin;
	
	public:
	
		line();
		
		line(point originIn, point destinIn);
		
		point getOrigin() const;
		
		point getDestin() const;
	
		friend std::ostream& operator<<( std::ostream& output, const line& l);
	
};

#endif