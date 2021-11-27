#include "RMQSparse.h"

template< class T >
void runRMQ( RMQSparse<T> theMatrix, RMQuery theQuery ){
	
	COUT << "Range Minimum Query from " << theQuery.left << " to " << theQuery.right << " is ";
	
	COUT << theMatrix.getRMQ( theQuery ) << ENDL;
	
}


void test1(){
	
	// Initialize the array length 
    int rmqArray[] = {31, 41, 59, 26, 53, 58, 97, 93}; 
	
	// How to obtain the size of the array when we use {} initializer
    long unsigned int arrayLen = sizeof(rmqArray)/sizeof(rmqArray[0]); 
	
	// Initialize RMQSparse class 
	RMQSparse<int> theMatrix( arrayLen, rmqArray );

	RMQuery q1(0, 3);	
	RMQuery q2(1, 4);
	RMQuery q3(0, 7);
	RMQuery q4(6, 7);
	
	COUT << "Test 1 Runs" << ENDL;
	COUT << ENDL << theMatrix << ENDL;
	
    runRMQ(theMatrix, q1); 
    runRMQ(theMatrix, q2);
    runRMQ(theMatrix, q3); 	
    runRMQ(theMatrix, q4); 
	
	std::cout << std::endl;
}


void test2(){
	
	// Initialize the array length 
    int rmqArray[] = {31, 41, 59, 26, 53, 58, 97, 93, 18, 46, 99, 5, 22, 17, 85, 42, 7}; 
	
	// How to obtain the size of the array when we use {} initializer
    long unsigned int arrayLen = sizeof(rmqArray)/sizeof(rmqArray[0]); 
	
	// Initialize RMQSparse class 
	RMQSparse<int> theMatrix( arrayLen, rmqArray );
	
	RMQuery q1(6, 7);	
	RMQuery q2(1, 4);
	RMQuery q3(4, 7);
	RMQuery q4(1, 15);
	
	COUT << "Test 2 Runs" << ENDL;
	COUT << ENDL << theMatrix << ENDL;
	
    runRMQ(theMatrix, q1); 
    runRMQ(theMatrix, q2);
    runRMQ(theMatrix, q3); 	
    runRMQ(theMatrix, q4); 
	
	std::cout << std::endl;
}


void test3(){
	
	// Initialize the array length 
    char rmqArray[] = {'N', 'o', 't', 'r', 'e', 'D', 'a', 'm', 'e'}; 
	
	// How to obtain the size of the array when we use {} initializer
    long unsigned int arrayLen = sizeof(rmqArray)/sizeof(rmqArray[0]); 
	
	// Initialize RMQSparse class 
	RMQSparse<char> theMatrix( arrayLen, rmqArray );
	
	RMQuery q1(0, 1);	
	RMQuery q2(0, 4);
	RMQuery q3(1, 4);
	RMQuery q4(4, 7);
	
	COUT << "Test 3 Runs" << ENDL;
	COUT << ENDL << theMatrix << ENDL;
	
    runRMQ(theMatrix, q1); 
    runRMQ(theMatrix, q2);
    runRMQ(theMatrix, q3); 	
    runRMQ(theMatrix, q4); 
	
	std::cout << std::endl;
}
  
// Driver program 
int main() 
{ 
	// Initial 8 integer from slides
	test1();
	
	// Next 16 integer array from slides 
	test2();
	
	// Character test with letters from Notre Dame
	test3();
} 

