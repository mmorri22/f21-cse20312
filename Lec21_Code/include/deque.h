#ifndef DEQUE_H
#define DEQUE_H

#include "dllist.h"

template< class T >
class deque{
	
	private:
	
		dllist<T>* the_list;
		
	public:
	
		deque() : the_list( new dllist<T>() ) {}
		
		~deque() {
			
			delete the_list;
			
		}
		
		deque(const deque<T>& copy) : the_list( new dllist<T>() ) {
			
			*the_list = copy.the_list;
			
		}
		
		deque<T>& operator=(const deque<T>& assign){
				
			// Check the address 
			if(this != &assign){

				*the_list = assign.the_list;

			}
			return *this;
			
		}
		
		void push_front( const T& new_data ){
			
			the_list->push_front( new_data );
			
		}
		
		void push_back( const T& new_data ){
			
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
		
		bool pop_front( ){
			
			return the_list->pop_front();
			
		}	
		
		bool pop_back( ){
			
			return the_list->pop_front();
			
		}	
	
};

#endif