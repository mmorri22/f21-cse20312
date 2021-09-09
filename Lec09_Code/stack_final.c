#include <stdio.h>
#include <stdlib.h>

struct sll_node{

	int data;
	struct sll_node* next_node;	
	
};

struct stack{
	
	struct sll_node* head_node;
	
};


void push( struct stack* the_stack, int new_data ){

	// De-reference in order to allocate and preserve the memory 
	struct sll_node* new_node = ( struct sll_node* )malloc( sizeof( struct sll_node ) );
	
	// De-reference new_node and update data 
	new_node->data = new_data;
	
	// De-reference new_node and set the next pointer equal to NULL 
	new_node->next_node = NULL;
	
	
	// Dr. Morrison's Golden Rule of Pointers
	if( the_stack->head_node == NULL ){
		
		the_stack->head_node = new_node;
		return;
		
	}
	
	else{
		
		new_node->next_node = the_stack->head_node;
		
		the_stack->head_node = new_node;
	}
}


// Assumes valid call 
int top( struct stack* the_stack ){
	
	return the_stack->head_node->data;
	
}


int pop( struct stack* the_stack ){
	
	// Dr. Morrison's Golden Rule of Pointers 
	if( the_stack->head_node == NULL )
		return 0;
	
	// Create a temporary pointer pointing to the head node 
	struct sll_node* to_free = the_stack->head_node;
	
	// move the head node pointer to the next node 
	the_stack->head_node = the_stack->head_node->next_node;
	
	// free the node pointing to the temporary node 
	free( to_free );
	
	return 1;
	
}


void print_list( struct stack* the_stack ){
	
	struct sll_node* curr_ptr = the_stack->head_node;
	
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
	struct stack the_stack = { NULL };
	
	// Push elements into the list
	push( &the_stack, 10 );
	push( &the_stack, -20 );
	push( &the_stack, 15 );
	push( &the_stack, -4 );
		
	// Iterator pointer 
	print_list( &the_stack );
	
	// Pop and Print 
	fprintf( stdout, "Removing %d........\n", top( &the_stack ) );
	while( pop_front( &the_stack ) ){
	
		print_list( &the_stack );
		
		fprintf( stdout, "-----------\n" );
		fprintf( stdout, "Removing %d......\n", top( &the_stack ) );
	
	}
	
	// Delete the list 
	// Will still work, even if empty 
	// Because we followed Dr. Morrison's Golden Rule of Pointers
	delete( &(the_stack.head_node) );
	
	return EXIT_SUCCESS;
	
}

