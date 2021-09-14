#include "sllist.h"

void insert( sllist* the_list, int new_data ){

	// De-reference in order to allocate and preserve the memory 
	sll_node* new_node = ( sll_node* )malloc( sizeof( struct sll_node ) );
	
	// De-reference new_node and update data 
	new_node->data = new_data;
	
	// De-reference new_node and set the next pointer equal to NULL 
	new_node->next_node = NULL;

	// Dr. Morrison's Golden Rule of Pointers 
	if( the_list->head_node == NULL ){
		
		the_list->head_node = new_node;
		return;
	}
	
	sll_node* curr_node = the_list->head_node;
	
	while( curr_node->next_node != NULL ){
		
		curr_node = curr_node->next_node;
	
	}
	
	curr_node->next_node = new_node;

	
}


void push_front( sllist* the_list, int new_data ){

	sll_node* new_node = ( sll_node* )malloc( sizeof( sll_node ) );
	
	new_node->data = new_data;
	
	new_node->next_node = NULL;
	
	if( the_list->head_node == NULL ){
		
		the_list->head_node = new_node;
		return;
		
	}
	
	else{
		
		new_node->next_node = the_list->head_node;
		
		the_list->head_node = new_node;
	}
}

int pop_front( sllist* the_list ){
	
	if( the_list->head_node == NULL )
		return 0;
	
	sll_node* to_free = the_list->head_node;
	
	the_list->head_node = the_list->head_node->next_node;
	
	free( to_free );
	
	return 1;
	
}


void print_list( sllist* the_list ){
	
	sll_node* curr_ptr = the_list->head_node;
	
	while( curr_ptr != NULL ){
		
		fprintf( stdout, "Node at %p has data %d\n", curr_ptr, curr_ptr->data );
		
		curr_ptr = curr_ptr->next_node;
		
	}
	
}

void delete( sll_node** curr_node ){
	
	if( *curr_node == NULL )
		return;
	
	// Recursively call the next node 
	// Review: (*curr_node) de-references the pointer to pointer 
	// (*curr_node)->next_node gets the pointer to next_node
	// &( (*curr_node)->next_node ) passes the address to next_node
	delete( &( (*curr_node)->next_node ) );
	
	free( *curr_node );
	
}

