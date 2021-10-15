#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <iostream>
#include <vector>
#include <string>

#define VECTOR std::vector
#define STRING std::string

// Enumerated Type EntryState 
enum EntryState { ACTIVE, EMPTY, DELETED };

template<class Key, class Value>
class HashTable{
	
	private:
	
		// Private Struct Hash Entry
		struct HashEntry{
			
			Key key;
			Value value;
			EntryState state;
			
			HashEntry() : key(), value(), state( EMPTY ) {}
			
			HashEntry( std::pair<const Key, Value> thePair, EntryState stateIn = EMPTY ) 
				: key(thePair.first), value(thePair.second), state( stateIn ) {}

		};
	
		// Private Dynamic Array for Hash Table 
		VECTOR<HashEntry>* array;
		long unsigned int numHash;			// Number of Hashed Elements
		
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
		long unsigned int HashFunc( const STRING& keyToTranslate ) const{
			
			return keyToTranslate.size();
			
		}

		// Return Hash Location
		long unsigned int findPos(const Key& theKey) const{
			
			return HashFunc(theKey) % array->size();
			
		}
		
		// Return Hash Location
		long unsigned int findPos( const std::pair<const Key, Value>& insertPair ) const{
			
			// Initialize the Values
			long unsigned int currentPos;
			long unsigned int iter = 0;
			const long unsigned int STEPSIZE = 1;
			
			do{
				// Hash Function determines current position
				currentPos = (HashFunc( insertPair.first ) + iter*STEPSIZE) % array->capacity();
				++iter;
			}
			while(
				array->at( currentPos ).state != EMPTY
				&& array->at( currentPos ).state != DELETED
				&& array->at(currentPos).key != insertPair.first
				&& iter < array->capacity()
			);
			
			// Return capacity if the current value isn't the key. For safety
			if(array->at( currentPos ).state == ACTIVE 
				&& array->at( currentPos ).key != insertPair.first ){
					
					return array->capacity();
					
				}
			
			return currentPos;
		}
		
		// Determine if the current position is active or not 
		bool isActive( long unsigned int currentPos ) const {
			
			return array->at( currentPos ).state == ACTIVE;
			
		}
		
		// Rehash the Dynamic Array
		void rehash(){
			
			// Copy the element 
			std::vector<HashEntry> oldArray = *array;
			
			// Clear the original array 
			array->clear();
			
			// Resize the array 
			array->resize( nextPrime( 2 * oldArray.size() ) );
			
			// Rehash the old elements 
			numHash = 0; // Set the number hashed to 0
			for( long unsigned int iter = 0; iter < oldArray.capacity(); iter++ ){
				
				if( oldArray.at(iter).state == ACTIVE ){
					
					// Insert using the std::pair {} template
					insert( { oldArray.at(iter).key, oldArray.at(iter).value } );
					
				}
			}
		}
		
	public:	
	
		// Constructor
		HashTable(const unsigned int size = 0) : array( new VECTOR<HashEntry>( nextPrime(size) ) ), numHash(0) {}
		
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
		void insert( const std::pair<Key, Value>& insertPair ){
			
			// If another insert exceeds half capacity, rehash
			if( numHash + 1 > array->capacity() / 2 ){
				
				rehash();
			}
			
			// We will always increment the Hash if we get here
			++numHash;
			
			// Get the location
			long unsigned int location = findPos( insertPair.first );
			
			// Insert the new entry at the current position
			HashEntry theEntry(insertPair, ACTIVE);
			array->at( location ) = theEntry;
			
		}
		
		bool remove( const Key& theKey ){
			
			// Find the position of the current key
			long unsigned int currentPos = findPos( theKey );
			
			// If it's not active - Not in the Hash 
			// Return false
			if( array->at(currentPos).state != ACTIVE )
				return false;
			
			// Otherwise, mark the position as DELETED
			array->at(currentPos).state = DELETED;
			
			// Decrement the Hash
			--numHash;
			
			return true;
		}

	
		// Overloaded Friend Operator
		friend std::ostream& operator<<( std::ostream& output, const HashTable<Key, Value>* theTable ){
			
			output << "Hash Table Size: " << theTable->array->size() << std::endl;
			
			for(unsigned int iter = 0; iter < theTable->array->size(); iter++){
				
				output << "{" << iter << ", ";
				
				if( theTable->array->at(iter).state == ACTIVE ){
				
					output << "ACTIVE, ";
				
				}
				if( theTable->array->at(iter).state == DELETED ){
				
					output << "DELETED, ";
				
				}
				else{
					
					output << "EMPTY, ";
				}
				
				output << theTable->array->at(iter).key << ", ";
				
				output << theTable->array->at(iter).value << "}" << std::endl;
				
			}			
			
			return output;
		}
};


#endif