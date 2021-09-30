#include <iostream>
#include <cstdlib>

int main( void ){
	
	std::cout << "Hello, World" << std::endl;
	
	int int_input;
	
	if( std::cin >> int_input)
		std::cout << int_input << " " << &int_input << std::endl;
	
	else
		std::cerr << "That was bad!" << std::endl;
	
	
	return 0;
	
}