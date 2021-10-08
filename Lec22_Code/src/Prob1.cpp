#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#define COUT std::cout
#define CIN std::cin
#define ENDL std::endl
#define OFSTREAM std::ofstream

int main(){

	COUT << "Select the array representation of the final Max Heap, given the following insertions and removals: 68 9 6 20 5 40 64 22 34, and then remove the Top 2 elements"<< ENDL;
	
	COUT << "A. 40 20 34 22 5 9 6" << ENDL;
	COUT << "B. 40 20 34 22 5 6 9" << ENDL;	
	COUT << "C. 40 34 20 22 5 6 9" << ENDL;
	COUT << "D. 40 34 20 5 22 6 9" << ENDL;
	
	char input_val = ' ';
	char correct_val = 'C';
	
	while( input_val != correct_val ){
		
		COUT << "" << ENDL;
		COUT << "Enter your choice (like Linux, answer is case sensitive): ";
		
		CIN >> input_val;
		
		if( input_val != correct_val ){
			
			COUT << input_val << " is not the correct answer" << ENDL;
		}
		
	}
	
	COUT << correct_val << " is correct" << ENDL;
	
	// Print successful output to file for Prob1.txt 
	std::ofstream Prob1( "Prob1.txt" );
	
	Prob1 << "Completed Problem 1" << std::endl;

	Prob1.close();
	
	return 0;
	
}
