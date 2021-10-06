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

# Command: make tempVoidNode
# Shows allocating templated generic types on the heap
# using imperative and procedural programming

tempVoidNodeObjs := $(OBJ)/tempVoidNode.o

tempVoidNode: $(tempVoidNodeObjs)
	$(PP) $(CXXFLAGS) -o $(EXE)/tempVoidNode $(tempVoidNodeObjs)
	$(EXE)/./tempVoidNode

$(OBJ)/tempVoidNode.o: $(SRC)/tempVoidNode.cpp
	$(PP) $(CXXFLAGS) -c $(SRC)/tempVoidNode.cpp -o $@



# Command: make tempVoidNode2
# Shows allocating templated generic types on the heap
# using imperative and procedural programming
# Uses proper casting of float

tempVoidNode2Objs := $(OBJ)/tempVoidNode2.o

tempVoidNode2: $(tempVoidNode2Objs)
	$(PP) $(CXXFLAGS) -o $(EXE)/tempVoidNode2 $(tempVoidNode2Objs)
	$(EXE)/./tempVoidNode2

$(OBJ)/tempVoidNode2.o: $(SRC)/tempVoidNode2.cpp
	$(PP) $(CXXFLAGS) -c $(SRC)/tempVoidNode2.cpp -o $@


# Command: make tempVoidNodeBad
# Shows an example of improper memory allocation

tempVoidNodeBadObjs := $(OBJ)/tempVoidNodeBad.o

tempVoidNodeBad: $(tempVoidNodeBadObjs)
	$(PP) $(CXXFLAGS) -o $(EXE)/tempVoidNodeBad $(tempVoidNodeBadObjs)
	$(EXE)/./tempVoidNodeBad

$(OBJ)/tempVoidNodeBad.o: $(SRC)/tempVoidNodeBad.cpp
	$(PP) $(CXXFLAGS) -c $(SRC)/tempVoidNodeBad.cpp -o $@


# Command: make voidNodeCallBy
# Shows how to call a pointer by reference

voidNodeCallByObjs := $(OBJ)/voidNodeCallBy.o

voidNodeCallBy: $(voidNodeCallByObjs)
	$(PP) $(CXXFLAGS) -o $(EXE)/voidNodeCallBy $(voidNodeCallByObjs)
	$(EXE)/./voidNodeCallBy

$(OBJ)/voidNodeCallBy.o: $(SRC)/voidNodeCallBy.cpp
	$(PP) $(CXXFLAGS) -c $(SRC)/voidNodeCallBy.cpp -o $@

# Command: make template1
# Simple templated class example

template1Objs := $(OBJ)/template1.o

template1: $(template1Objs)
	$(PP) $(CXXFLAGS) -o $(EXE)/template1 $(template1Objs)
	$(EXE)/./template1

$(OBJ)/template1.o: $(SRC)/template1.cpp $(INC)/A_1.h
	$(PP) $(CXXFLAGS) -c $(SRC)/template1.cpp -o $@
	

# Command: make tempTest
# Simple templated class example

tempTestObjs := $(OBJ)/tempTest.o

tempTest: $(tempTestObjs)
	$(PP) $(CXXFLAGS) -o $(EXE)/tempTest $(tempTestObjs)
	$(EXE)/./tempTest


$(OBJ)/tempTest.o: $(SRC)/tempTest.cpp $(INC)/A.h
	$(PP) $(CXXFLAGS) -c $(SRC)/tempTest.cpp -o $@


	

# Command: make classBad
# Example of Pitfall of splitting templated classes into cpp and h
# Contains deliberate compiler errors

classBadObjs := $(OBJ)/classBad.o $(OBJ)/Abad.o

classBad: $(classBadObjs)
	$(PP) $(CXXFLAGS) -o $(EXE)/classBad $(classBadObjs)
	$(EXE)/./classBad

$(OBJ)/classBad.o: $(SRC)/classBad.cpp $(INC)/Abad.h
	$(PP) $(CXXFLAGS) -c $(SRC)/classBad.cpp -o $@
	
$(OBJ)/Abad.o: $(INC)/Abad.cpp $(INC)/Abad.h
	$(PP) $(CXXFLAGS) -c $(INC)/Abad.cpp -o $@
	
	
	
# Command: make tempBad
# Example of Pitfall of splitting bad templating
# Contains deliberate compiler errors

tempBadObjs := $(OBJ)/tempBad.o

tempBad: $(tempBadObjs)
	$(PP) $(CXXFLAGS) -o $(EXE)/tempBad $(tempBadObjs)
	$(EXE)/./tempBad

$(OBJ)/tempBad.o: $(SRC)/tempBad.cpp $(INC)/A.h
	$(PP) $(CXXFLAGS) -c $(SRC)/tempBad.cpp -o $@


# Command: make vector
vectorObjs := $(OBJ)/vector.o

vector: $(vectorObjs)
	$(PP) $(CXXFLAGS) -o $(EXE)/vector $(vectorObjs)
	$(EXE)/./vector

$(OBJ)/vector.o: $(SRC)/vector.cpp
	$(PP) $(CXXFLAGS) -c $(SRC)/vector.cpp -o $@


# Command: make quadPair
quadPairObjs := $(OBJ)/quadPair.o

quadPair: $(quadPairObjs)
	$(PP) $(CXXFLAGS) -o $(EXE)/quadPair $(quadPairObjs)
	$(EXE)/./quadPair

$(OBJ)/quadPair.o: $(SRC)/quadPair.cpp
	$(PP) $(CXXFLAGS) -c $(SRC)/quadPair.cpp -o $@


# Command: make quadPair2
quadPair2Objs := $(OBJ)/quadPair2.o

quadPair2: $(quadPair2Objs)
	$(PP) $(CXXFLAGS) -o $(EXE)/quadPair2 $(quadPair2Objs)
	$(EXE)/./quadPair2

$(OBJ)/quadPair2.o: $(SRC)/quadPair2.cpp
	$(PP) $(CXXFLAGS) -c $(SRC)/quadPair2.cpp -o $@	


# Command: make iterator
iteratorObjs := $(OBJ)/iterator.o

iterator: $(iteratorObjs)
	$(PP) $(CXXFLAGS) -o $(EXE)/iterator $(iteratorObjs)
	$(EXE)/./iterator

$(OBJ)/iterator.o: $(SRC)/iterator.cpp
	$(PP) $(CXXFLAGS) -c $(SRC)/iterator.cpp -o $@	
	
	


# make initialize
# Will be called by grader to initialize your objects and executables folders
initialize: 
	mkdir objects executables


# Make all
all: tempDest vector quadPair quadPair2 iterator

# Make clean
clean :
	rm -rf *.o $(OBJ)/* $(EXE)/*
