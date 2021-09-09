#include <stdio.h>
#include <stdlib.h>

typedef struct node{

	int value;
	struct node* next_node;

} node;


int main( void ){

	node* first_node = (node *)malloc( sizeof( node ) );

	node* second_node = (node *)malloc( sizeof(node) );

	first_node->value = 10;
	second_node->value = 15;

	first_node->next_node = second_node;
	second_node->next_node = NULL;

	node* iter = first_node;

	while( iter != NULL ){

		fprintf( stdout, "%d\n", iter->value );
		iter = iter->next_node;
	}

	return 0;
}
