#ifndef QUEUE_H
#define QUEUE_H

#include "dllist.h"

template< class T >
class queue{
	
	private:
	
		dllist<T>* the_list;
		
	public:
	
		queue() : the_list( new dllist<T>() ) {}
		
		~queue() {
			
			delete the_list;
			
		}
		
		queue(const queue<T>& copy) : the_list( new dllist<T>() ) {
			
			*the_list = copy.the_list;
			
		}
		
		queue<T>& operator=(const queue<T>& assign){
				
			// Check the address 
			if(this != &assign){

				*the_list = assign.the_list;

			}
			return *this;
			
		}
		
		void push( const T& new_data ){
			
			the_list->push_back( new_data );
			
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