#ifndef MAX_STACK_H
#define MAX_STACK_H

#include <iostream>
#include <cstdlib>

#include "stack.h"

template <typename T>
class max_stack {
    
	private:
		// Data, Max, and Minimum Stacks
		stack<T>* data;
		stack<T>* max_data;
		stack<T>* min_data;
    
    public:
    
        // Counters for size to report
        // Don't need to unstack to get stack size.
		// Deliberately public to show students it can be done
        size_t data_size = 0;
        size_t max_size = 0;
        size_t min_size = 0;
		
		// Constructor
		max_stack() : data( new stack<T>() ), max_data( new stack<T>() ), 
					  min_data( new stack<T>() ) {}
		
		// Destructor
		~max_stack(){
			
			delete data;
			delete max_data;
			delete min_data;
		}
		
		// Copy Constructor
		max_stack( const max_stack<T>& copy ) : data( copy.data ), max_data( copy.max_data ), 
			min_data( copy.min_data ) { }
		
		// Assignment Operator
		max_stack<T>& operator=( const max_stack<T>& assign ){
			
			if( this != &assign ){
				
				data = assign.data;
				max_data = assign.max_data;
				min_data = assign.min_data;
				
			}
			return *this;
		}
 
    	bool empty() const { 
    	    return data->empty(); 
    	}
  	
        const T top() const { 
            return data->top(); 
        }
    
        void push(const T& value) {
			
			std::cout << value << " ";
			
            data->push(value);   data_size++;
    
            if ( max_data->is_empty() || value >= max_data->top() ) {
				
                max_data->push(value);
                max_size++;
				
            } 
            
            if ( min_data->is_empty() || value <= min_data->top() ) {
				
                min_data->push(value);
                min_size++;
				
            } 
        }
        
        void pop() {
			
            if( data->top() == max_data->top() ){
                std::cout << "Max found! " << data->top() << " popped." << std::endl;
                max_data->pop();
                max_size--;
            }
            
            if( data->top() == min_data->top() ){
                std::cout << "Min found! " << data->top() << " popped." << std::endl;
                min_data->pop();
                min_size--;
            }
                
            data->pop(); data_size--;

        }

       
        const T max() const { 
            return max_data->top(); 
        }
        
        const T min() const { 
            return min_data->top(); 
        }
};

#endif