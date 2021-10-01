#include <iostream> 

const double PI = 3.14159;

double CircleArea( double radius ){
	
	return PI * radius * radius;
	
}

double CircleCircumference ( double radius ){
	
	return PI * radius;
	
}

int main(){

	double radius = 5;
	
	std::cout << "The circle's radius is " << radius << std::endl;
	std::cout << "The value of Pi is " << PI << std::endl;
	
	std::cout << "The area of the circle is " 
		<< CircleArea( radius ) << std::endl;
		
	std::cout << "The circumfrence of the circle is " 
		<< CircleCircumference( radius ) << std::endl;

	return 0;
}
