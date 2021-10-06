#ifndef COMPLEX_H
#define COMPLEX_H

#include<iostream> 
  
class Complex { 
private: 
    int real, imag; 
	
public: 
    Complex(int r = 0, int i = 0);
	
	void setReal(int realIn);
	
	void setImag(int imagIn);
	
	int getReal() const;
	
	int getImag() const;
      
	Complex operator+(const Complex &rhs) const;
	
	Complex operator-(const Complex &rhs) const;

	bool operator==(const Complex &rhs) const;

	bool operator<(const Complex &rhs) const;

	bool operator>(const Complex &rhs) const;
	
   friend std::ostream& operator<<( std::ostream& output, const Complex& C );
   
   friend std::istream& operator>>( std::istream& input, Complex& C );
	
}; 


#endif
