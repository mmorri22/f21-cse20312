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

void print_nodes( struct sll_node* head_node ){

	if( head_node == NULL )
		return;

	struct sll_node* curr_ptr = head_node;

	while( curr_ptr != NULL ){

		fprintf( stdout, "%d\n", curr_ptr->data );

		curr_ptr = curr_ptr->next;
	}

}

int main( void ){

	struct sll_node* node_1 = ( struct sll_node* ) malloc ( sizeof( struct sll_node  ) ); 

	struct sll_node* node_2 = ( struct sll_node* ) malloc ( sizeof( struct sll_node  ) );
	
	struct sll_node* node_3 = ( struct sll_node* ) malloc ( sizeof( struct sll_node  ) );

	node_1->data = 15;
	node_2->data = 7;
	node_3->data = -99;

	link_nodes( node_1, node_2 );	
	link_nodes( node_2, node_3 );	
	
	print_nodes( node_1 );
	
	free( node_1 );
	free( node_2 );
	free( node_3 );

	return 0;
}
