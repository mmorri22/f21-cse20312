#include "../inc/LinearProbe5.h"

#include <iostream>
#include <fstream>

#define COUT std::cout
#define ENDL std::endl

int main(){
	
	std::ofstream Prob3( "Prob3.txt" );
	
	Prob3 << "Problem 3 Completed" << ENDL;
	
	Prob3.close();
	
	const unsigned int hashSize = 7;
	
	HashTable<std::string, unsigned int> strHash(hashSize);
	
	HashTable<int, double> intHash;
	
	// Insert into the String Hash 
	strHash.insert( { "Data", 22} );
	strHash.insert( { "Structures", 15} );
	strHash.insert( { "Hash", 9} );
	
	COUT << strHash << ENDL;
	
	// Insert into the int, double hash 
	intHash.insert( {5, 3.14} );
	
	COUT << intHash << ENDL;
	
	return 0;
}

