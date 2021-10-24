#include "../include/Quick.h"
#include "../include/TwoSums.h"

void test1(){
	
	VECTOR<int> test1 = {-1, 0, 1, 2, -1, -4};
	
	COUT << "Original Array: ";
	printArray( test1 );
	COUT << ENDL;
	
	std::random_shuffle ( test1.begin(), test1.end() );	
	QuickSort( test1, 0, (int)test1.size() - 1 );

	COUT << "Sorted Array  : ";	
	printArray( test1 );
	COUT << ENDL;
	
	VECTOR< VECTOR<int> > results = ThreeSums( test1 );
	
	printVecVec( results );
	
}


void test2(){
	
	VECTOR<int> test2 = {-1, 0, 1, 2, -1, 4};
	
	COUT << "Original Array: ";
	printArray( test2 );
	COUT << ENDL;
	
	std::random_shuffle ( test2.begin(), test2.end() );	
	QuickSort( test2, 0, (int)test2.size() - 1 );

	COUT << "Sorted Array  : ";	
	printArray( test2 );
	COUT << ENDL;
	
	VECTOR< VECTOR<int> > results = ThreeSums( test2 );
	
	printVecVec( results );
	
}


void test3(){
	
	VECTOR<int> test3 = {-7, 14, 22, 8, -9, 0, -3, -7, -8, -15, 9, 7, 24};
	
	COUT << "Original Array: ";
	printArray( test3 );
	COUT << ENDL;
	
	std::random_shuffle ( test3.begin(), test3.end() );	
	QuickSort( test3, 0, (int)test3.size() - 1 );

	COUT << "Sorted Array  : ";	
	printArray( test3 );
	COUT << ENDL;
	
	VECTOR< VECTOR<int> > results = ThreeSums( test3 );
	
	printVecVec( results );
	
}


int main(){
	
	
	test1();
	
	COUT << ENDL;
	
	test2();
	
	COUT << ENDL;
	
	test3();
	
	return 0;
	
}