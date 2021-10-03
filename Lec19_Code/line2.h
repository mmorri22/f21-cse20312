/**********************************************
* File: line2.h
* Author: Matthew Morrison
* Email: matt.morrison@nd.edu
*  
**********************************************/

#ifndef LINE2_H
#define LINE2_H 

#include "point.h"

class line{
	
	private:
		point origin;
		point destin;
	
	public:
	
		line();
		
		line(point originIn, point destinIn);
		
		/* Modification: New Constructor */
		line(COORDINATE orgX, COORDINATE orgY, COORDINATE desX, COORDINATE desY);
		
		point getOrigin() const;
		
		point getDestin() const;
	
		friend std::ostream& operator<<( std::ostream& output, const line& l);
	
};

#endif