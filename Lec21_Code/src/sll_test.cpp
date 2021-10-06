#include "../include/sllist.h"

#define COUT std::cout
#define ENDL std::endl

int main( const int argc, const char* argv[] ){
	
	// Create a Singly Linked List on the Heap
	sllist<int>* the_list = new sllist<int>();
	
	for( int iter = 1; iter < argc; ++iter ){
		
		int temp = atoi( argv[iter] );
		
		the_list->insert(temp);
	}
	
	COUT << the_list << ENDL;
	
	// Must delete if new is called 
	delete the_list;
	
	return 0;
}