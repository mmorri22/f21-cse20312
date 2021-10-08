#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

#include "dllist.h"

template< class T >
class priority_queue{
	
	private:
	
		dllist<T>* the_list;
		
	public:
	
		priority_queue() : the_list( new dllist<T>() ) {}
		
		~priority_queue() {
			
			delete the_list;
			
		}
		
		priority_queue(const priority_queue<T>& copy) : the_list( new dllist<T>() ) {
			
			*the_list = copy.the_list;
			
		}
		
		priority_queue<T>& operator=(const priority_queue<T>& assign){
				
			// Check the address 
			if(this != &assign){

				*the_list = assign.the_list;

			}
			return *this;
			
		}
		
		void push( const T& new_data ){
			
			the_list->insert_sort( new_data );
			
		}
		
		T front(){
			
			return the_list->front();
			
		}
		
		T back(){
			
			return the_list->back();
			
		}
		
		bool is_empty(){
			
			return the_list->is_empty();
			
		}
		
		bool pop( ){
			
			return the_list->pop_front();
			
		}	
	
};

#endif