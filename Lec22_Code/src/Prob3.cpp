#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#define COUT std::cout
#define CIN std::cin
#define ENDL std::endl
#define OFSTREAM std::ofstream

int main(){

	COUT << "Select the array representation of the final Min Heap, given the following insertions and removals: 68 9 6 20 5 40 64 22 34, and then remove the Top 2 elements"<< ENDL;
	
	COUT << "A. 9 20 40 22 34 68 64" << ENDL;
	COUT << "B. 9 40 20 22 34 68 64" << ENDL;	
	COUT << "C. 9 20 40 34 22 68 64" << ENDL;
	COUT << "D. 9 40 20 22 34 64 68" << ENDL;
	
	char input_val = ' ';
	char correct_val = 'A';
	
	while( input_val != correct_val ){
		
		COUT << "" << ENDL;
		COUT << "Enter your choice (like Linux, answer is case sensitive): ";
		
		CIN >> input_val;
		
		if( input_val != correct_val ){
			
			COUT << input_val << " is not the correct answer" << ENDL;
		}
		
	}
	
	COUT << correct_val << " is correct" << ENDL;
	
	// Print successful output to file for Prob3.txt 
	std::ofstream Prob3( "Prob3.txt" );
	
	Prob3 << "Completed Problem 3" << std::endl;

	Prob3.close();
	
	return 0;
	
}
