#include <iostream>
#include <fstream>

#define CIN std::cin
#define COUT std::cout
#define ENDL std::endl
#define OFSTREAM std::ofstream


int main(){
	
	// Create the output stream 
	OFSTREAM file_out( "Prob1.txt" );
	
	while( true ) {

		COUT << "Problem 1: You are given the following Adjacency List Representation of a Graph." << ENDL;
		COUT << "Select the path that will result from a Depth-First Search from 0 to 9" << ENDL;
		COUT << ENDL;
		COUT << "Vertex\t\tList" << ENDL;
		COUT << "0 (45)\t\t3, 1, 2" << ENDL;
		COUT << "1 (-7)\t\t4, 2" << ENDL;
		COUT << "2 (34)\t\t1, 5" << ENDL;
		COUT << "3 (18)\t\t1, 2, 5" << ENDL;
		COUT << "4 (10)\t\t" << ENDL;
		COUT << "5 (-18)\t\t7, 6" << ENDL;
		COUT << "6 (-6)\t\t8, 9" << ENDL;
		COUT << "7 (-81)\t\t3" << ENDL;
		COUT << "8 (19)\t\t5, 9" << ENDL;
		COUT << "9 (4)" << ENDL << ENDL;
		
		COUT << "A: 0->3->5->6->9" << ENDL;
		COUT << "B: 0->3->5->7->9" << ENDL;
		COUT << "C: 0->3->6->9" << ENDL;
		COUT << "D: 0->3->1->2->5->6->7->9" << ENDL;
		COUT << "E: 0->3->1->2->5->6->8->9" << ENDL;
		COUT << ENDL;
		
		char stu_answer;
		
		COUT << "Enter your choice (Like Linux, answer is case sensitive): ";
		CIN >> stu_answer;
		
		if( stu_answer == 'E' ){
			COUT << "Correct Answer!" << ENDL;
			COUT << "25/25 towards Lecture 17 assignment" << ENDL;
			break;
		}
		
		else{
			COUT << "Incorrect choice. Please try again." << ENDL;
		}
		
	}

	file_out << "Student successfully answered Problem 1 correctly in class." << ENDL;

	// Close the file 
	file_out.close();	
	
	
}
