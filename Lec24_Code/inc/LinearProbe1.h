#ifndef LINEARPROBE1_H
#define LINEARPROBE1_H

#include <iostream>
#include <vector>

template<class Key, class Value>
class HashTable{
	
	private:
		std::vector<Value> array;	// Private Dynamic Array for Hash Table 
		
	public:	
	
		// Constructor
		HashTable(const unsigned int size = 0) : array( size ) {}
	
		// Overloaded Friend Operator
		friend std::ostream& operator<<( std::ostream& output, const HashTable<Key, Value>& theTable ){
			
			output << "Hash Table Size: " << theTable.array.size() << std::endl;
			
			return output;
		}
};

#endif
