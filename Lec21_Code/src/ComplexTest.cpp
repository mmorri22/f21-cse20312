#include "../include/Complex.h"

int main() 
{ 
    const Complex c1(2, 5);
	Complex c2(2, 6); 
	
	c2.setImag( -1 );
	
	/* Overloaded Output Operator */
	std::cout << "Complex c1 = " << c1 << std::endl;
	std::cout << "Complex c2 = " << c2 << std::endl;

	/* Overloaded Operators comparison operators */
	if(c1 < c2){
		std::cout << "c1 < c2" << std::endl;
	}
	else if(c1 > c2){
		std::cout << "c1 > c2" << std::endl;
	}
	else if(c1 == c2){
		std::cout << "c1 == c2" << std::endl;
	}
	else{
		std::cout << "What?" << std::endl;
	}
	
	/* Overloaded Addition and Subtraction Operator */
    Complex c3 = c1 + c2; 
	Complex c4 = c1 - c2;
	
	/* Overloaded Output Operator */
    std::cout << "Complex c3 = " << c3 << std::endl;
    std::cout << "Complex c4 = " << c4 << std::endl;
	
	std::cout << c1 << " " << c2 << std::endl;
	
	Complex c5;
	std::cout << "Input two values for Complex c5: ";
	std::cin >> c5;
	
	std::cout << c5 << std::endl;
	
}