#include <stdio.h>
#include <stdlib.h>

struct sll_node{

	int data;
	struct sll_node* next_node;	
	
};

int main( void ){
	
	// Leave the head_node initially NULL for empty
	struct sll_node* head_node = NULL;
	
	fprintf( stdout, "head_node at register %p pointing to %p\n", 
		&head_node, head_node );
	
	
	return EXIT_SUCCESS;
}

