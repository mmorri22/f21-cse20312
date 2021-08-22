#include <stdio.h>
#include <stdlib.h>

/* Data Element with a sizeof() = 30 */
struct data_node{

	char first_char;
	char second_char;
	int first_int;
	int second_int;
	float float_data;
	double double_data;
	long unsigned int lui_data;
	
};

struct sll_node{

	struct data_node data;
	struct sll_node* next_node;	
	
};

struct sllist{
	
	struct sll_node* head_node;
	
};

struct vector{

	long unsigned int length;
	long unsigned int capacity;
	struct data_node* the_array;

};

/* Notice how I pass the data by reference! Reduce the memory */
/* Compare to sll_8.c, where we only do int */
/* int = 4 bytes, data_node = 30 bytes, data_node* = 8 bytes */
void insert( struct sllist* the_list, data_node* new_data ){

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


int main( void ){
	
	fprintf( stdout, "Size of int = %lu, size of int pointer  = %lu\n", 
		sizeof( int ), sizeof( int* ) );
	
	fprintf( stdout, "Size of data_node = %lu, size of data_node pointer  = %lu\n", 
		sizeof( struct data_node ), sizeof( struct data_node* ) );
	
	/* Example of Worst-Case Vector with 5 elements and capacity of 8 */
	long unsigned int length = 5;
	long unsigned int capacity = 8;
	struct vector data_node_vector = {length, capacity, 
		( struct data_node *)malloc( capacity * sizeof( struct data_node ) ) };
		
	
	
	return 0;
	
}