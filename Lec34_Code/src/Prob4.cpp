#include <iostream>
#include <fstream>

#define CIN std::cin
#define COUT std::cout
#define ENDL std::endl
#define OFSTREAM std::ofstream


int main(){
	
	// Create the output stream 
	OFSTREAM file_out( "Prob4.txt" );
	
	while( true ) {

		COUT << "Problem 4: You are given the following Adjacency List Representation of a weighted Graph." << ENDL;
		COUT << "Select the corresponding Adjacency List representation of the Minimum Spanning Tree" << ENDL;
		COUT << ENDL;
		COUT << "Vertex\t\tList (destin, weight)" << ENDL;
		COUT << "0 (A)\t\t(1,7), (2,6), (3,8)" << ENDL; 
		COUT << "1 (B)\t\t(4,5), (5,5)" << ENDL;
		COUT << "2 (C)\t\t(5,8), (6,9)" << ENDL;
		COUT << "3 (D)\t\t(5,4), (7,9)" << ENDL;
		COUT << "4 (E)\t\t" << ENDL;
		COUT << "5 (F)\t\t(7,4)" << ENDL;
		COUT << "6 (G)\t\t(5,3), (7,2)" << ENDL;
		COUT << "7 (H)\t\t" << ENDL;
		
		COUT << "A:" << ENDL;
		COUT << "0 (A)\t\t(1,7), (2,6), (3,8)" << ENDL; 
		COUT << "1 (B)\t\t(4,5)" << ENDL;
		COUT << "2 (C)\t\t(6,9)" << ENDL;
		COUT << "3 (D)\t\t" << ENDL;
		COUT << "4 (E)\t\t(5,4), (7,9)" << ENDL;
		COUT << "5 (F)\t\t(7,4)" << ENDL;
		COUT << "6 (G)\t\t(5,3), (7,2)" << ENDL;
		COUT << "7 (H)\t\t" << ENDL;		
		COUT << "B: " << ENDL;
		COUT << "0 (A)\t\t(1,7), (2,6)" << ENDL; 
		COUT << "1 (B)\t\t(4,5)" << ENDL;
		COUT << "2 (C)\t\t(6,9)" << ENDL;
		COUT << "3 (D)\t\t(7,9)" << ENDL;
		COUT << "4 (E)\t\t" << ENDL;
		COUT << "5 (F)\t\t(7,4)" << ENDL;
		COUT << "6 (G)\t\t(5,3)" << ENDL;
		COUT << "7 (H)\t\t" << ENDL;	
		COUT << "C:" << ENDL;
		COUT << "0 (A)\t\t(2,6)" << ENDL; 
		COUT << "1 (B)\t\t(5,5)" << ENDL;
		COUT << "2 (C)\t\t(5,8), (6,9)" << ENDL;
		COUT << "3 (D)\t\t(5,4), (7,9)" << ENDL;
		COUT << "4 (E)\t\t" << ENDL;
		COUT << "5 (F)\t\t" << ENDL;
		COUT << "6 (G)\t\t(5,3), (7,2)" << ENDL;
		COUT << "7 (H)\t\t" << ENDL;	
		COUT << "D:" << ENDL;
		COUT << "0 (A)\t\t(1,7), (2,6), (3,8)" << ENDL; 
		COUT << "1 (B)\t\t" << ENDL;
		COUT << "2 (C)\t\t(5,8), (6,9)" << ENDL;
		COUT << "3 (D)\t\t" << ENDL;
		COUT << "4 (E)\t\t" << ENDL;
		COUT << "5 (F)\t\t(7,4)" << ENDL;
		COUT << "6 (G)\t\t(5,3)" << ENDL;
		COUT << "7 (H)\t\t" << ENDL;	
		COUT << ENDL;
		
		char stu_answer;
		
		COUT << "Enter your choice (Like Linux, answer is case sensitive): ";
		CIN >> stu_answer;
		
		if( stu_answer == 'A' ){
			COUT << "Correct Answer!" << ENDL;
			COUT << "40/40 towards Lecture 17 assignment" << ENDL;
			break;
		}
		
		else{
			COUT << "Incorrect choice. Please try again." << ENDL;
		}
		
	}

	file_out << "Student successfully answered Problem 2 correctly in class." << ENDL;

	// Close the file 
	file_out.close();	
	
	
}
