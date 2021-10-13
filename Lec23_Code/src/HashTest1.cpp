#include "../inc/HashTable.h"

#define COUT std::cout
#define ENDL std::endl

int main(){
	
	const unsigned int hash_size = 7;
	
	HashTable<std::string, unsigned int>* strHash = new HashTable<std::string, unsigned int>( hash_size );
	
	HashTable<int, double>* dblHash = new HashTable<int, double>( hash_size );
	
	COUT << strHash << ENDL;
	
	COUT << dblHash << ENDL;
	
	return 0;
}

