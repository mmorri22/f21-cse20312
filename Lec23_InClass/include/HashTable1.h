#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <iostream>
#include <vector>

#define VECTOR std::vector

template<class Key, class Value>
class HashTable{
	
	private:
	
		// Private Dynamic Array for Hash Table 
		VECTOR<Value>* array;
		
	public:	
	
		// Constructor
		HashTable(const unsigned int size = 0) : array( new VECTOR<Value>( size ) ) {}
		
		// Destructor
		~HashTable(){
			delete array;
		}
		
		// Copy Constructor
		HashTable( const HashTable<Key, Value>& copy ) : array( copy.array ) {}
		
		// Assignment Operator
		HashTable& operator=( const HashTable<Key, Value>& assign ){
			
			if( this != &assign ){
			
				this->array = assign.array;
			}
			
			return *this;
		}
	
		// Overloaded Friend Operator
		friend std::ostream& operator<<( std::ostream& output, const HashTable<Key, Value>* theTable ){
			
			output << "Hash Table Size: " << theTable->array->size() << std::endl;
			
			return output;
		}
};


#endif