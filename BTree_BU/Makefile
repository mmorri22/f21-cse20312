# This is the Makefile for the CSE 20312 course - Lecture 12

# G++ is for the GCC compiler for C++
PP := g++

# CXXFLAGS are the compiler flages for when we compile C++ code in this course 
FLAGS := -O2 -g -Wall -Wextra -Wconversion -Werror 
CXXFLAGS := -m64 -std=c++11 -Weffc++ $(FLAGS) 

# Variables for Folders
INC := inc
SRC := src
EXE := exe
OBJ := obj


# Command: make test_b_tree
test_b_treeObjs := test_b_tree.o 

test_b_tree: $(test_b_treeObjs)
	$(PP) $(CXXFLAGS) -o test_b_tree $(test_b_treeObjs)

test_b_tree.o: test_b_tree.cpp
	$(PP) $(CXXFLAGS) -c test_b_tree.cpp -o $@

	

# Make clean
clean :
	rm -rf *.o test_b_tree
