#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <iostream>
#include <vector>
#include <string>

#define VECTOR std::vector
#define STRING std::string

template<class Key, class Value>
class HashTable{
	
	private:
	
		// Private Dynamic Array for Hash Table 
		VECTOR<Value>* array;
		
		// Translate to unsigned int for int
		long unsigned int HashFunc( const int& keyToTranslate ) const{
				
			if (keyToTranslate < 0){
				return (long unsigned int)(-1 * keyToTranslate);
			}
			
			return (long unsigned int) keyToTranslate;
			
		}

		// Translate to unsigned int for std::string		
		long unsigned int HashFunc( const STRING& keyToTranslate ) const{
			
			return keyToTranslate.size();
			
		}

		// Return Hash Location
		long unsigned int findPos(const Key& theKey) const{
			
			return HashFunc(theKey) % array->size();
			
		}
		
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
		
		// Insert into the hash 
		void insert( const Key& theKey, const Value& theValue ){
			
			long unsigned int location = findPos(theKey);
			
			array->at(location) = theValue;
			
		}
	
		// Overloaded Friend Operator
		friend std::ostream& operator<<( std::ostream& output, const HashTable<Key, Value>* theTable ){
			
			output << "Hash Table Size: " << theTable->array->size() << std::endl;
			
			for(unsigned int iter = 0; iter < theTable->array->size(); iter++){
				
				output << "{" << iter << ", " << theTable->array->at(iter) << "}" << std::endl;
				
			}			
			
			return output;
		}
};


#endif