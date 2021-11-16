#ifndef GRAPH7_H
#define GRAPH7_H

#include "Vertex.h"
#include <stack>
#include <iostream>
#include <vector>

template<class T>
class Graph{
	
	private:
	
		// Private DFS method
		bool DFS( unsigned int destin, unsigned int vertVal, std::vector<unsigned int>& parents, std::vector<bool>& visited ){
				
			if( !visited[ vertVal ] ){
				
				// Set the visited edges to true
				visited[ vertVal ] = true;
				
				// Check each outgoing edge 
				for( unsigned int iter = 0; iter < vertices[ vertVal ].num_edges(); iter++ ){
					
					// Obtain a temporary copy of the Edge
					Edge tempEdge = vertices[ vertVal ].get_edge( iter );
					
					// If the destination has not been visited, make recursive call
					if( !visited[ tempEdge.destin ] ){
						
						// Set the destination's parent to vertVal
						parents[ tempEdge.destin ] = vertVal;
						
						// If we found the vertex, return true
						if( tempEdge.destin == destin ){
							
							return true;
						}
						
						// Otherwise, recursively call the destination vertex
						bool check = DFS( destin, tempEdge.destin, parents, visited );
						
						if( check ){
							
							return true;
						}
					}
					
				}
			}
			
			return false;
				
		}
		
		
		// Private DFS method
		void TopSort( unsigned int vertVal, std::vector<unsigned int>& parents, std::vector<bool>& visited ){
				
			if( !visited[ vertVal ] ){
				
				// Set the visited edges to true
				visited[ vertVal ] = true;
				
				// Check each outgoing edge 
				for( unsigned int iter = 0; iter < vertices[ vertVal ].num_edges(); iter++ ){
					
					// Obtain a temporary copy of the Edge
					Edge tempEdge = vertices[ vertVal ].get_edge( iter );
					
					// If the destination has not been visited, make recursive call
					if( !visited[ tempEdge.destin ] ){
						
						// Set the destination's parent to vertVal
						parents[ tempEdge.destin ] = vertVal;
						
						// Otherwise, recursively call the destination vertex
						TopSort( tempEdge.destin, parents, visited );
						
					}
				}
			}
		}
	
		std::vector< Vertex< T > > vertices;	// Adjacency Lisy
		
	public:
		// Constructor
		Graph( ) : vertices() {}
		
		// Add a vertex prior to any edges
		void add_vertex( T vertexData ){
			
			Vertex<T> theVertex( vertexData );
			vertices.push_back( theVertex );
		}
		
		// Add Edge from Origin to Destination, with weight
		void add_edge(unsigned int origin, unsigned int destin, int weight ){
			if( origin < vertices.size() && destin < vertices.size() ){
			
				vertices[origin].add_edge( destin, weight );
		
			}
		}
		
		// Returns the number of vertices in the Graph
		long unsigned int get_num_vertices(){
			
			return vertices.size();
		}
		
		// Return the value with a Call by Reference
		// bool for if the vertex requested was valid
		bool get_vertex_value( unsigned int vertex, T& value ){
			
			if( vertex < vertices.size() ){
				
				value = vertices.at(vertex).get_vertex_value();
				return true;
			}
			
			return false;
			
		}
		
		// Set the value at a given vertex 
		// bool for if the vertex requested was valid
		bool set_vertex_value( unsigned int vertex, T& value ){
						
			if( vertex < vertices.size() ){
				
				value = vertices[vertex].set_vertex_value( value );
				return true;
			}			
			return false;
		}
		
		// Return the value with a Call by Reference
		// bool for if the origin and destination requested were valid
		bool get_edge_value( unsigned int origin, unsigned int destin, int& weight){
				
			if( origin < vertices.size() && destin < vertices.size() ){
				
				return vertices[origin].get_edge_value( destin, weight );
			}
			
			return false;
		}
		
		// Set the value at a given origin and destination 
		// bool for if the origin and destination requested were valid
		bool set_edge_value( unsigned int origin, unsigned int destin, int weight){
				
			if( origin < vertices.size() && destin < vertices.size() ){
				
				return vertices[origin].set_edge_value( destin, weight );
			}
			
			return false;
		}
		
