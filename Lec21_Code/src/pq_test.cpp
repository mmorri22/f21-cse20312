#include "../include/priority_queue.h"

#define COUT std::cout
#define ENDL std::endl

int main( const int argc, const char* argv[] ){
	
	// Create a priority_queue on the Heap
	priority_queue<int>* the_priority_queue = new priority_queue<int>();
	
	for( int iter = 1; iter < argc; ++iter ){
		
		int temp = atoi( argv[iter] );
		
		the_priority_queue->push(temp);
	}
	
	while( !the_priority_queue->is_empty() ){
		
		COUT << the_priority_queue->front() << " ";
		the_priority_queue->pop();
		
	}
	COUT << ENDL;
	
	// Must delete if new is called 
	delete the_priority_queue;
	
	return 0;
}