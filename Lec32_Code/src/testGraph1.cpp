#include "../inc/Graph1.h"

#include <iostream>
#include <fstream>

#define COUT std::cout
#define ENDL std::endl
#define OFSTREAM std::ofstream

int main(){
	
	Graph< std::string > theGraph;
	
	// Four Vertices for Seven Bridges of Koningsberg
	theGraph.add_vertex( "Top River Bank" );
	theGraph.add_vertex( "Left Island" );
	theGraph.add_vertex( "Bottom River Bank" );
	theGraph.add_vertex( "Right Island" );
	
	// Add the Bridge Edges
	// Can cross in either direction
	// Two bridges go from 0 to 1 and one from 0 to 3
	theGraph.add_edge(0, 1, 1);		theGraph.add_edge(0, 1, 1 );
	theGraph.add_edge(0, 3, 1);
	
	// Two bridges from 1 to 0, two from 1 to 2, and one from 1 to 3
	theGraph.add_edge(1, 0, 1 );	theGraph.add_edge(1, 0, 1 );
	theGraph.add_edge(1, 2, 1 );	theGraph.add_edge(1, 2, 1 );
	theGraph.add_edge(1, 3, 1 );
	
	// Two bridges from 2 to 1, and one from 2 to 3
	theGraph.add_edge(2, 1, 1 );	theGraph.add_edge(2, 1, 1 );
	theGraph.add_edge(2, 3, 1 );	
	
	// One bridge from 3 to 2, and One from 3 to 0
	theGraph.add_edge(3, 2, 1 );	theGraph.add_edge(3, 0, 1 );
	
	// Create the output stream 
	OFSTREAM file_out( "Prob2.txt" );
	
	// Print the Graph to the user
	file_out << theGraph << std::endl;
	
	file_out.close();
	
	return 0;
	
}