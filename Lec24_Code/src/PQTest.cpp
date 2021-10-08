#include "../inc/PriorityQueue.h"
#include "../inc/MaxHeap.h"

#include <iostream>
#include <string>

#define COUT std::cout
#define ENDL std::endl

int main(int argc, char** argv){
	
	// Initialize the Priority Queue with string Priorities
	PriorityQueue< int > thePQ;
	
	for( int iter = 1; iter < argc; ++iter ){
	
		// Friendly reminder that this line of code is equivalent to 
		// thePQ.push( atoi( argv[ iter ] ) );
		thePQ.push( atoi( *( argv + iter ) ) );
	
	}
	
	// Print the results from pop
	COUT << "Priority Result: ";
	while( !thePQ.empty() ){
		
		COUT << thePQ.front() << " ";
		thePQ.pop();
	}
	
	COUT << ENDL;

	return 0;
}