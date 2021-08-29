#include <stdio.h>
#include <stdlib.h>

struct sll_node{

	int data;
	struct sll_node* next_node;	
	
};

struct sllist{
	
	struct sll_node* head_node;
	
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


void link_nodes( struct sllist* the_list, struct sll_node* next_node ){
	
	// Dr. Morrison's Golden Rule of Pointers 
	if( the_list->head_node == NULL ){
		
		the_list->head_node = next_node;
		return;
	}
	
	struct sll_node* curr_node = the_list->head_node;
	
	while( curr_node->next_node != NULL ){
		
		curr_node = curr_node->next_node;
	
	}
	
	curr_node->next_node = next_node;
	
}

void print_list( struct sllist* the_list ){
	
	struct sll_node* curr_ptr = the_list->head_node;
	
	while( curr_ptr != NULL ){
		
		fprintf( stdout, "Node at %p has data %d\n", curr_ptr, curr_ptr->data );
		
		curr_ptr = curr_ptr->next_node;
		
	}
	
}

int main( void ){
	
	// Leave the head_node initially NULL for empty
	struct sllist the_list = { NULL };
	
	// Create four nodes and link
	struct sll_node* node_1; 
	struct sll_node* node_2; 
	struct sll_node* node_3; 
	struct sll_node* node_4;
	init_sll_node( &node_1, 10 );
	init_sll_node( &node_2, -20 );
	init_sll_node( &node_3, 15 );
	init_sll_node( &node_4, -4 );
	
	// Link the rest of the nodes 
	link_nodes( &the_list, node_1 );
	link_nodes( &the_list, node_2 );
	link_nodes( &the_list, node_3 );
	link_nodes( &the_list, node_4 );
		
	// Iterator pointer 
	print_list( &the_list );
	
	
	return EXIT_SUCCESS;
	
}

