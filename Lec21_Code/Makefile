# Author: Matthew Morrison
# E-mail: matt.morrison@nd.edu
#
# This is the Makefile for the CSE 20312 course Lecture 20

# G++ is for the GCC compiler for C++
PP := g++


# CXXFLAGS are the compiler flages for when we compile C++ code in this course 
FLAGS := -O2 -g -Wall -Wextra -Wconversion -Wshadow -Werror 
CXXFLAGS := -m64 -std=c++11 -Weffc++ $(FLAGS) 


INC := include
SRC := src
OBJ := obj
EXE := exe


# Command: make sll_test
$(OBJ)/sll_test.o: $(SRC)/sll_test.cpp
	$(PP) $(CXXFLAGS) -c $(SRC)/sll_test.cpp -o $@

sll_test_objs := $(OBJ)/sll_test.o

sll_test: $(sll_test_objs)
	$(PP) $(CXXFLAGS) -o $(EXE)/sll_test $(sll_test_objs)



# Command: make stack_test
$(OBJ)/stack_test.o: $(SRC)/stack_test.cpp
	$(PP) $(CXXFLAGS) -c $(SRC)/stack_test.cpp -o $@

stack_test_objs := $(OBJ)/stack_test.o

stack_test: $(stack_test_objs)
	$(PP) $(CXXFLAGS) -o $(EXE)/stack_test $(stack_test_objs)



# Command: make ComplexTest
# Shows allocating templated generic types on the heap
# using imperative and procedural programming

ComplexTestObjs := $(OBJ)/ComplexTest.o $(OBJ)/Complex.o

ComplexTest: $(ComplexTestObjs)
	$(PP) $(CXXFLAGS) -o $(EXE)/ComplexTest $(ComplexTestObjs)
	$(EXE)/./ComplexTest

$(OBJ)/ComplexTest.o: $(SRC)/ComplexTest.cpp
	$(PP) $(CXXFLAGS) -c $(SRC)/ComplexTest.cpp -o $@

$(OBJ)/Complex.o: $(SRC)/Complex.cpp
	$(PP) $(CXXFLAGS) -c $(SRC)/Complex.cpp -o $@


	


# make initialize
# Will be called by grader to initialize your objects and executables folders
initialize: 
	mkdir objects executables


# Make all
all: tempDest vector quadPair quadPair2 iterator

# Make clean
clean :
	rm -rf *.o $(OBJ)/* $(EXE)/*
