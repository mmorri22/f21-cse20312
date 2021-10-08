# Author: Matthew Morrison
# E-mail: matt.morrison@nd.edu
#
# This is the Makefile for the CSE 20312 course Lecture 11

# G++ is for the GCC compiler for C++
PP := g++

# CXXFLAGS are the compiler flages for when we compile C++ code in this course 
FLAGS := -O0 -g -Wall -Wextra -Wconversion -Wshadow -pedantic -Werror 
CXXFLAGS := -m64 -std=c++11 -Weffc++ $(FLAGS) 


INC := inc
SRC := src
OBJ := obj
EXE := exe


# Command: make switch
switchObjs := $(OBJ)/switch.o

switch: $(switchObjs)
	$(PP) $(CXXFLAGS) -o $(EXE)/switch $(switchObjs)
	$(EXE)/./switch

$(OBJ)/switch.o: $(SRC)/switch.cpp
	$(PP) $(CXXFLAGS) -c $(SRC)/switch.cpp -o $@



# Command: make LPTest1
LPTest1Objs := $(OBJ)/LPTest1.o

LPTest1: $(LPTest1Objs)
	$(PP) $(CXXFLAGS) -o $(EXE)/LPTest1 $(LPTest1Objs)
	$(EXE)/./LPTest1

$(OBJ)/LPTest1.o: $(SRC)/LPTest1.cpp $(INC)/LinearProbe1.h
	$(PP) $(CXXFLAGS) -c $(SRC)/LPTest1.cpp -o $@



# Command: make LPTest2
LPTest2Objs := $(OBJ)/LPTest2.o

LPTest2: $(LPTest2Objs)
	$(PP) $(CXXFLAGS) -o $(EXE)/LPTest2 $(LPTest2Objs)
	$(EXE)/./LPTest2

$(OBJ)/LPTest2.o: $(SRC)/LPTest2.cpp $(INC)/LinearProbe2.h
	$(PP) $(CXXFLAGS) -c $(SRC)/LPTest2.cpp -o $@



# Command: make LPTest3
LPTest3Objs := $(OBJ)/LPTest3.o

LPTest3: $(LPTest3Objs)
	$(PP) $(CXXFLAGS) -o $(EXE)/LPTest3 $(LPTest3Objs)
	$(EXE)/./LPTest3

$(OBJ)/LPTest3.o: $(SRC)/LPTest3.cpp $(INC)/LinearProbe3.h
	$(PP) $(CXXFLAGS) -c $(SRC)/LPTest3.cpp -o $@



# Command: make LPTest4
LPTest4Objs := $(OBJ)/LPTest4.o

LPTest4: $(LPTest4Objs)
	$(PP) $(CXXFLAGS) -o $(EXE)/LPTest4 $(LPTest4Objs)
	$(EXE)/./LPTest4

$(OBJ)/LPTest4.o: $(SRC)/LPTest4.cpp $(INC)/LinearProbe4.h
	$(PP) $(CXXFLAGS) -c $(SRC)/LPTest4.cpp -o $@


# Command: make LPTest5
LPTest5Objs := $(OBJ)/LPTest5.o

LPTest5: $(LPTest5Objs)
	$(PP) $(CXXFLAGS) -o $(EXE)/LPTest5 $(LPTest5Objs)
	$(EXE)/./LPTest5

$(OBJ)/LPTest5.o: $(SRC)/LPTest5.cpp $(INC)/LinearProbe5.h
	$(PP) $(CXXFLAGS) -c $(SRC)/LPTest5.cpp -o $@


# Command: make LPTest6
LPTest6Objs := $(OBJ)/LPTest6.o

LPTest6: $(LPTest6Objs)
	$(PP) $(CXXFLAGS) -o $(EXE)/LPTest6 $(LPTest6Objs)
	$(EXE)/./LPTest6

$(OBJ)/LPTest6.o: $(SRC)/LPTest6.cpp $(INC)/LinearProbe6.h
	$(PP) $(CXXFLAGS) -c $(SRC)/LPTest6.cpp -o $@


# Command: make LPTest7
LPTest7Objs := $(OBJ)/LPTest7.o

LPTest7: $(LPTest7Objs)
	$(PP) $(CXXFLAGS) -o $(EXE)/LPTest7 $(LPTest7Objs)
	$(EXE)/./LPTest7

$(OBJ)/LPTest7.o: $(SRC)/LPTest7.cpp $(INC)/LinearProbe7.h
	$(PP) $(CXXFLAGS) -c $(SRC)/LPTest7.cpp -o $@


# Command: make LPTest8
LPTest8Objs := $(OBJ)/LPTest8.o

LPTest8: $(LPTest8Objs)
	$(PP) $(CXXFLAGS) -o $(EXE)/LPTest8 $(LPTest8Objs)
	$(EXE)/./LPTest8

$(OBJ)/LPTest8.o: $(SRC)/LPTest8.cpp $(INC)/LinearProbe.h
	$(PP) $(CXXFLAGS) -c $(SRC)/LPTest8.cpp -o $@
	


# Command: make LPTest
LPTestObjs := $(OBJ)/LPTest.o

LPTest: $(LPTestObjs)
	$(PP) $(CXXFLAGS) -o $(EXE)/LPTest $(LPTestObjs)
	$(EXE)/./LPTest

