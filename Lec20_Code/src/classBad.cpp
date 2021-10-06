#include "../include/Abad.h"

int main()  { 

   const A<char, char> a('G', 72); 
   A<char, char> b(71, 'H'); 
   A<int, float> c(10, (float)-35.7); 
   
   std::cout << "a: " << a << std::endl;
   std::cout << "b: " << b << std::endl;  
   std::cout << "c: " << c << std::endl;  
   
   if(a == b){
	   std::cout << "a == b" << std::endl;
   }
   
   c.setX(31); 
   c.setY( (float)18.231 );
   std::cout << "c: " << c << std::endl;  
   
   return 0; 
} 
