#include "../include/deque.h"

#define COUT std::cout
#define ENDL std::endl

int main( const int argc, const char* argv[] ){
	
	// Create a deque on the Heap
	deque<int>* the_deque = new deque<int>();
	
	for( int iter = 1; iter < argc; ++iter ){
		
		int temp = atoi( argv[iter] );
		
		if( iter % 2 == 0 )
			the_deque->push_back(temp);
		else
			the_deque->push_front(temp);
	}
	
	while( !the_deque->is_empty() ){
		
		COUT << the_deque->front() << " ";
		the_deque->pop_front();
		
	}
	COUT << ENDL;
	
	// Must delete if new is called 
	delete the_deque;
	
	return 0;
}