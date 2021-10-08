#include "../inc/LinearProbe.h"

#define COUT std::cout
#define ENDL std::endl

template< class Key, class Value >
void accessOperatorExample( const HashTable<Key, Value>& theHash, Key keyLookup ){
	
	// Valid example with try catch
	try{
		COUT << "Element at " << keyLookup << " is " << theHash[ keyLookup ] << ENDL << ENDL;
	} 
	catch( const std::exception& theException ){
		
		COUT << "Attempted lookup with key " << keyLookup << ENDL;
		COUT << theException.what() << ENDL << ENDL;
		
	}
	
}

int main(){
	
	const unsigned int hashSize = 7;
	
	HashTable<std::string, unsigned int> strHash(hashSize);
	
	HashTable<int, double> intHash;
	
	// Insert into the String Hash 
	strHash.insert( { "Data", 22} );
	strHash.insert( { "Structures", 15} );
	strHash.insert( { "Hash", 9} );
	strHash.insert( { "Table", 44} );
	strHash.insert( { "Lecture", 109} );
	
	strHash.remove( "Lecture" );
	
	COUT << strHash << ENDL;
	
	strHash.insert( { "Example", 211} );
	
	COUT << strHash << ENDL;
	
	std::string strKeyLookup = "Example";
	
	// Valid example with try catch
	accessOperatorExample( strHash, strKeyLookup );
	
	// Insert into the int, double hash 
	intHash.insert( {5, 3.14} );
	intHash.insert( {2, 6.28} );
	intHash.insert( {7, -22.6} );
	intHash.insert( {1, 33} );
	
	intHash.remove( 5 );
	
	COUT << intHash << ENDL;
	
	intHash.insert( {5, 28.2} );
	
	COUT << intHash << ENDL;
	
	
	// Throw/catch example with try catch
	accessOperatorExample( intHash, 9 );
	
	// Valid example with try catch
	accessOperatorExample( intHash, 7 );
	
	return 0;
}

