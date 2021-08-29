#include <stdio.h>
#include <stdlib.h>

struct sll_node{

	int data;
	struct sll_node* next_node;	
	
};

struct sllist{
	
	struct sll_node* head_node;
	
};

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
	
	// Leave the head_node initially NULL for empty
	struct sllist the_list = { NULL };
	
	// Push elements into the list
	push_front( &the_list, 10 );
	push_front( &the_list, -20 );
	push_front( &the_list, 15 );
	push_front( &the_list, -4 );
		
	// Iterator pointer 
	print_list( &the_list );
	
	// Delete the list 
	delete( &(the_list.head_node) );
	
	return EXIT_SUCCESS;
	
}

