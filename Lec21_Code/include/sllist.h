#ifndef SLLIST_H
#define SLLIST_H

#include <iostream>
#include <cstdlib>

template< class T >
struct sll_node{

	T data;
	sll_node<T>* next_node;	
	
	// Struct C++ Constructor
	sll_node( const T& new_data ) : data( new_data ), next_node( NULL ) {}

};

template< class T >
class sllist{

	private:
	
		sll_node<T>* head_node;
		
		// Recursively calls delete_nodes and deletes the curr_node 
		void delete_nodes( sll_node<T>* curr_node ){
			
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
		sllist() : head_node( NULL ) {}
		
		// Destructor
		~sllist(){
			delete_nodes( head_node );
		}
		
		// Copy Constructor
		sllist(const sllist<T>& copy) : head_node(NULL) {
			
			sll_node<T>* curr_node = copy.head_node;
			
			while(curr_node != NULL){
				
				insert(curr_node->data);
					
				curr_node = curr_node->next_node;
				
			}
		}
		
		sllist<T>& operator=(const sllist<T>& assign){
				
			// Check the address 
			if(this != &assign){

				sll_node<T>* curr_node = assign.curr_node;
				
				while(curr_node != NULL){
					
					this->Insert(curr_node->data);

					curr_node = curr_node->next;
					
				}
			}
			return *this;
			
		}
		
		void insert( const T& new_data ){
			
			// De-reference in order to allocate and preserve the memory 
			sll_node<T>* new_node = new sll_node<T>( new_data );

			// Dr. Morrison's Golden Rule of Pointers 
			if( head_node == NULL ){
				
				head_node = new_node;
				return;
			}
			
			sll_node<T>* curr_node = head_node;
			
			while( curr_node->next_node != NULL ){
				
				curr_node = curr_node->next_node;
			
			}
			
			curr_node->next_node = new_node;
					
		}
		
		void push_front( const T& new_data ){
			
			// De-reference in order to allocate and preserve the memory 
			sll_node<T>* new_node = new sll_node<T>( new_data );
			
			// Dr. Morrison's Golden Rule of Pointers
			if( head_node == NULL ){
				head_node = new_node;
				return;
			}
			
			else{
				new_node->next_node = head_node;
				head_node = new_node;
			}			
		}
		
		
		bool pop_front(){
			
			// Dr. Morrison's Golden Rule of Pointers 
			if( head_node == NULL )
				return false;
			
			// Create a temporary pointer pointing to the head node 
			sll_node<T>* to_free = head_node;
			
			// move the head node pointer to the next node 
			head_node = head_node->next_node;
			
			// free the node pointing to the temporary node 
			delete to_free;
			
			return true;			
		}
		
		T front(){
			
			return head_node->data;
			
		}
		
		bool is_empty(){
			
			return head_node == NULL;
			
		}
		
		friend std::ostream& operator<<( std::ostream& out, const sllist<T>* print_list ){
			
			if( print_list->head_node != NULL ){

				sll_node<T>* curr_node = print_list->head_node;
				
				while( curr_node != NULL ){
					
					out << curr_node->data << " ";
					
					curr_node = curr_node->next_node;
				}
			}				
			
			return out;
		}

};


#endif