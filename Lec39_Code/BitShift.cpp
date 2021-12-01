#include <iostream>

int main(){
	
	int array_len = 100;
	
	for( int j = 0; (1<<j) <= array_len; ++j ){
		
		std::cout << j << " " << (1<<j) << std::endl;
		
	}
	
	return EXIT_SUCCESS;
}