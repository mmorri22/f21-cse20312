# This is the Makefile for the CSE 20312 course - Lecture 12

# G++ is for the GCC compiler for C++
PP := g++

# CXXFLAGS are the compiler flages for when we compile C++ code in this course 
FLAGS := -O0 -g -Wall -Wextra -Wconversion -Wshadow -pedantic -Werror 
CXXFLAGS := -m64 -std=c++11 -Weffc++ $(FLAGS) 

# Variables for Folders
INC := inc
SRC := src
EXE := exe
OBJ := obj



# Command: make test_min_heap
test_min_heapObjs := $(OBJ)/test_min_heap.o 

test_min_heap: $(test_min_heapObjs)
	$(PP) $(CXXFLAGS) -o $(EXE)/test_min_heap $(test_min_heapObjs)

$(OBJ)/test_min_heap.o: $(SRC)/test_min_heap.cpp
	$(PP) $(CXXFLAGS) -c $(SRC)/test_min_heap.cpp -o $@

	
# Command: make testMinHeap
FindKthLargestObjs := $(OBJ)/FindKthLargest.o 

FindKthLargest: $(FindKthLargestObjs)
	$(PP) $(CXXFLAGS) -o $(EXE)/FindKthLargest $(FindKthLargestObjs)
	$(EXE)/./FindKthLargest

$(OBJ)/FindKthLargest.o: $(SRC)/FindKthLargest.cpp
	$(PP) $(CXXFLAGS) -c $(SRC)/FindKthLargest.cpp -o $@
	


# Command: make FindMedian
FindMedianObjs := $(OBJ)/FindMedian.o 

FindMedian: $(FindMedianObjs)
	$(PP) $(CXXFLAGS) -o $(EXE)/FindMedian $(FindMedianObjs)
	$(EXE)/./FindMedian

$(OBJ)/FindMedian.o: $(SRC)/FindMedian.cpp
	$(PP) $(CXXFLAGS) -c $(SRC)/FindMedian.cpp -o $@



# Make all
all: FindKthLargest FindMedian Prob3 Prob1



# make initialize
# Will be called by grader to initialize your objects and executables folders
initialize: 
	mkdir $(OBJ) $(EXE)
	

# Make clean
clean :
	rm -rf $(OBJ)/* $(EXE)/*
