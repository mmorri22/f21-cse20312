#include "../include/stack.h"

#define COUT std::cout
#define ENDL std::endl

int main( const int argc, const char* argv[] ){
	
	// Create a Stack on the Heap
	stack<int>* the_stack = new stack<int>();
	
	for( int iter = 1; iter < argc; ++iter ){
		
		int temp = atoi( argv[iter] );
		
		the_stack->push(temp);
	}
	
	while( !the_stack->is_empty() ){
		
		COUT << the_stack->top() << " ";
		the_stack->pop();
		
	}
	COUT << ENDL;
	
	// Must delete if new is called 
	delete the_stack;
	
	return 0;
}