#include "../inc/Graph.h"
#include <iostream>

#define COUT std::cout
#define ENDL std::endl

template< class T >
void checkConnected( Graph<T>& theGraph, unsigned int origin, unsigned int destin ){
	
	COUT << "Vertices " << origin << " and " << destin << " are";
	
	if( !theGraph.connected( origin, destin ) ){
		
		COUT << " not";
	}
	
	COUT << " connected." << ENDL;
	
}

void initializeGraph( Graph<int>& disjointSet ){
	
	for( int iter = 0; iter < 10; iter++ ){
		
		disjointSet.add_vertex( iter );
	
	}
	
	disjointSet.add_edge( 1, 2, 1 );	disjointSet.add_edge( 2, 1, 1 );
	
	disjointSet.add_edge( 1, 6, 1 );	disjointSet.add_edge( 6, 1, 1 );
	
	disjointSet.add_edge( 5, 6, 1 );	disjointSet.add_edge( 6, 5, 1 );
	
	disjointSet.add_edge( 3, 8, 1 );	disjointSet.add_edge( 8, 3, 1 );
	
	disjointSet.add_edge( 4, 9, 1 );	disjointSet.add_edge( 9, 4, 1 );
	
	COUT << "The initial Disjoint Set:" << ENDL;
	COUT << disjointSet << ENDL << ENDL;	
	
}

int main(){
	
	Graph< int > disjointSet;
	
	initializeGraph( disjointSet );
	
	checkConnected( disjointSet, 0, 1 );
	checkConnected( disjointSet, 2, 1 );	
	checkConnected( disjointSet, 6, 5 );
	checkConnected( disjointSet, 3, 8 );
	checkConnected( disjointSet, 3, 9 );
	
	COUT << ENDL;
	
	disjointSet.Union( 0, 1 );
	
	disjointSet.Union( 2, 7, 3 );	
	
	disjointSet.Union( 3, 8, 4 );
	
	disjointSet.Union( 3, 9, 4 );	
	
	COUT << "The Disjoint Set after Union operations:" << ENDL;
	COUT << disjointSet << ENDL << ENDL;

	checkConnected( disjointSet, 0, 1 );	
	checkConnected( disjointSet, 3, 9 );	
	checkConnected( disjointSet, 0, 9 );
	
	return 0;
	
}