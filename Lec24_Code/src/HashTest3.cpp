#include "../include/HashTable3.h"

#define COUT std::cout
#define ENDL std::endl

int main(){
	
	const unsigned int hash_size = 7;
	
	HashTable<std::string, unsigned int>* str_int_hash = new HashTable<std::string, unsigned int>( hash_size );
	
	HashTable<int, double>* int_dbl_hash = new HashTable<int, double>( );
	
	// Insert into the String Hash 
	str_int_hash->insert( "Data", 22 );
	str_int_hash->insert( "Structures", 15 );
	str_int_hash->insert( "Hash", 9 );
	
	COUT << str_int_hash << ENDL;
	
	// Insert into the int, double hash 
	int_dbl_hash->insert( 5, 3.14 );
	
	COUT << int_dbl_hash << ENDL;
	
	delete int_dbl_hash;
	delete str_int_hash;
	
	return 0;
}

