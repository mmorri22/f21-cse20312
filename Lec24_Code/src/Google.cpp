/**********************************************
* File: Google.cpp
* Author: Matthew Morrison
* Email: matt.morrison@nd.edu
* 
* This is a solution to the Google License Interview question 
* using std::vector to store the dictionary words
* 
*************************************************/
#include <iostream>
#include <fstream>
#include <unordered_map>
#include <vector>
#include <string>
#include <iterator>

void getAndCheckFile(std::ifstream& fileStream, std::string fileName){
	
	fileStream.open(fileName);
	
	if(!fileStream.is_open()){
		
		std::cout << "The file " << fileName << " does not exist. Exiting Program..." << std::endl;
		exit(-1);
		
	}
}

void getDictionaryWords(std::ifstream& dictionaryFile, std::vector< std::string >& dictionaryVec){
	// Get the strings and put in the Forward List
	std::string wordIn;
	while (dictionaryFile >> wordIn)
	{
		dictionaryVec.push_back(wordIn);
	}
}

void HashLicense(std::unordered_map< char, int >& HashPlate, const std::string& plate){
	
	for(long unsigned int i = 0; i < plate.size(); i++){
		
		// Assume ASCII and all uppercase letters -> 65-90
		if((int)plate.at(i) >= 65 && (int)plate.at(i) <= 90){
		
			if(HashPlate.count(plate.at(i)) == 0){
				
				// Put the word in, and set the count to 1
				HashPlate.insert( {plate.at(i), 1} );
			}
			else{
				// Increment the count 
				HashPlate[ plate.at(i) ]++;
			}
		}
	}
}

void HashWord(std::unordered_map< char, int >& HashPlate, std::string currWord, std::string& finalWord){
	
	// Create a temporary Hash for the current work 
	std::vector< int > VecWord(26);
	
	for(long unsigned int iter = 0; iter < currWord.size(); iter++){
			
		// words.txt contains all uppercase, but some words may contain numbers 
		if((int)currWord[iter] >= 65 && (int)currWord[iter] <= 90){
				
			VecWord.at((int)currWord[iter] - 65)++;
				
		}
	}

	// Now, go through each character in HashPlate 
	for(std::unordered_map<char, int>::iterator iter = HashPlate.begin(); iter != HashPlate.end(); iter++){
		// if the value in the HashWord is less than HashPlate, 
		// then the # of that character in the word is less than the license plate
		// which means it cannot be a valid choice. Return.
		if(VecWord.at((int)(iter->first) - 65) < iter->second){
			return;
		}
	}
	
	// Went through all the characters in HashPlate and they were found in 
	// the current word. Therefore, currWord is the current solution 
	finalWord = currWord;
	
}

void checkPlate(std::vector< std::string >& dictionaryVec, const std::string& plateStr){
	
	// Get and Hash License Plate
	std::unordered_map< char, int > HashPlate;
	
	// Hash the values of the characters in the license plate  
	HashLicense(HashPlate, plateStr);

	// Set the string where the final word (solution) will be stored
	std::string finalWord;
	
	// Iterate through each word in the dictionary 
	for(long unsigned int iter = 0; iter < dictionaryVec.size(); ++iter ){
		
		std::string currWord = dictionaryVec.at(iter);
		
		// Check the word, and update final word if it qualifies
		// Do not hash currWord if final Word is the same length - Save run time 
		// Must also account for if no word is found yet (finalWord.length() > 0)
		if(currWord.length() < finalWord.length() || finalWord.length() == 0)
			HashWord(HashPlate, currWord, finalWord);
	}
	
	// Print the result to the user 
	std::cout << "Shortest Word in Dictionary with characters in " 
		<< plateStr << " is " << finalWord << std::endl;
	
}

/********************************************
* Function Name  : main
* Pre-conditions : int argc, char** argv
* Post-conditions: int
*
* Main driver function for the program  
********************************************/
int main(const int argc, const char* argv[] ){
	
	// Create a Vec of dictionary words 
	std::vector< std::string > dictionaryVec;
	
	// Get the inputstream
	std::ifstream dictionaryFile;
	if(argc == 2){
		getAndCheckFile(dictionaryFile, argv[1]);
	}
	else{
		std::cout << "Number of inputs are wrong" << std::endl;
		std::cout << "./Google [DictionaryFile] [License]" << std::endl;
		exit(-1);
	}

	// Get the strings and put in the Vec
	getDictionaryWords(dictionaryFile, dictionaryVec);

	// Close the ifstream
	dictionaryFile.close();
	
	// In C++11, conversion from char* to string is depricated. Must do it here
	// Without (char*), it will compile and run. -Wpedantic will throw a warning
	checkPlate(dictionaryVec, "RCT100SA");
	checkPlate(dictionaryVec, "RT123SO");
	checkPlate(dictionaryVec, "AQ10S0K");
	checkPlate(dictionaryVec, "TNT055RB");
	checkPlate(dictionaryVec, "LET10EE0");
	checkPlate(dictionaryVec, "AB1C1D1");
	checkPlate(dictionaryVec, "AEI1O2U3");
	checkPlate(dictionaryVec, "OTR1N2E3");
	checkPlate(dictionaryVec, "AM1E2D3");
	checkPlate(dictionaryVec, "SHR5I3I3");

	return 0;

}

