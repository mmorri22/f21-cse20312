#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#define COUT std::cout
#define CIN std::cin
#define ENDL std::endl
#define OFSTREAM std::ofstream

int main(){

	COUT << "Select the array representation of the final Max Heap, given the following insertions and removals: 33 21 81 27 1 7 44 0 99, and then remove the Top 2 elements"<< ENDL;
	
	COUT << "A. 44 33 27 21 7 0" << ENDL;
	COUT << "B. 44 27 33 21 7 0" << ENDL;	
	COUT << "C. 44 33 27 7 21 0" << ENDL;
	COUT << "D. 44 27 33 7 21 0" << ENDL;
	
	char input_val = ' ';
	char correct_val = 'B';
	
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
	std::ofstream Prob5( "Prob5.txt" );
	
	Prob5 << "Completed Problem 5" << std::endl;

	Prob5.close();
	
	return 0;
	
}
