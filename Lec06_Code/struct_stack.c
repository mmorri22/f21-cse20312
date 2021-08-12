#include <stdio.h>
#include <stdlib.h>

struct sll_node{

	int data;
	struct sll_node* next;	
	
};


void link_nodes( struct sll_node* curr_node, struct sll_node* next_node ){

	if( next_node != NULL )
		curr_node->next = next_node;

}

void push_back( struct sll_node** head_node, int data_to_link ){
	
	struct sll_node* new_node = ( struct sll_node* ) malloc ( sizeof(int) + sizeof( struct sll_node * ) ); 
	
	/* Initialize Data and next as NULL */
	new_node->data = data_to_link;
	new_node->next = NULL;
	
	if( *head_node == NULL ){
		
		*head_node = new_node;
		return;
	}
	
	struct sll_node* curr_ptr = *head_node;
	
	while( curr_ptr->next != NULL ){
		
		fprintf( stdout, "Hi?\n");
		
		curr_ptr = curr_ptr->next;
		
	}
	
	curr_ptr->next = new_node;
	
}

void push_front( struct sll_node** head_node, int data_to_link ){
	
	struct sll_node* new_node = ( struct sll_node* ) malloc ( sizeof(int) + sizeof( struct sll_node * ) );
	
	/* Initialize Data and next as NULL */
	new_node->data = data_to_link;
	new_node->next = NULL;

	if( *head_node == NULL ){

		*head_node = new_node;
		return;
	}
	
	/* If head_node is not NULL */
	// Link new_node's next to head 
	new_node->next = *head_node;
	
	// Set head_node equal to new_node
	*head_node = new_node;
	
}

void print_nodes( struct sll_node* head_node ){

	if( head_node == NULL )
		return;

	struct sll_node* curr_ptr = head_node;

	while( curr_ptr != NULL ){

		fprintf( stdout, "%d\n", curr_ptr->data );

		curr_ptr = curr_ptr->next;
	}

}

void free_list_memory( struct sll_node* curr_node ){
	
	if( curr_node == NULL ){
		
		return;
	}
	
	if( curr_node->next != NULL ){
		
		free_list_memory( curr_node->next );
	}
	
	free( curr_node );
}

int main( void ){
	
	// Leave NULL: Pointer, not a node itself
	struct sll_node* head_node = NULL; 
	
	char read_char = 'y';
	while( read_char == 'y' ){
		
		int read_int;
		fprintf( stdout, "Enter an integer: ");
		fscanf( stdin, "%d", &read_int );
		
		// push_back( &head_node, read_int );
		push_front( &head_node, read_int );
		
		// Flush the input buffer
		getchar();

		fprintf( stdout, "Do you wish to continue? (y for yes): ");
		fscanf( stdin, "%c", &read_char );
		
	}	
	
	print_nodes( head_node );
	
	free_list_memory( head_node );

	return 0;
}