		// Remove an edge
		bool remove_edge( unsigned int origin, unsigned int destin){
				
			// If the origin and destination are valid
			if( origin < vertices.size() && destin < vertices.size() ){
				
				// From the Origin vertex, remove the destination vertex
				return vertices[origin].remove_edge( destin );
			}
			
			return false;
		}
		
		
		void remove_vertex( unsigned int vertVal ){
			
			// First, perform Lazy Deletion on the vertex 
			vertices[ vertVal ].lazy_delete();
			
			// Next, go through each vertex and remove all edges with the destination to the vertex 
			for( unsigned int iter = 0; iter < vertices.size(); iter++ ){
				
				int jter = 0;
				
				// While the increment is less than the number of edges
				while( jter < vertices[iter].num_edges() ){
					
					// If the destination of the edge is the vertex we are removing
					if( vertices[iter].get_edge( jter ).destin == vertVal ){
						
						// Remove that edge
						vertices[iter].remove_edge( vertVal );
					}
					else{
						// Only increment jter is there is not any deletion
						jter++;
					}
				}
			}
		}
		
		
		// Public DFS Method
		void DFS( unsigned int destin ){
			
			// If the input is invalid or the Graph is empty
			if( destin >= vertices.size() || vertices.size() == 0){
				
				std::cout << "Invalid inputs to DFS" << std::endl;
				
				return;
			}
			
			/* Initialize the Values for the DFS */
			
			// Track the parents for printing the results
			std::vector<unsigned int> parents(vertices.size());
			
			// Keep track of the visited vertices
			std::vector<bool> visited(vertices.size());
			
			// Create a std::stack to store the final path
			std::stack< unsigned int > finalPath;
			bool found = false;

			// Initialize the search	
			parents[0] = -1;
			
			// Set all the visited elements to false
			for( unsigned int iter = 0; iter < vertices.size(); iter++ ){
				visited[iter] = false;
			}
			
			// If the destination is the origin, mark found as true
			if( destin == 0 ){
				
				found = true;
				
			}
			
			// Otherwise, run the recursive DFS 
			else{

				found = DFS( destin, 0, parents, visited );
			
			}
			
			// If we have not found the node, there is no path
			if( !found ){
				
				std::cout << "No valid path from 0 to " << destin << std::endl;
				return;
			}
			
			// Otherwise, go through the parents until we find the origin
			unsigned int sentinel = destin;	
			finalPath.push( sentinel );		// Push the desination onto the std::stack
			
			while( parents[sentinel] != -1 ){
				
				finalPath.push( parents[sentinel] );	// Push the parent onto the std::stack
				sentinel = parents[sentinel];			// Update the sentinel
				
			}
			
			// Stack contains the correct order 
			std::cout << "The valid DFS path from 0 to " << destin << " is: ";
			while( !finalPath.empty() ){
				
				std::cout << finalPath.top() << " ";
				finalPath.pop();
			}
			std::cout << std::endl;
				
			
		}
		
		
		// Public DFS Method
		void DFS( unsigned int origin, unsigned int destin ){
			
			// If the input is invalid or the Graph is empty
			if( origin >= vertices.size() || destin >= vertices.size() || vertices.size() == 0){
				
				std::cout << "Invalid inputs to DFS" << std::endl;
				
				return;
			}
			
			/* Initialize the Values for the DFS */
			
			// Track the parents for printing the results
			std::vector<unsigned int> parents(vertices.size());
			
			// Keep track of the visited vertices
			std::vector<bool> visited(vertices.size());
			
			// Create a std::stack to store the final path
			std::stack< unsigned int > finalPath;
			bool found = false;

			// Initialize the search	
			parents[ origin ] = -1;
			
			// Set all the visited elements to false
			for( unsigned int iter = 0; iter < vertices.size(); iter++ ){
				visited[iter] = false;
			}
			
			// If the destination is the origin, mark found as true
			if( destin == origin ){
				
				found = true;
				
			}
			
			// Otherwise, run the recursive DFS 
			else{

				found = DFS( destin, origin, parents, visited );
			
			}
			
			// If we have not found the node, there is no path
			if( !found ){
				
				std::cout << "No valid path from " << origin << " to " << destin << std::endl;
				return;
			}
			
			// Otherwise, go through the parents until we find the origin
			unsigned int sentinel = destin;	
			finalPath.push( sentinel );		// Push the desination onto the std::stack
			
			while( parents[sentinel] != -1 ){
				
				finalPath.push( parents[sentinel] );	// Push the parent onto the std::stack
				sentinel = parents[sentinel];			// Update the sentinel
				
			}
			
			// Stack contains the correct order 
			std::cout << "The valid DFS path from " << origin << " to " << destin << " is: ";
			while( !finalPath.empty() ){
				
				std::cout << finalPath.top() << " ";
				finalPath.pop();
			}
			std::cout << std::endl;
				
			
		}
		
		
		// Method for Topological Sort
		Graph<T> TopSort( ){
			
			/* Initialize the Values for the Topological Sort */
			
			/* Initialize the return Graph */
			Graph<T> TopSortGraph;
			
			for( unsigned int iter = 0; iter < vertices.size(); iter++ ){
				
				// Add the value of each vertex to the TopSort graph
				TopSortGraph.add_vertex( vertices[ iter ].get_vertex_value() );
				
			}
			
			// Track the parents for printing the results
			std::vector<unsigned int> parents(vertices.size());
			
			// Keep track of the visited vertices
			std::vector<bool> visited(vertices.size());
			
			// Create a std::stack to store the final path
			std::stack< unsigned int > finalPath;
			
			// Set all the visited elements to false
			for( unsigned int iter = 0; iter < vertices.size(); iter++ ){
				visited[iter] = false;
				parents[iter] = -1;
			}
			
			// Run the Topological Sort - We must check every element 
			for(unsigned int iter = 0; iter < vertices.size(); iter++ ){
				TopSort( iter, parents, visited );
			}
			
			// Add all the edges from the parent to the Graph 
			for( unsigned int iter = 1; iter < vertices.size(); iter++ ){
				
				// Get the edge weight 
				int edgeWeight = 0;
				get_edge_value( parents[iter], iter, edgeWeight );
				
				// Add the Edge
				TopSortGraph.add_edge(parents[iter], iter, edgeWeight );
			}
			
			return TopSortGraph;
		}
		
		
		// Dijkstra's Algorithm
		void Dijkstra( unsigned int destin ){
			
			
			if( destin >= vertices.size() || vertices.size() == 0 ){
				
				std::cout << "Invalid Inputs" << std::endl;
				return;
				
			}
			
			/* Initialize the Elements */
			std::stack< unsigned int > theStack;
			std::vector< unsigned int > parents( vertices.size() );
			std::vector< int > distance;
			std::stack< unsigned int > finalPath;
			
			bool found = false;
			
			/* Initialize the origin */
			theStack.push( 0 );
			distance[0] = 0;
			parents[0] = -1;
			
			if( destin == 0 ){	
				found = true;
			}
			
			if( !found ){
				
				/* Initialize all the distances after the origin */
				for( unsigned int iter = 1; iter < vertices.size(); iter++ ){
					// Make it the largest possible int
					distance[ iter ] = 2147483647;
					// Set the parent to -1
					parents[ iter ] = -1;
				}
				
				/* Run the shortest path algorithm */
				while( !theStack.empty() ){
					
					// Get the top element of the std::stack and pop
					unsigned int index = theStack.top();
					theStack.pop();
					
					// Evaluate the edges from the vertex 
					for(unsigned int iter = 0; iter < vertices[ index ].num_edges(); iter++ ){
						
						// Obtain the edge
						Edge tempEdge = vertices[ index ].get_edge( iter );
						
						// If the weight of the edge plus distance of the  distance is less than the destin weight
						if( distance[ index ] + tempEdge.weight < distance[ tempEdge.destin ] ) {
							
							// Update the distance
							distance[ tempEdge.destin ] = distance[ index ] + tempEdge.weight;
							
							// Update the parent of the destin 
							parents[ tempEdge.destin ] = index;
							
							// Check if destin is the result;
							if( tempEdge.destin == destin && !found ){
								
								found = true;
							}
							
							theStack.push( tempEdge.destin );
						}
					}
				}
			}
			
			// Otherwise, go through the parents until we find the origin
			if( found ){
				
				unsigned int sentinel = destin;	
				finalPath.push( sentinel );		// Push the desination onto the std::stack
				
				while( parents[sentinel] != -1 ){
					
					finalPath.push( parents[sentinel] );	// Push the parent onto the std::stack
					sentinel = parents[sentinel];			// Update the sentinel
					
				}
				
				// Stack contains the correct order 
				std::cout << "The valid Dijkstra path from 0 to " << destin << " is: ";
				while( !finalPath.empty() ){
					
					std::cout << finalPath.top() << " ";
					finalPath.pop();
				}
				std::cout << ", and the distance is " << distance[destin] << std::endl;
				std::cout << std::endl;		
			}
			
		}

		
		// Overloaded Operator
		friend std::ostream& operator<<( std::ostream& output, const Graph<T>& theGraph ){
			
			for( unsigned int iter = 0; iter < theGraph.vertices.size(); iter++ ){
				
				output << iter << ": " << theGraph.vertices[ iter ] << std::endl;
				
			}
			
			return output;
		}
};

#endif
