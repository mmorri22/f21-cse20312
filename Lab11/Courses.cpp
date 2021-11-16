#include "Graph.h"
#include <iostream>
#include <string>

int main(){
    std::cout << "Test 1: " << std::endl;
	
    Graph<int> theGraph;
    // 10 vertices to add
    theGraph.add_vertex(0);     theGraph.add_vertex(1);     theGraph.add_vertex(2);
    theGraph.add_vertex(3);     theGraph.add_vertex(4);     theGraph.add_vertex(5);
    theGraph.add_vertex(6);     theGraph.add_vertex(7);		theGraph.add_vertex(8);
	theGraph.add_vertex(9);

    // Nodes from 0
    theGraph.add_edge(0,1,1);
	theGraph.add_edge(0,3,1);
    theGraph.add_edge(0,4,1);
	
    // Nodes from 1
    theGraph.add_edge(1,2,1);
    theGraph.add_edge(1,3,1);

    // Nodes from 2
    theGraph.add_edge(2,6,1);
	
    // Nodes from 3
    theGraph.add_edge(3,5,1);
	
    // Nodes from 5
    theGraph.add_edge(5,7,1);
	
    // Nodes from 6
    theGraph.add_edge(6,7,1);
	
    // Nodes from 8
    theGraph.add_edge(8,9,1);
	
	std::cout << theGraph << std::endl;
	
	Graph<int> TopSort1 = theGraph.TopSort();
	
	std::cout << "Topological Sort:" << std::endl;
	std::cout << TopSort1 << std::endl;

    // Run Depth-First research
    for (unsigned int i = 0; i < TopSort1.get_num_vertices(); ++i){
        TopSort1.DFS( i );
    }

    std::cout << std::endl << "Test 2: " << std::endl;
	
    std::cout << "Input: " << std::endl << "{ [0,1], [1,2], [0,2], [0, 3], [2, 4], [3, 4]}" << std::endl;
    Graph<int> theGraph2;
    // 8 vertices to add
    theGraph2.add_vertex(0);     theGraph2.add_vertex(1);     theGraph2.add_vertex(2);
    theGraph2.add_vertex(3);     theGraph2.add_vertex(4);

    // Nodes from 0
    theGraph2.add_edge(0,1,1);
    theGraph2.add_edge(0,2,1);
    theGraph2.add_edge(0,3,1);
    // Nodes from 1
    theGraph2.add_edge(1,2,1);
    // Nodes from 2
    theGraph2.add_edge(2,4,1);
    // Nodes from 3
    theGraph2.add_edge(3,4,1);

    // Run Depth-First research
    for (unsigned int i = 0; i < theGraph2.get_num_vertices(); ++i){
        theGraph2.DFS( i );
    }

    std::cout << std::endl << "Test 3: " << std::endl;
    std::cout << "Input: " << std::endl << "{ [Fund Com, Systems], [Fund Com, DS], [Fund Com, LD], [DS, Theory Com], [LD, Com Arch]}" << std::endl;
    Graph<std::string> theGraph3;
    // 8 vertices to add
    theGraph3.add_vertex("Fund Com");     theGraph3.add_vertex("Systems");     theGraph3.add_vertex("DS");
    theGraph3.add_vertex("Theory Com");     theGraph3.add_vertex("Com Arch");

    // Nodes from 0
    theGraph3.add_edge(0,1,1);
    theGraph3.add_edge(0,2,1);
    theGraph3.add_edge(0,3,1);
    // Nodes from 2
    theGraph3.add_edge(2,4,1);
    // Nodes from 3
    theGraph3.add_edge(3,5,1);

    // Run Depth-First research
    for (unsigned int i = 0; i < theGraph3.get_num_vertices(); ++i){
        theGraph3.DFS( i );
    }

    std::cout << std::endl << "Test 4: " << std::endl;
    std::cout << "Input: " << std::endl << "{ [A,C], [B,C], [C,D], [C,E], [E,F]}" << std::endl;
    Graph<char> theGraph4;
    // 8 vertices to add
    theGraph4.add_vertex('A');     theGraph4.add_vertex('B');     theGraph4.add_vertex('C');
    theGraph4.add_vertex('D');     theGraph4.add_vertex('E');     theGraph4.add_vertex('F');

    // Nodes from 0
    theGraph4.add_edge(0,2,1);
    // Nodes from 1
    theGraph4.add_edge(1,2,1);
    // Nodes from 2
    theGraph4.add_edge(2,3,1);
    theGraph4.add_edge(2,4,1);
    // Nodes from 4
    theGraph4.add_edge(4,5,1);

    // Run Depth-First research
    for (unsigned int i = 0; i < theGraph4.get_num_vertices(); ++i){
        theGraph4.DFS( i );
    }

    return 0;



}
