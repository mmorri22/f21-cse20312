#include <stdio.h>
#include <stdlib.h>

typedef struct sll_node{

	int data;
	struct sll_node* next_node;	
	
}sll_node;

// Step 3 - Create the struct for sllist


	// Make the private sll_node member called head_node
	
	



// Step 6 - Create the constructor method for sllist 

	
	// Create a sll_node pointer called insert_node
	
	
	// Set the insert_node's data to the_value and next_node to NULL 
	
	
	
	// Dr. Morrison's Golden Rule of Pointers 
	// Check if the list is empty
	
		
		// Set the head node equal to insert_node 
		
		
		// And return
		
	
	
	// Otherwise, create a curr_ptr equal to the head_node 
	
	
	// Iterate until the next_node is NULL
	
		
		
	
	
	// Set curr_ptr's next_node equal to insert_node
	
	


// Step 8 - Print the Singly Linked List 

	
	// We can just copy and paste from sllist_part2.c
	
	// Just change node_0 to head_node

	
	
		
		
		
				
		
		

		// Iterate through the next node
		

	
	




// Step 10 - Free all the elements 

	
	// Dr. Morrison's Golden Rule of Pointers 
	
		
	

	// Recursively call destructor on the next node  
	
		
	// Free the current pointer 
	
	



int main( void ){
	
	// Step 4 - Dynamically allocate a sllist 
	
	
	// Step 4-1 - Set the head_node to NULL 
	
	
	
	// Step 7 - Call insert with 10, -20, 15, and 4
	
	
	
	
	
	
	// Step 9 - Call in main
	

	
	// Step 11 - Call the destructor
	

	
	// Step 5 - Free the sllist 
	
	
	return EXIT_SUCCESS;
}