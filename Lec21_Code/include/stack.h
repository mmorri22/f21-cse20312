#ifndef STACK_H
#define STACK_H

#include "sllist.h"

template< class T >
class stack{
	
	private:
	
		sllist<T>* the_list;
		
	public:
	
		stack() : the_list( new sllist<T>() ) {}
		
		~stack() {
			
			delete the_list;
			
		}
		
		stack(const stack<T>& copy) : the_list( new sllist<T>() ) {
			
			*the_list = copy.the_list;
			
		}
		
		stack<T>& operator=(const stack<T>& assign){
				
			// Check the address 
			if(this != &assign){

				*the_list = assign.the_list;

			}
			return *this;
			
		}
		
		void push( const T& new_data ){
			
			the_list->push_front( new_data );
			
		}
		
		T top(){
			
			return the_list->front();
			
		}
		
		bool is_empty(){
			
			return the_list->is_empty();
			
		}
		
		bool pop( ){
			
			return the_list->pop_front();
			
		}	
	
};

#endif