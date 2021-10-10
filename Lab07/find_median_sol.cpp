#include "max_heap.h"
#include "min_heap.h"

#define COUT std::cout
#define CIN std::cin
#define ENDL std::endl

void addNum( int input, max_heap<int>* left, min_heap<int>* right ){
	
	if( left->is_empty() && right->is_empty() ){
		left->push( input );
	}
	
	else if( left->size() > right->size() ){
		
		if( input <= left->top() ){
			right->push( left->top() );
			left->pop();
			left->push( input );
		}
		
		else if( input > left->top() ){
			right->push( input );
		}
	}
	else if( left->size() == right->size() ){
		
		if( input <= right->top() ){
			left->push( input );
		}
		else{
			left->push( right->top() );
			right->pop();
			right->push( input );
		}
	}
}


void getMedian( max_heap<int>* left, min_heap<int>* right ){
	
	COUT << "Median: ";
	
	if( left->is_empty() && right->is_empty() ){
		COUT << "No values input-> No median to calculate" << ENDL;
	}
	
	else if( left->size() > right->size() ){
		COUT << left->top() << ENDL;
	}
	
	else{
		COUT << ( (double)left->top() + (double)right->top() ) / 2 << ENDL;
	}
	
}

int main(){
	
	max_heap< int >* left = new max_heap<int>();
	min_heap< int >* right = new min_heap<int>();
	
	int input = 0;
	
	while( input >= 0 ){
		
		COUT << "Insert a positive integer (or -1 to quit): ";
		
		CIN >> input;
		
		if( input >= 0 ){
			
			addNum( input, left, right );
			
			COUT << "Left Heap : " << left << "\tRight Heap: " << right << ENDL;
			
			getMedian( left, right );
			COUT << ENDL;
			
		}
	}
	
	delete left;
	delete right;
	
	return 0;
}
