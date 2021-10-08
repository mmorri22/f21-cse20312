#include "../include/queue.h"

#define COUT std::cout
#define ENDL std::endl

int main( const int argc, const char* argv[] ){
	
	// Create a queue on the Heap
	queue<int>* the_queue = new queue<int>();
	
	for( int iter = 1; iter < argc; ++iter ){
		
		int temp = atoi( argv[iter] );
		
		the_queue->push(temp);
	}
	
	while( !the_queue->is_empty() ){
		
		COUT << the_queue->top() << " ";
		the_queue->pop();
		
	}
	COUT << ENDL;
	
	// Must delete if new is called 
	delete the_queue;
	
	return 0;
}