$(OBJ)/LPTest.o: $(SRC)/LPTest.cpp $(INC)/LinearProbe.h
	$(PP) $(CXXFLAGS) -c $(SRC)/LPTest.cpp -o $@


#####################################################
# Problem 1
#####################################################
# Command: make Prob1
Prob1Objs :=  $(OBJ)/Prob1.o

Prob1: $(Prob1Objs)
	$(PP) $(CXXFLAGS) -o $(EXE)/Prob1 $(Prob1Objs)
	$(EXE)/./Prob1

$(OBJ)/Prob1.o: $(SRC)/Prob1.cpp
	$(PP) $(CXXFLAGS) -c $(SRC)/Prob1.cpp -o $@
	
	
#####################################################
# Problem 2
#####################################################
# Command: make Prob2
Prob2Objs :=  $(OBJ)/Prob2.o

Prob2: $(Prob2Objs)
	$(PP) $(CXXFLAGS) -o $(EXE)/Prob2 $(Prob2Objs)
	$(EXE)/./Prob2

$(OBJ)/Prob2.o: $(SRC)/Prob2.cpp
	$(PP) $(CXXFLAGS) -c $(SRC)/Prob2.cpp -o $@



# Command: make testMaxHeap1
testMaxHeap1Objs := $(OBJ)/testMaxHeap1.o 

testMaxHeap1: $(testMaxHeap1Objs)
	$(PP) $(CXXFLAGS) -o $(EXE)/testMaxHeap1 $(testMaxHeap1Objs)
	$(EXE)/./testMaxHeap1

$(OBJ)/testMaxHeap1.o: $(SRC)/testMaxHeap1.cpp $(INC)/MaxHeap1.h
	$(PP) $(CXXFLAGS) -c $(SRC)/testMaxHeap1.cpp -o $@



# Command: make testMaxHeap2
testMaxHeap2Objs := $(OBJ)/testMaxHeap2.o 

testMaxHeap2: $(testMaxHeap2Objs)
	$(PP) $(CXXFLAGS) -o $(EXE)/testMaxHeap2 $(testMaxHeap2Objs)
	$(EXE)/./testMaxHeap2

$(OBJ)/testMaxHeap2.o: $(SRC)/testMaxHeap2.cpp $(INC)/MaxHeap2.h
	$(PP) $(CXXFLAGS) -c $(SRC)/testMaxHeap2.cpp -o $@



# Command: make testMaxHeap3
testMaxHeap3Objs := $(OBJ)/testMaxHeap3.o 

testMaxHeap3: $(testMaxHeap3Objs)
	$(PP) $(CXXFLAGS) -o $(EXE)/testMaxHeap3 $(testMaxHeap3Objs)
	$(EXE)/./testMaxHeap3

$(OBJ)/testMaxHeap3.o: $(SRC)/testMaxHeap3.cpp $(INC)/MaxHeap3.h
	$(PP) $(CXXFLAGS) -c $(SRC)/testMaxHeap3.cpp -o $@
	
	
	
# Command: make PQTest
PQTestObjs := $(OBJ)/PQTest.o 

PQTest: $(PQTestObjs)
	$(PP) $(CXXFLAGS) -o $(EXE)/PQTest $(PQTestObjs)

$(OBJ)/PQTest.o: $(SRC)/PQTest.cpp $(INC)/PriorityQueue.h
	$(PP) $(CXXFLAGS) -c $(SRC)/PQTest.cpp -o $@


#####################################################
# Problem 5
#####################################################
# Command: make Prob5
Prob5Objs :=  $(OBJ)/Prob5.o

Prob5: $(Prob5Objs)
	$(PP) $(CXXFLAGS) -o $(EXE)/Prob5 $(Prob5Objs)
	$(EXE)/./Prob5

$(OBJ)/Prob5.o: $(SRC)/Prob5.cpp
	$(PP) $(CXXFLAGS) -c $(SRC)/Prob5.cpp -o $@
	
	
#####################################################
# Problem 6
#####################################################
# Command: make Prob6
Prob6Objs :=  $(OBJ)/Prob6.o

Prob6: $(Prob6Objs)
	$(PP) $(CXXFLAGS) -o $(EXE)/Prob6 $(Prob6Objs)
	$(EXE)/./Prob6

$(OBJ)/Prob6.o: $(SRC)/Prob6.cpp
	$(PP) $(CXXFLAGS) -c $(SRC)/Prob6.cpp -o $@


#####################################################
# Problem 7
#####################################################
# Command: make Prob7
Prob7Objs :=  $(OBJ)/Prob7.o

Prob7: $(Prob7Objs)
	$(PP) $(CXXFLAGS) -o $(EXE)/Prob7 $(Prob7Objs)
	$(EXE)/./Prob7

$(OBJ)/Prob7.o: $(SRC)/Prob7.cpp
	$(PP) $(CXXFLAGS) -c $(SRC)/Prob7.cpp -o $@	

# make initialize
# Will be called by grader to initialize your objects and executables folders

initialize: 
	mkdir $(OBJ) $(EXE)
	

# Make clean
clean :
	rm -rf *.o $(OBJ)/* $(EXE)/*
