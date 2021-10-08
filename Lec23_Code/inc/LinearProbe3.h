#ifndef LINEARPROBE3_H
#define LINEARPROBE3_H

#include <iostream>
#include <vector>

template<class Key, class Value>
class HashTable{
	
	private:
		std::vector<Value> array;	// Private Dynamic Array for Hash Table
		
		// Checks if the value is a Primt
		bool isPrime( long unsigned int n ) const{
			
			if( n == 2 || n == 3){
				return true;
			}
			
			if( n == 1 || n % 2 == 0 ){
				return false;
			}
			
			for( long unsigned int i = 3; i * i <= n; i += 2 ){
				if( n % i == 0 ){
					return false;
				}
			}
			
			return true;
		}

		// Obtains the next Prime
		long unsigned int nextPrime( long unsigned int n ) const{
			
			// If n is even, make it odd
			if( n % 2 == 0 ){
				++n;
			}
			
			for( ; !isPrime(n); n+=2 ){
				// Do Nothing
			}
			
			return n;
		}


		
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
		HashTable(const unsigned int size = 0) : array( nextPrime(size) ) { }
		
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