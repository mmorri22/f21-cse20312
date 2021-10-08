#include "../inc/LinearProbe1.h"

#define COUT std::cout
#define ENDL std::endl

int main(){
	
	const unsigned int hashSize = 7;
	
	HashTable<std::string, unsigned int> strHash(hashSize);
	
	HashTable<int, double> dblHash;
	
	COUT << strHash << ENDL;
	
	COUT << dblHash << ENDL;
	
	return 0;
}

