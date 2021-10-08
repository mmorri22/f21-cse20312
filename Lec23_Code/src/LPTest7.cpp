#include "../inc/LinearProbe7.h"

#define COUT std::cout
#define ENDL std::endl

int main(){
	
	const unsigned int hashSize = 7;
	
	HashTable<std::string, unsigned int> strHash(hashSize);
	
	HashTable<int, double> intHash;
	
	// Insert into the String Hash 
	strHash.insert( { "Data", 22} );	strHash.insert( { "Structures", 15} );
	strHash.insert( { "Hash", 9} );		strHash.insert( { "Table", 44} );
	strHash.insert( { "Lecture", 109} );
	
	strHash.remove( "Lecture" );
	
	COUT << strHash << ENDL;
	
	strHash.insert( { "Example", 211} );
	
	COUT << strHash << ENDL;
	
	// Insert into the int, double hash 
	intHash.insert( {5, 3.14} );	intHash.insert( {2, 6.28} );
	intHash.insert( {7, -22.6} );	intHash.insert( {1, 33} );
	
	intHash.remove( 5 );
	
	COUT << intHash << ENDL;
	
	intHash.insert( {5, 28.2} );
	
	COUT << intHash << ENDL;
	
	return 0;
}

