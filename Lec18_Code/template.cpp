#include <iostream>
#include <string>

#define COUT std::cout
#define ENDL std::endl
#define STRING std::string

template<class T> 
void printFunc(T& t_var){
	
	COUT << t_var << ENDL;
	
}

int main(){

	int i = 1842;
    double j = 3.14;
    STRING k = "Go Irish!";
    printFunc(i); printFunc(j); printFunc(k);
		
	return 0;
}
