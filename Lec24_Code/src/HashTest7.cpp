#include "../include/HashTable7.h"

#define COUT std::cout
#define ENDL std::endl

int main(){
	
	const unsigned int hash_size = 7;
	
	//HashTable<std::string, unsigned int>* str_int_hash = new HashTable<std::string, unsigned int>( hash_size );
	
	HashTable<int, double>* int_dbl_hash = new HashTable<int, double>( hash_size );
	
	// Insert into the String Hash 
	// Modified to instantiate a std::pair
	/* str_int_hash->insert( { "Data", 22} );
	str_int_hash->insert( { "Structures", 15} );
	str_int_hash->insert( { "Hash", 9} );
	str_int_hash->insert( { "Table", 44} );
	str_int_hash->insert( { "Lecture", 109} );
	
	COUT << str_int_hash << ENDL;
	
	str_int_hash->remove( "Lecture" );
	
	COUT << str_int_hash << ENDL;
	
	str_int_hash->insert( { "Example", 211} );
	
	COUT << str_int_hash << ENDL; */
	
	// Insert into the int, double hash 
	int_dbl_hash->insert( {31, 3.14} );
	COUT << int_dbl_hash << ENDL;
	int_dbl_hash->insert( {17, 6.28} );
	COUT << int_dbl_hash << ENDL;
	int_dbl_hash->insert( {24, -22.6} );
	COUT << int_dbl_hash << ENDL;
	int_dbl_hash->insert( {41, 33} );
	COUT << int_dbl_hash << ENDL;
	int_dbl_hash->insert( {26, 37} );
	COUT << int_dbl_hash << ENDL;
	int_dbl_hash->insert( {43, 19} );
	
	
	COUT << int_dbl_hash << ENDL;
	
	//int_dbl_hash->remove( 5 );
	
	//COUT << int_dbl_hash << ENDL;
	
	//int_dbl_hash->insert( {5, 28.2} );
	
	//COUT << int_dbl_hash << ENDL;
	
	delete int_dbl_hash;
	//delete str_int_hash;
	
	return 0;
}

