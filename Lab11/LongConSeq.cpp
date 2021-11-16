#include <string>
#include <iostream>
#include <vector>
#include <unordered_map>


template<class T>
int longConsec(std::vector<T>& theArr){
	
    /* The Hash Table */
    std::unordered_map<T, int> countSort;
	
	// Insert the elements into the Hash 
    for(unsigned int iter = 0; iter < theArr.size(); iter++){
        countSort.insert({theArr[iter], 1});
    }

    int result = 0;

    for(unsigned int iter = 0; iter < theArr.size(); iter++){
        int count = 1;
        T num = theArr[iter];
		
		if( countSort.count( num ) > 0 ){
			
			T down = (T)(num - 1);
			while (countSort.count(down) != 0){
				countSort.erase(down);
				down--;
				count++;
			}
			T up = (T)(num + 1);
			while(countSort.count(up) != 0 ){
				countSort.erase(up);
				up++;
				count++;
			}
			
			if (count > result){
				result = count;
			}
			countSort.erase(num);
		}
    }
    return result;
}

template< class T >
void print_vector( const std::vector<T>& print_vec ){
	
	
	for( const T& print_val : print_vec ){
		
		std::cout << print_val << " ";
		
	}
	
	std::cout << std::endl;
	
}


int main(){
    std::cout << "Test 1: <int>" << std::endl;
    std::vector<int> theVals;
    theVals.push_back(100);
    theVals.push_back(4);
    theVals.push_back(200);
    theVals.push_back(1);
    theVals.push_back(3);
    theVals.push_back(2);
    print_vector( theVals );
    int result1 = longConsec(theVals);
    std::cout << "The length of the longest consecutive element is: " << result1 << std::endl;

    std::cout << std::endl << "Test 2: <char>" << std::endl;
    std::vector<char> theChars;
    theChars.push_back('e');
    theChars.push_back('A');
    theChars.push_back('b');
    theChars.push_back('c');
    theChars.push_back('a');
    theChars.push_back('B');
    theChars.push_back('d');
    print_vector( theChars );
    int result2 = longConsec(theChars);
    std::cout << "The length of the longest consecutive element is: " << result2 << std::endl;


    std::cout << std::endl << "Test 3: <unsigned int>" << std::endl;
    std::vector<unsigned int> theUnsigned;
    theUnsigned.push_back(31);
    theUnsigned.push_back(7);
    theUnsigned.push_back(127);
    theUnsigned.push_back(30);
    theUnsigned.push_back(28);
    theUnsigned.push_back(29);
    print_vector( theUnsigned );
    int result3 = longConsec(theUnsigned);
    std::cout << "The length of the longest consecutive element is: " << result3 << std::endl;

    std::cout << std::endl << "Test 4: <long unsigned int>" << std::endl;
    std::vector<long unsigned int> theLong;
    theLong.push_back(131);
    theLong.push_back(140);
    theLong.push_back(132);
    theLong.push_back(149);
    theLong.push_back(2);
    theLong.push_back(133);
    print_vector( theLong );
    int result4 = longConsec(theLong);
    std::cout << "The length of the longest consecutive element is: " << result4 << std::endl;


    std::cout << std::endl << "Test 5: <long unsigned int>" << std::endl;
    std::vector<long unsigned int> theLong2;
	//36, 41, 56, 35, 37, 33, 34, 92, 42, 32

    theLong2.push_back(36);
    theLong2.push_back(41);
    theLong2.push_back(56);
    theLong2.push_back(35);
    theLong2.push_back(37);
    theLong2.push_back(33);
    theLong2.push_back(34);
    theLong2.push_back(92);
    theLong2.push_back(42);
    theLong2.push_back(32);
    print_vector(  theLong2 );
    int result5 = longConsec(theLong2);
    std::cout << "The length of the longest consecutive element is: " << result5 << std::endl;

    return 0;


}
