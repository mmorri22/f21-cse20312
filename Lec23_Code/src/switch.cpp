#include <iostream>

const int Freshman = 1;
const int Sophomore = 2;
const int Junior = 3;
const int Senior = 4;

#define COUT std::cout
#define ENDL std::endl

void runSwitch(int value){
	
	switch( value ){
		
		case 1:
			COUT << "Freshman" << ENDL;
			break;
			
		case 2:
			COUT << "Sophomore" << ENDL;
			break;
			
		case 3:
			COUT << "Junior" << ENDL;
			break;
			
		case 4:
			COUT << "Senior" << ENDL;
			break;
			
		default:
			COUT << "Not a valid input" << ENDL;
		
	}
	
}

int main(){
	
	runSwitch( Freshman );
	runSwitch( Sophomore );
	runSwitch( Junior );
	runSwitch( Senior );
	runSwitch( 5 );
	
	return 0;
}
