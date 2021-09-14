#include <stdio.h>
#include <stdlib.h>

// Step 1 - Code Together - sll_node struct


// Step 3 - Code Together - sllist struct



void insert( struct sllist* the_list, int new_data ){

	// De-reference in order to allocate and preserve the memory 
	struct sll_node* new_node = ( struct sll_node* )malloc( sizeof( struct sll_node ) );
	
	// De-reference new_node and update data 
	new_node->data = new_data;
	
	// De-reference new_node and set the next pointer equal to NULL 
	new_node->next_node = NULL;

	// Dr. Morrison's Golden Rule of Pointers 
	if( the_list->head_node == NULL ){
		
		the_list->head_node = new_node;
		return;
	}
	
	struct sll_node* curr_node = the_list->head_node;
	
	while( curr_node->next_node != NULL ){
		
		curr_node = curr_node->next_node;
	
	}
	
	curr_node->next_node = new_node;

	
}


void push_front( struct sllist* the_list, int new_data ){

	// De-reference in order to allocate and preserve the memory 
	struct sll_node* new_node = ( struct sll_node* )malloc( sizeof( struct sll_node ) );
	
	// De-reference new_node and update data 
	new_node->data = new_data;
	
	// De-reference new_node and set the next pointer equal to NULL 
	new_node->next_node = NULL;
	
	
	// Dr. Morrison's Golden Rule of Pointers
	if( the_list->head_node == NULL ){
		
		the_list->head_node = new_node;
		return;
		
	}
	
	else{
		
		new_node->next_node = the_list->head_node;
		
		the_list->head_node = new_node;
	}
}

int pop_front( struct sllist* the_list ){
	
	// Dr. Morrison's Golden Rule of Pointers 
	if( the_list->head_node == NULL )
		return 0;
	
	// Create a temporary pointer pointing to the head node 
	struct sll_node* to_free = the_list->head_node;
	
	// move the head node pointer to the next node 
	the_list->head_node = the_list->head_node->next_node;
	
	// free the node pointing to the temporary node 
	free( to_free );
	
	return 1;
	
}


void print_list( struct sllist* the_list ){
	
	struct sll_node* curr_ptr = the_list->head_node;
	
	while( curr_ptr != NULL ){
		
		fprintf( stdout, "Node at %p has data %d\n", curr_ptr, curr_ptr->data );
		
		curr_ptr = curr_ptr->next_node;
		
	}
	
}

// Need ** so freeing the pointer is preserved 
void delete( struct sll_node** curr_node ){
	
	if( *curr_node == NULL )
		return;
	
	// Recursively call the next node 
	// Review: (*curr_node) de-references the pointer to pointer 
	// (*curr_node)->next_node gets the pointer to next_node
	// &( (*curr_node)->next_node ) passes the address to next_node
	delete( &( (*curr_node)->next_node ) );
	
	free( *curr_node );
	
}


int main( void ){
	
	// Step 2 - On Your Own
	// Step 2-1 - Create and Free four sll_nodes with dynamic memory allocation
	
	// Step 2-2 - Make their values 10, -20, 15, and 4 and link them in that order
	
	// Step 2-3 - Point to the next one in this order, and set the last to NULL
	
	// Step 2-4 - Print iterating through them
	// 1) Address of the node, 2) the address of the int
	// 3) the int itself, 4) the address of the pointer to the next node
	// and 5) the address the next node points to 
	// Hint: Think about the void* version of “Hello, World
	
	// Step 2-5 -  Free four sll_nodes with dynamic memory allocation
	
	
	// Step 4 - Code Together - Create a sllist - 

	
	return EXIT_SUCCESS;
	
}

