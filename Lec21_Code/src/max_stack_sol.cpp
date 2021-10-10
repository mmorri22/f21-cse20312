#include "../include/max_stack.h"

const int INPUT_THROW = 100;

#define COUT std::cout
#define ENDL std::endl

void clearSTDCIN(){
	std::cin.clear();
    std::cin.ignore(256, '\n');
}

void getInputs(unsigned int& stack_size, unsigned int& val_max){

    std::cout << "Enter the values as [size] [range]: " << std::endl;

    if( !(std::cin >> stack_size) ){
		std::cerr << "Input " << stack_size << " is incorrect. Must be an integer." << std::endl;
		exit(-1);
	}
    
    if( !(std::cin >> val_max) ){
		std::cerr << "Input " << val_max << " is incorrect. Must be an integer." << std::endl;
		exit(-1);
	}
	
 }

int main()
{  

	unsigned int stack_size;
	unsigned int val_max;
	
	getInputs(stack_size, val_max);
	
	// Seed srand - Remember the Year 2038 Problem?
	srand( (unsigned int)time(NULL) );
	
	max_stack<int>* the_max_stack = new max_stack<int>();
	
	COUT << "Elements pushed on the stack: ";
	for(unsigned int i = 0; i < stack_size; i++){
		
		the_max_stack->push(rand() % val_max);
		
	}
	
	COUT << ENDL;
	
	COUT << "size = " << the_max_stack->data_size 
	     << ", max_size = " << the_max_stack->max_size
	     << ", min_size = " << the_max_stack->min_size << ENDL;
	
	COUT << ENDL << "Top\tMax\tMin\t" << ENDL;
	for(unsigned int i = 0; i < stack_size; i++){
		COUT << the_max_stack->top() << '\t';
		COUT << the_max_stack->max() << '\t';
		COUT << the_max_stack->min() << ENDL;
		the_max_stack->pop();
	}
	
	delete the_max_stack;

    return 0;
}
