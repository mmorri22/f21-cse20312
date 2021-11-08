#include <iostream>
#include <fstream>
#include <vector>
#include <stack>
#include <unordered_map>

#define COUT std::cout 
#define ENDL std::endl
#define OFSTREAM std::ofstream
#define VECTOR std::vector
#define PAIR std::pair
#define STACK std::stack

// In-Class Coding Opportunity
void DFS( const VECTOR< PAIR<int, int> >& graph_vec, int begin, int end ){
	
	// Initialize an unordered map of integers 
	std::unordered_map< int, int > the_map;
	
	// Create a stack, templated to integer pairs
	STACK< PAIR<int, int> > the_stack;
	
	// Initialize the traversal
	// Insert the first element in the vector, with a second element with -1 (no parent)
	the_map.insert( { graph_vec.at( begin ).first, -1 } );
	
	// Insert the second element for begin, and then the first (indicating the 1st is second's parent 
	the_map.insert( { graph_vec.at( begin ).second, graph_vec.at( begin ).first } );
	
	// Check all the edges 
	for( PAIR<int, int> curr_pair : graph_vec ){
		
		// If we haven't encountered the destination of the edge
		if( the_map.count( curr_pair.second ) == 0 ){
			
			// Insert the element (second, first) 
			the_map.insert( {curr_pair.second, curr_pair.first} );
		}
		
	}
	
	// While the second element in the pair is not -1
	for( int value = end; value != -1; value = the_map[ value ] ){
		
		// Push the value and the parent into the stack 
		the_stack.push( { value, the_map[value] } );
		
	}
	
	// While the stack is not empty 
	while( !the_stack.empty() ){
		
		// Print the "first" element at the top of the stack
		COUT << the_stack.top().first << " ";
		
		// Pop the element off the top
		the_stack.pop();
	}
	
	// Print the endline 
	COUT << ENDL;
	
}

int main(){
	
	VECTOR< PAIR<int, int> > graph_vec{ {0, 1}, {0, 2}, {1, 2}, {1, 3}, {2, 4}, {3, 5} };
	
	DFS( graph_vec, 0, 5 );
	
	return 0;
	
}