#ifndef LINEARPROBE2_H
#define LINEARPROBE2_H

#include <iostream>
#include <vector>

template<class Key, class Value>
class HashTable{
	
	private:
		std::vector<Value> array;	// Private Dynamic Array for Hash Table
		
		// Translate to unsigned int for int
		long unsigned int HashFunc( const int& keyToTranslate ) const{
				
			if (keyToTranslate < 0){
				return (long unsigned int)(-1 * keyToTranslate);
			}
			
			return (long unsigned int) keyToTranslate;
			
		}

		// Translate to unsigned int for std::string		
		long unsigned int HashFunc( const std::string& keyToTranslate ) const{
			
			return keyToTranslate.size();
			
		}

		// Return Hash Location
		long unsigned int findPos(const Key& theKey) const{
			
			return HashFunc(theKey) % array.size();
			
		}
		
	public:
	
		// Constructor
		HashTable(const unsigned int size = 0) : array( size ) {}
		
		// Insert into the hash 
		void insert( const Key& theKey, const Value& theValue ){
			
			long unsigned int location = findPos(theKey);
			
			array[location] = theValue;
			
		}
	
		// Overloaded Friend Operator
		friend std::ostream& operator<<( std::ostream& output, const HashTable<Key, Value>& theTable ){
			
			output << "Hash Table Size: " << theTable.array.size() << std::endl;
			
			for(unsigned int iter = 0; iter < theTable.array.size(); iter++){
				
				output << "{" << iter << ", " << theTable.array[iter] << "}" << std::endl;
				
			}
			
			return output;
		}
};

#endif