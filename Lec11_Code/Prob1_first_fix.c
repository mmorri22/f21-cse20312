#include <stdio.h>
#include <stdlib.h>

/* Singly Linked List Node */
typedef struct sll_node{

	char data;
	struct sll_node* next_node;	
	
}sll_node;


/* Singly Linked List Struct */
typedef struct sllist{

	struct sll_node* head_node;
	
}sllist;

/* Insert function for the sllist */
void insert( sllist* the_list, char the_value ){
	
	sll_node* insert_node = (sll_node*)malloc( sizeof(sll_node) );
	
	insert_node->data = the_value;
	insert_node->next_node = NULL;
	
	if( the_list->head_node == NULL ){
		
		the_list->head_node = insert_node;
		
		return;
	}
	
	sll_node* curr_ptr = the_list->head_node;
	
	while( curr_ptr->next_node != NULL ){
		
		curr_ptr = curr_ptr->next_node;
	}
	
	curr_ptr->next_node = insert_node;
	
}

/* Prints the address and value of each node */
void print_list( sll_node* head_node ){
	
	// We can just copy and paste from sllist_part2.c
	
	// Just change node_0 to head_node

	sll_node* curr_ptr = head_node;
	while( curr_ptr != NULL ){
		
		fprintf( stdout, "%p, ", curr_ptr );
		fprintf( stdout, "%p, ", &(curr_ptr->data) );
		fprintf( stdout, "%c, ", curr_ptr->data );		
		fprintf( stdout, "%p, ", &(curr_ptr->next_node) );
		fprintf( stdout, "%p\n", curr_ptr->next_node );

		// Iterate through the next node
		curr_ptr = curr_ptr->next_node;

	}
	fprintf( stdout, "\n" );

}	


/* Destructor function for the sllist */
void destructor( sll_node* curr_ptr ){
	
	if( curr_ptr == NULL )
		return;
	
	destructor( curr_ptr->next_node );
		
	free( curr_ptr );
}


int main( const int argc, const char* argv[] )
{
    
    /* Interpret argc / argc portion */
    fprintf( stdout, "%p %d\n", &argc, argc );
    fprintf( stdout, "%p %p\n", &argv, argv );
    
    int iter;
    for( iter = 0; iter < argc; ++iter ){
        
        fprintf( stdout, "%p %p: \n", &argv[iter], argv[iter] );
        
        int jter = 0;
        while( argv[iter][jter] != '\0' ){
            
            fprintf( stdout, "%p %c \n", &argv[iter][jter], argv[iter][jter] );
            ++jter;
            
        }
        
    }
    fprintf( stdout, "\n" );
    

    /* Interpret the_list portion */
    sllist* the_list = (sllist *)malloc( sizeof( sllist ) );
    
    the_list->head_node = NULL;
    
    insert( the_list, 'D' );
    insert( the_list, 'a' );
    insert( the_list, 'm' );
    insert( the_list, 'e' );
    
    fprintf( stdout, "%p %p\n", &the_list, the_list );
    
    print_list( the_list->head_node );

    destructor( the_list->head_node );

    return 0;
}
