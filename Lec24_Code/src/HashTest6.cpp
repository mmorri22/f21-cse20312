#include "../include/HashTable6.h"

#define COUT std::cout
#define ENDL std::endl

int main(){
	
	const unsigned int hash_size = 7;
	
	HashTable<std::string, unsigned int>* str_int_hash = new HashTable<std::string, unsigned int>( hash_size );
	
	HashTable<int, double>* int_dbl_hash = new HashTable<int, double>( );
	
	// Insert into the String Hash 
	// Modified to instantiate a std::pair
	str_int_hash->insert( { "Data", 22} );
	str_int_hash->insert( { "Structures", 15} );
	str_int_hash->insert( { "Hash", 9} );
	str_int_hash->insert( { "Table", 44} );
	str_int_hash->insert( { "Lecture", 109} );
	
	COUT << str_int_hash << ENDL;
	
	// Insert into the int, double hash 
	int_dbl_hash->insert( {5, 3.14} );
	int_dbl_hash->insert( {2, 6.28} );
	int_dbl_hash->insert( {7, -22.6} );
	int_dbl_hash->insert( {1, 33} );
	
	COUT << int_dbl_hash << ENDL;
	
	delete int_dbl_hash;
	delete str_int_hash;
	
	return 0;
}

