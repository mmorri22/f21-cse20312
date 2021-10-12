#include "b_tree.h"

#include <cstdlib>

#define COUT std::cout
#define ENDL std::endl

int main( const int argc, const char* argv[] ){
	
	VECTOR<int> test_vector;
	
	for( int iter = 1; iter < argc; ++iter ){
		test_vector.push_back( atoi( argv[iter] ) );
	}
	
	COUT << "Testing B-Tree Degree of 4" << ENDL;
	
	b_tree<int>* the_b_tree = new b_tree<int>(4);
	
	for( int iter = 1; iter < argc; ++iter ){
		
		the_b_tree->insert( atoi( argv[iter] ) );
		COUT << the_b_tree << ENDL;
	}
	
	
	delete the_b_tree;
	
	
	return 0;
}