#include <iostream> /*C++ version of stdio.h*/
#include <cstdlib> /* Equivalent of stdlib.h */
#include <string> /* String Library */
#include <sstream> /* String Stream for inputting to variables */

void PrintMe (std::string& s) {
   std::cout << "string s = \"" << s << "\"" << std::endl ;
}


void PrintMe (int i) {
   std::cout << "int i = " << i << std::endl ;
}


void PrintMe (std::string& s, int i) {
   std::cout << s << " " << i << std::endl ;
}


int main(){

	std::string strX = "Hello, World";
	int tempX = 25;
	
	PrintMe(strX);
	PrintMe(tempX);
	PrintMe(strX, tempX);
		
	return 0;
}
