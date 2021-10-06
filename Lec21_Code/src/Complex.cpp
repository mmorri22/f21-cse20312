#include "../include/Complex.h"

Complex::Complex(int r, int i) : real(r), imag(i) {} 

void Complex::setReal(int realIn){
	real = realIn;
}

void Complex::setImag(int imagIn){
	imag = imagIn;		
}

int Complex::getReal() const{
	return real;
}

int Complex::getImag() const{
	return imag;
}

Complex Complex::operator+(const Complex &rhs) const{ 
	 Complex sol; 
	 sol.real = real + rhs.real; 
	 sol.imag = imag + rhs.imag; 
	 return sol; 
}

Complex Complex::operator-(const Complex &rhs) const{
	 Complex sol; 
	 sol.real = real - rhs.real; 
	 sol.imag = imag - rhs.imag; 
	 return sol; 
} 

bool Complex::operator==(const Complex &rhs) const{ 
	 if(real == rhs.real && imag == rhs.imag){
		return true; 
	 }
	 return false;
} 


bool Complex::operator<(const Complex &rhs) const{ 
	 if(real < rhs.real){
		return true; 
	 }
	 else if(real == rhs.real && imag < rhs.imag){
		return true;
	 }
	 return false;
} 


bool Complex::operator>(const Complex &rhs) const{
	
	if(real > rhs.real){
		return true;
	}
	else if(real == rhs.real && imag > rhs.imag){
		return true;
	}
	return false;
	
}

std::ostream& operator<<( std::ostream& output, const Complex& C ){ 

	output << C.real;

	if(C.imag < 0){
		output << " - i" << -1*C.imag;
	}
	else{
		output << " + i" << C.imag;
	}
	
	return output;
} 

std::istream& operator>>( std::istream& input, Complex& C ){
	
	int real, imag;
	input >> real;
	input >> imag;
	
	C.setReal(real);
	C.setImag(imag);
	
	return input;
	
}


