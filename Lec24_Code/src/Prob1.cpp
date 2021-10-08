#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#define COUT std::cout
#define CIN std::cin
#define ENDL std::endl
#define OFSTREAM std::ofstream

int main(){
	
	bool solved = false;
	
	while( !solved ){
		
		COUT << "Given a Hash Table where there are 7 buckets, draw the final table using Open Addressing with Linear Probing for 25, 47, 82, 19. Assume no re-hashing or re-sizing."<< ENDL;

		COUT << ENDL << "Calculate the table, and then type the value into the corresponding bucket" << ENDL;
		COUT << "If the bucket is empty, just press 0" << ENDL;
	
		std::vector< std::string > vec_student;
		
		int curr_bucket = 0;
		
		COUT << "0 - ";
		
		while( curr_bucket < 7 ){
			
			std::string curr_answer;
			
			CIN >> curr_answer;
			
			vec_student.push_back( curr_answer );
			
			++curr_bucket;
			
			if( curr_bucket != 7 )
				COUT << curr_bucket << " - ";
		}

		std::vector< std::string > vec_solution{ "19", "0", "0", "0", "25", "47", "82" };
		
		solved = true;

		for( long unsigned int iter = 0; iter < vec_solution.size(); ++iter ){
			
			if( vec_solution.at( iter ) != vec_student.at(iter) ){
				
				solved = false;
				
			}
		}
		
		if( !solved ){
			
			COUT << ENDL << "Your submission is not correct" << ENDL;
			COUT << "Here is the comparison of your submission and the answer:" << ENDL;
			COUT << "Bucket   Answer   Your Submission" << ENDL;
			
			for( long unsigned int iter = 0; iter < vec_solution.size(); ++iter ){
				
				COUT << iter << "        " << vec_solution.at( iter ) << "       " << vec_student.at( iter ) << ENDL;
			}			
			
			COUT << ENDL << "Give it another try." << ENDL;
		}
		
		else{
			
			COUT << "Good job! That is the correct answer!" << ENDL;
		}
	}
	
	// Print successful output to file for Prob1.txt 
	std::ofstream Prob1( "Prob1.txt" );
	
	Prob1 << "Completed Problem 1" << std::endl;

	Prob1.close();
	
	return 0;
	
}
