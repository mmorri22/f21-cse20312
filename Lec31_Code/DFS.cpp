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
	
	
	// Create a stack, templated to integer pairs
	
	
	// Initialize the traversal
	// Insert the first element in the vector, with a second element with -1 (no parent)
	
	
	// Insert the second element for begin, and then the first (indicating the 1st is second's parent 
	
	
	// Check all the edges 
	
		
		// If we haven't encountered the destination of the edge
		
			
			// Insert the element (second, first) 
			
		
		
	
	
	// While the second element in the pair is not -1
	
		
		// Push the value and the parent into the stack 
		
		
	
	
	// While the stack is not empty 
	
		
		// Print the "first" element at the top of the stack
		
		
		// Pop the element off the top
		
	
	
	// Print the endline 
	
	
}

int main(){
	
	VECTOR< PAIR<int, int> > graph_vec{ {0, 1}, {0, 2}, {1, 2}, {1, 3}, {2, 4}, {3, 5} };
	
	DFS( graph_vec, 0, 5 );
	
	return 0;
	
}