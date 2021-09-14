#include <stdio.h>
#include <stdlib.h>

// Step 1 - sll_node struct goes here
typedef struct sll_node{

	int data;
	struct sll_node* next_node;	
	
}sll_node;

typedef struct sllist{
	
	struct sll_node* head_node;
	
} sllist;

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

	// De-reference in order to allocate and preserve the memory 
	sll_node* new_node = ( sll_node* )malloc( sizeof( sll_node ) );
	
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

int pop_front( sllist* the_list ){
	
	// Dr. Morrison's Golden Rule of Pointers 
	if( the_list->head_node == NULL )
		return 0;
	
	// Create a temporary pointer pointing to the head node 
	sll_node* to_free = the_list->head_node;
	
	// move the head node pointer to the next node 
	the_list->head_node = the_list->head_node->next_node;
	
	// free the node pointing to the temporary node 
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

// Need ** so freeing the pointer is preserved 
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


int main( void ){
	
	// Step 2-1 - Create and Free four sll_nodes with dynamic memory allocation
	sll_node* node_0 = (sll_node*)malloc( sizeof(sll_node) );
	sll_node* node_1 = (sll_node*)malloc( sizeof(sll_node) );
	sll_node* node_2 = (sll_node*)malloc( sizeof(sll_node) );
	sll_node* node_3 = (sll_node*)malloc( sizeof(sll_node) );
	
	// Step 2-2 - Make their values 10, -20, 15, and 4 and link them in that order
	node_0->data = 10;
	node_1->data = -20;
	node_2->data = 15;
	node_3->data = 4;
	
	// Step 2-3 - Point to the next one in this order, and set the last to NULL
	node_0->next_node = node_1;
	node_1->next_node = node_2;
	node_2->next_node = node_3;
	node_3->next_node = NULL;
	
	// Step 2-4 - Print iterating through them
	// 1) Address of the node, 2) the address of the int
	// 3) the int itself, and 4) the address pointed to by the next node
	// Hint: Think about the void* version of “Hello, World
	sll_node* curr_ptr = node_0;
	while( curr_ptr != NULL ){
		
		fprintf( stdout, "%p %p %d %p\n", curr_ptr, &(curr_ptr->data), 
				curr_ptr->data, curr_ptr->next_node );
				
		curr_ptr = curr_ptr->next_node;
	}
	fprintf( stdout, "\n" );
	
	// Step 2-5 -  Free four sll_nodes with dynamic memory allocation
	free( node_0 );
	free( node_1 );
	free( node_2 );
	free( node_3 );
	
	
	// Leave the head_node initially NULL for empty
	struct sllist the_list = { NULL };
	
	// Push elements into the list
	push_front( &the_list, 10 );
	push_front( &the_list, -20 );
	push_front( &the_list, 15 );
	push_front( &the_list, -4 );
		
	// Iterator pointer 
	print_list( &the_list );
	
	// Pop and Print 
	while( pop_front( &the_list ) ){
	
		print_list( &the_list );
		
		fprintf( stdout, "-----------\n" );
	
	}
	
	// Delete the list 
	delete( &(the_list.head_node) );
	
	return EXIT_SUCCESS;
	
}

