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
	
	checkConnected( disjointSet, 0, 1 );
	checkConnected( disjointSet, 2, 1 );	
	checkConnected( disjointSet, 6, 5 );
	checkConnected( disjointSet, 3, 8 );
	checkConnected( disjointSet, 3, 9 );
	
}

void numConnectedComponents( Graph<int>& disjointSet ){
	
	COUT << ENDL << "The Graph contains "; 
	
	COUT << disjointSet.numConnected();
	
	COUT << " connected components." << ENDL;

}


void unionTest( Graph<int>& disjointSet ){
	
	disjointSet.Union( 0, 1 );
	
	COUT << "The Disjoint Set after Union(0,1):" << ENDL;
	COUT << disjointSet << ENDL;
	
	numConnectedComponents( disjointSet );
	
	disjointSet.Union( 2, 7, 3 );	
	
	COUT << ENDL << "The Disjoint Set after Union(2,7):" << ENDL;
	COUT << disjointSet << ENDL;
	
	numConnectedComponents( disjointSet );
	
	disjointSet.Union( 3, 8, 4 );
	
	COUT << ENDL << "The Disjoint Set after Union( 3, 8 ):" << ENDL;
	COUT << disjointSet << ENDL << ENDL;

	numConnectedComponents( disjointSet );
	
	disjointSet.Union( 3, 9, 4 );	
	
	COUT << ENDL << "The Disjoint Set after Union( 3, 9 ):" << ENDL;
	COUT << disjointSet << ENDL << ENDL;

	checkConnected( disjointSet, 0, 1 );	
	checkConnected( disjointSet, 3, 9 );	
	checkConnected( disjointSet, 0, 9 );
	
}


int main(){
	
	Graph< int > disjointSet;
	
	initializeGraph( disjointSet );
	
	numConnectedComponents( disjointSet );
	
	COUT << ENDL;
	
	unionTest( disjointSet );
	
	numConnectedComponents( disjointSet );
	
	return 0;
	
}