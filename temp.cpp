/******************************************************************************
 *
 * Welcome to GDB Online.
 * GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
 * C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
 * Code, Compile, Run and Debug online from anywhere in world.
 *
 * *******************************************************************************/
#include <iostream>
#include <cstdlib>

class sample{
	    
	  int the_int;
	    float the_float;
	      double the_double;
	          
};

template< class T >
struct sll_node_struct{
	    
	  T data;
	    struct sll_node_struct<T>* next_node;
	        
};

template< class T >
class sll_node_class{
	    
	  T data;
	    sll_node_class<T>* next_node;   
	        
};

int main()
{
	    std::cout << sizeof( struct sll_node_struct<sample> ) << std::endl;
	        std::cout << sizeof( sll_node_class<sample> ) << std::endl;
		    return 0;
}


