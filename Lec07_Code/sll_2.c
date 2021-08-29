#include <stdio.h>
#include <stdlib.h>

struct sll_node{

	int data;
	struct sll_node* next_node;	
	
};

int main( void ){
	
	// Leave the head_node initially NULL for empty
	struct sll_node* head_node = NULL;
	
	// Create a node and link
	struct sll_node* node_1 = ( struct sll_node* )malloc( sizeof( struct sll_node ) );
	node_1->data = 10;
	node_1->next_node = NULL;
	
	// Head node pointer is pointing to node_1
	head_node = node_1;
	
	fprintf( stdout, "head_node at register %p pointing to %p\n", 
		&head_node, head_node );
		
	fprintf( stdout, "node_1 at register %p pointing to %p\n",
		&node_1, node_1 );
		
	//fprintf( stdout, "node_1->data = %d, located at %p\n", node_1->data, &(node_1->data) );
	//fprintf( stdout, "node_1->next_node = %p, located at %p\n", node_1->next_node, &(node_1->next_node) );
	
	return EXIT_SUCCESS;
}

