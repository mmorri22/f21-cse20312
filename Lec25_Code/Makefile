# Author: Matthew Morrison
# E-mail: matt.morrison@nd.edu
#
# This is the Makefile for the CSE 20312 - Lab 03

# G++ is for the GCC compiler for C++
PP := g++

# CXXFLAGS are the compiler flages for when we compile C++ code in this course 
FLAGS := -O0 -g -Wall -Wextra -Wconversion -Wshadow -pedantic -Werror 
CXXFLAGS := -m64 -std=c++11 -Weffc++ $(FLAGS) 


INC := include
SRC := src
OBJ := obj
EXE := exe


# Command: make containsDup
containsDupObjs := $(OBJ)/containsDup.o

containsDup: $(containsDupObjs)
	$(PP) $(CXXFLAGS) -o $(EXE)/containsDup $(containsDupObjs)
	$(EXE)/./containsDup

$(OBJ)/containsDup.o: $(SRC)/containsDup.cpp $(INC)/LinearProbe.h
	$(PP) $(CXXFLAGS) -c $(SRC)/containsDup.cpp -o $@



# Command: make TwoSums
TwoSumsObjs := $(OBJ)/TwoSums.o

TwoSums: $(TwoSumsObjs)
	$(PP) $(CXXFLAGS) -o $(EXE)/TwoSums $(TwoSumsObjs)
	$(EXE)/./TwoSums

$(OBJ)/TwoSums.o: $(SRC)/TwoSums.cpp
	$(PP) $(CXXFLAGS) -c $(SRC)/TwoSums.cpp -o $@	



# Command: make 3Sum
3SumObjs := $(OBJ)/3Sum.o

3Sum: $(3SumObjs)
	$(PP) $(CXXFLAGS) -o $(EXE)/3Sum $(3SumObjs)
	$(EXE)/./3Sum

$(OBJ)/3Sum.o: $(SRC)/3Sum.cpp
	$(PP) $(CXXFLAGS) -c $(SRC)/3Sum.cpp -o $@


# make initialize
# Will be called by grader to initialize your objects and executables folders

initialize: 
	mkdir $(OBJ) $(EXE)
	


# Make all
all: containsDup TwoSums

# Make clean
clean :
	rm -rf *.o $(OBJ)/* $(EXE)/*
