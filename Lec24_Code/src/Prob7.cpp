#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#define COUT std::cout
#define CIN std::cin
#define ENDL std::endl
#define OFSTREAM std::ofstream

int main(){
	
	COUT << "What is are primary benefit of using a Sorted Doubly Linked List for a Priority Queue instead of a Max Heap? (Two correct answers)"<< ENDL;
	
	COUT << "A. Insertion time of O( lg(n) ) for each element" << ENDL;
	COUT << "B. Guaranteed O(1) removal for all elements" << ENDL;	
	COUT << "C. Aggregating a dynamic array instead of using pointers reduces memory if the templated type of the Priority Queue is large" << ENDL;
	COUT << "D. Use of balancing mechanisms instead of sorting reduces the need for exact sorting after every push or pop" << ENDL;
	
	char input_val_1 = ' ';
	char input_val_2 = ' ';
	char correct_val_1 = 'B';
	char correct_val_2 = 'C';
	
	while( input_val_1 != correct_val_1 || input_val_2 != correct_val_2 ){
		
		COUT << "" << ENDL;
		COUT << "Enter your choice as A B (like Linux, answer is case sensitive): ";
		
		CIN >> input_val_1 >> input_val_2;
		
		if( input_val_1 != correct_val_1 ){
			
			COUT << input_val_1 << " is not a correct answer" << ENDL;
		}
		
		if( input_val_2 != correct_val_2 ){
			
			COUT << input_val_2 << " is not a correct answer" << ENDL;
		}
		
	}
	
	COUT << correct_val_1 << " " << correct_val_2 << " is correct" << ENDL;
	
	// Print successful output to file for Prob1.txt 
	std::ofstream Prob6( "Prob6.txt" );
	
	Prob6 << "Completed Problem 6" << std::endl;

	Prob6.close();
	
	return 0;
	
}
