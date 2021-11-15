#include "../inc/Graph.h"
#include <iostream>

int main(){
	
	Graph< char > theGraph;
	
	theGraph.add_vertex( 'A' );		theGraph.add_vertex( 'B' );
	theGraph.add_vertex( 'C' );		theGraph.add_vertex( 'D' );
	theGraph.add_vertex( 'E' );		theGraph.add_vertex( 'F' );
	
	// Nodes from 0
	theGraph.add_edge( 0, 1, 5 );	theGraph.add_edge( 0, 2, 6 );
	theGraph.add_edge( 0, 3, 7 );	theGraph.add_edge( 0, 5, 9 );
	
	// Nodes from 1	
	theGraph.add_edge( 1, 3, 1 );	theGraph.add_edge( 1, 4, 7 );
	
	// Nodes from 2
	theGraph.add_edge( 2, 3, 4 );	theGraph.add_edge( 2, 4, 5 );
	
	// Nodes from 3 
	theGraph.add_edge( 3, 4, 2 );
	
	// Nodes from 4
	theGraph.add_edge( 4, 5, 3 );
	
	// Print Original Graph:
	std::cout << "Original Graph:\n" << theGraph << std::endl;
	
	// Run Breadth-First Search
	std::cout << "\nMST Solution:\n" << theGraph.MST() << std::endl;

	return 0;
}
