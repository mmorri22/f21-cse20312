#include <stdio.h>
#include <stdlib.h>

typedef struct sll_node{

	int data;
	struct sll_node* next_node;	
	
}sll_node;

// Step 3 - Create the struct for sllist
typedef struct sllist{

	// Make the private sll_node member called head_node
	struct sll_node* head_node;
	
}sllist;


// Step 6 - Create the constructor method for sllist 
void insert( sllist* the_list, int the_value ){
	
	// Create a sll_node pointer called insert_node
	sll_node* insert_node = (sll_node*)malloc( sizeof(sll_node) );
	
	// Set the insert_node's data to the_value and next_node to NULL 
	insert_node->data = the_value;
	insert_node->next_node = NULL;
	
	// Dr. Morrison's Golden Rule of Pointers 
	// Check if the list is empty
	if( the_list->head_node == NULL ){
		
		// Set the head node equal to insert_node 
		the_list->head_node = insert_node;
		
		// And return
		return;
	}
	
	// Otherwise, create a curr_ptr equal to the head_node 
	sll_node* curr_ptr = the_list->head_node;
	
	// Iterate until the next_node is NULL
	while( curr_ptr->next_node != NULL ){
		
		curr_ptr = curr_ptr->next_node;
	}
	
	// Set curr_ptr's next_node equal to insert_node
	curr_ptr->next_node = insert_node;
	
}

// Step 13 - Push Front 
void push_front( sllist* the_list, int the_value ){
	
	// 13 - 1 We can copy everything up through the empty head node from Insert 
	
	// Create a sll_node pointer called insert_node
	sll_node* insert_node = (sll_node*)malloc( sizeof(sll_node) );
	
	// Set the insert_node's data to the_value and next_node to NULL 
	insert_node->data = the_value;
	insert_node->next_node = NULL;
	
	// Dr. Morrison's Golden Rule of Pointers 
	// Check if the list is empty
	if( the_list->head_node == NULL ){
		
		// Set the head node equal to insert_node 
		the_list->head_node = insert_node;
		
		// And return
		return;
	}
	
	// 13-2 Now we just need to use a reference pointer and put them in front
	sll_node* reference = the_list->head_node;
	
	// Set the head_node to the new node 
	the_list->head_node = insert_node;
	
	// Set the new head_node's next to the reference 
	the_list->head_node->next_node = reference;
	
}

// Step 8 - Print the Singly Linked List 
void print_list( sll_node* head_node ){
	
	// We can just copy and paste from sllist_part2.c
	
	// Just change node_0 to head_node

	sll_node* curr_ptr = head_node;
	while( curr_ptr != NULL ){
		
		// Step 17 - Only print the value
		fprintf( stdout, "%d ", curr_ptr->data );		

		// Iterate through the next node
		curr_ptr = curr_ptr->next_node;

	}
	fprintf( stdout, "\n" );

}	


// Step 10 - Free all the elements 
void destructor( sll_node* curr_ptr ){
	
	// Dr. Morrison's Golden Rule of Pointers 
	if( curr_ptr == NULL )
		return;
	

	// Recursively call destructor on the next node  
	destructor( curr_ptr->next_node );
		
	// Free the current pointer 
	free( curr_ptr );
	
}


// Step 15 - Pop Front 
void pop_front( sllist* the_list ){
	
	// Check if the list is not empty
	if( the_list->head_node == NULL )
		return;
	
	// Otherwise, move the node and free
	// Set a reference pointer to head_node
	sll_node* reference = the_list->head_node;
	
	// Set the head_node to head_node's next_node;
	the_list->head_node = the_list->head_node->next_node;
	
	// Free the reference 
	free( reference );
	
}


int main( const int argc, const char* argv[] ){

	
	// Step 4 - Dynamically allocate a sllist 
	sllist* the_list = (sllist *)malloc( sizeof( sllist ) );
	
	// Step 4-1 - Set the head_node to NULL 
	the_list->head_node = NULL;
	
	
	// Step 14 - Replace 11 - Call push_front with as many as we want to insert
	int iter;
	for( iter = 1; iter < argc; ++iter ){
		
		int the_value = atoi( argv[iter] );
		
		push_front( the_list, the_value );
		
	}
	
	
	// Step 9 - Call in main
	print_list( the_list->head_node );
	
	
	// Step 16 - We are going to iterate and print 
	while( the_list->head_node != NULL ){
		
		pop_front( the_list );
		
		print_list( the_list->head_node );
		
	}

	
	// Step 11 - Call the destructor
	destructor( the_list->head_node );

	
	// Step 5 - Free the sllist 
	free( the_list );
	
	return EXIT_SUCCESS;
}