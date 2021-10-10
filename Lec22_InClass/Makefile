# This is the Makefile for the CSE 20312 course - Lecture 22

# G++ is for the GCC compiler for C++
PP := g++

# CXXFLAGS are the compiler flages for when we compile C++ code in this course 
FLAGS := -O2 -g -Wall -Wextra -Wconversion -Wshadow -pedantic -Werror 
CXXFLAGS := -m64 -std=c++11 -Weffc++ $(FLAGS) 

	
# Command: make test_min_heap
test_min_heap.o: test_min_heap.cpp
	$(PP) $(CXXFLAGS) -c test_min_heap.cpp -o $@
	
test_min_heapObjs := test_min_heap.o 

test_min_heap: $(test_min_heapObjs)
	$(PP) $(CXXFLAGS) -o test_min_heap $(test_min_heapObjs)


# Command: make test_max_heap
test_max_heap.o: test_max_heap.cpp
	$(PP) $(CXXFLAGS) -c test_max_heap.cpp -o $@
	
test_max_heapObjs := test_max_heap.o 

test_max_heap: $(test_max_heapObjs)
	$(PP) $(CXXFLAGS) -o test_max_heap $(test_max_heapObjs)


# Make all
all: test_min_heap
	

# Make clean
clean :
	rm -rf *.o test_min_heap
