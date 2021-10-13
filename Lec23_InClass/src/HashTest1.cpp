#include "../include/HashTable1.h"

#define COUT std::cout
#define ENDL std::endl

int main(){
	
	const unsigned int hash_size = 7;
	
	HashTable<std::string, unsigned int>* str_int_hash = new HashTable<std::string, unsigned int>( hash_size );
	
	HashTable<int, double>* int_dbl_hash = new HashTable<int, double>( );
	
	COUT << str_int_hash << ENDL;
	
	COUT << int_dbl_hash << ENDL;
	
	delete int_dbl_hash;
	delete str_int_hash;
	
	return 0;
}

