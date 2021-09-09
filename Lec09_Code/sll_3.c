#include <stdio.h>
#include <stdlib.h>

struct sll_node{

	int data;
	struct sll_node* next_node;	
	
};

// Review: ** means we have a POINTER passed by reference 
void init_sll_node( struct sll_node** curr_node, int new_data ){
	
	// De-reference in order to allocate and preserve the memory 
	*curr_node = ( struct sll_node* )malloc( sizeof( struct sll_node ) );
	
	// De-reference curr_node and update data 
	(*curr_node)->data = new_data;
	
	// De-reference curr_node and set the next pointer equal to NULL 
	(*curr_node)->next_node = NULL;
	
}


void link_nodes( struct sll_node** curr_node, struct sll_node* next_node ){
	
	(*curr_node)->next_node = next_node;
	
}

void print_list( struct sll_node* head_node ){
	
	struct sll_node* curr_ptr = head_node;
	
	while( curr_ptr != NULL ){
		
		fprintf( stdout, "Node at %p has data %d\n", curr_ptr, curr_ptr->data );
		
		curr_ptr = curr_ptr->next_node;
		
	}
	
}

int main( void ){
	
	// Leave the head_node initially NULL for empty
	struct sll_node* head_node = NULL;
	
	// Create four nodes and link
	struct sll_node* node_1; 
	struct sll_node* node_2; 
	struct sll_node* node_3; 
	struct sll_node* node_4;
	init_sll_node( &node_1, 10 );
	init_sll_node( &node_2, -20 );
	init_sll_node( &node_3, 15 );
	init_sll_node( &node_4, -4 );
	
	// Have head_node point to node_1 
	head_node = node_1;
	
	// Link the rest of the nodes 
	link_nodes( &node_1, node_2 );
	link_nodes( &node_2, node_3 );
	link_nodes( &node_3, node_4 );
	
	fprintf( stdout, "head_node at register %p pointing to %p\n", 
		&head_node, head_node );
		
	// Iterator pointer 
	print_list( head_node );
	
	
	return EXIT_SUCCESS;
	
}

