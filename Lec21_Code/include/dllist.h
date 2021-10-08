#ifndef DLLIST_H
#define DLLIST_H

#include <iostream>
#include <cstdlib>

template< class T >
struct dll_node{

	T data;
	dll_node<T>* prev_node;	
	dll_node<T>* next_node;	
	
	// Struct C++ Constructor
	dll_node( const T& new_data ) : data( new_data ), 
			prev_node( NULL ), next_node( NULL ) {}

};

template< class T >
class dllist{

	private:
	
		dll_node<T>* head_node;
		dll_node<T>* tail_node;
		
		// Recursively calls delete_nodes and deletes the curr_node 
		void delete_nodes( dll_node<T>* curr_node ){
			
			// Dr. Morrison's Golden Rule of Pointers 
			if( curr_node == NULL )
				return;
			
			// Recursively call delete_nodes
			delete_nodes( curr_node->next_node );
			
			// Delete the current node 
			delete curr_node;
			
		}
	
	public:
	
		// Default Copy Constructor
		dllist() : head_node( NULL ), tail_node( NULL ) {}
		
		// Destructor
		~dllist(){
			delete_nodes( head_node );
		}
		
		// Copy Constructor
		dllist(const dllist<T>& copy) : head_node(NULL) {
			
			dll_node<T>* curr_node = copy.head_node;
			
			while(curr_node != NULL){
				
				push_back(curr_node->data);
					
				curr_node = curr_node->next_node;
				
			}
		}
		
		dllist<T>& operator=(const dllist<T>& assign){
				
			// Check the address 
			if(this != &assign){

				dll_node<T>* curr_node = assign.curr_node;
				
				while(curr_node != NULL){
					
					this->push_back(curr_node->data);

					curr_node = curr_node->next;
					
				}
			}
			return *this;
			
		}
		
		void insert( const T& new_data ){
			
			// De-reference in order to allocate and preserve the memory 
			dll_node<T>* new_node = new dll_node<T>( new_data );

			// Dr. Morrison's Golden Rule of Pointers 
			if( head_node == NULL ){
				
				head_node = new_node;
				return;
			}
			
			dll_node<T>* curr_node = head_node;
			
			while( curr_node->next_node != NULL ){
				
				curr_node = curr_node->next_node;
			
			}
			
			curr_node->next_node = new_node;
					
		}
		
		// Step 13 - Push Front 
		void push_front( const T& new_data ){
	
			// De-reference in order to allocate and preserve the memory 
			dll_node<T>* new_node = new dll_node<T>( new_data );
	
			// Dr. Morrison's Golden Rule of Pointers 
			// Check if the list is empty
			if( head_node == NULL && tail_node == NULL ){
		
				// Set the head node equal to new_node 
				head_node = new_node;
				tail_node = new_node;
		
				// And return
				return;
			}
	
			// 13-2 Now we just need to use a reference pointer and put them in front
			dll_node<T>* reference = head_node;
			
			// Set the head_node to the new node 
			head_node = new_node;
			
			// Set the new head_node's next to the reference 
			head_node->next_node = reference;
			reference->prev_node = head_node;
			
		}

		// Step 13 - Push Front 
		void push_back( const T& new_data ){
			
			// Create a dll_node pointer called insert_node
			dll_node<T>* new_node = new dll_node<T>( new_data );
			
			// Dr. Morrison's Golden Rule of Pointers 
			// Check if the list is empty
			if( head_node == NULL && tail_node == NULL ){
				
				// Set the head node equal to insert_node 
				head_node = new_node;
				tail_node = new_node;
				
				// And return
				return;
			}
			
			// 13-2 Now we just need to use a reference pointer and put them in front
			dll_node<T>* reference = tail_node;
			
			// Set the head_node to the new node 
			tail_node = new_node;
			
			// Set the new head_node's next to the reference 
			tail_node->prev_node = reference;
			reference->next_node = tail_node;
			
		}
		
		// Step 6 - Create the constructor method for dllist 
		void insert_sort( const T& new_data ){
			
			// Corner Cases where the new_data is smallest or largest
			if( head_node != NULL && tail_node!= NULL ){
				
				// If the_value is less than the head node, push front 
				if( new_data < head_node->data ){
					
					push_front( new_data );
					
					return;
				}
				else if( new_data > tail_node->data ){
					
					push_back( new_data);
					
					return;
				}				
				
			}
			
			// Create a dll_node pointer called insert_node
			dll_node<T>* insert_node = new dll_node<T>( new_data );
			
			// Dr. Morrison's Golden Rule of Pointers 
			// Check if the list is empty
			if( head_node == NULL && tail_node == NULL ){
				
				// Set the head node equal to insert_node 
				head_node = insert_node;

				// Set the tail node equal to insert_node 
				tail_node = insert_node;
				
				// And return
				return;
			}
			
			// Otherwise, create a curr_ptr equal to the head_node 
			dll_node<T>* prev_ptr = head_node;
			dll_node<T>* curr_ptr = head_node->next_node;
			
			// Iterate until the next_node is NULL
			while( new_data >= curr_ptr->data ){
				
				prev_ptr = curr_ptr;
				curr_ptr = curr_ptr->next_node;
			}
			
			// Set curr_ptr's next_node equal to insert_node
			insert_node->prev_node = prev_ptr;
			prev_ptr->next_node = insert_node;
			
			insert_node->next_node = curr_ptr;
			curr_ptr->prev_node = insert_node;
			
		}
		
		bool pop_front( ){
			
			// Check if the list is not empty
			if( head_node == NULL && tail_node == NULL )
				return false;
		
			else if( head_node == tail_node ){
				
				delete head_node;
				
				head_node = NULL;
				tail_node = NULL;
				
				return true;
			}
			
			// Otherwise, move the node and free
			// Set a reference pointer to head_node
			dll_node<T>* reference = head_node;
			
			// Set the head_node to head_node's next_node;
			head_node = reference->next_node;
			head_node->prev_node = NULL;

			
			// Free the reference 
			delete reference;
			
			return true;
			
		}


		// Step 15 - Pop Front 
		bool pop_back( ){
			
			// Check if the list is not empty
			if( head_node == NULL && tail_node == NULL )
				return true;
			
			else if( head_node == tail_node ){
				
				delete head_node;
				
				head_node = NULL;
				tail_node = NULL;
				
				return true;
			}
			
			// Otherwise, move the node and free
			// Set a reference pointer to head_node
			dll_node<T>* reference = tail_node;
			
			// Set the head_node to head_node's next_node;
			tail_node = reference->prev_node;
			tail_node->next_node = NULL;

			
			// Free the reference 
			delete reference;
			
			return true;
			
		}

		
		T front(){
			
			return head_node->data;
			
		}
		
		T back(){
			
			return tail_node->data;
			
		}
		
		bool is_empty(){
			
			return head_node == NULL && tail_node == NULL;
			
		}
		
		friend std::ostream& operator<<( std::ostream& out, const dllist<T>* print_list ){
			
			if( print_list->head_node != NULL ){

				dll_node<T>* curr_node = print_list->head_node;
				
				while( curr_node != NULL ){
					
					out << curr_node->data << " ";
					
					curr_node = curr_node->next_node;
				}
			}				
			
			return out;
		}

};


#endif