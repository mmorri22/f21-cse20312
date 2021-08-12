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
	
	// Insert elements into the list
	insert( &the_list, 10 );
	insert( &the_list, -20 );
	insert( &the_list, 15 );
	insert( &the_list, -4 );
		
	// Iterator pointer 
	print_list( &the_list );
	
	return EXIT_SUCCESS;
	
}

