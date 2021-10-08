# Author: Matthew Morrison
# E-mail: matt.morrison@nd.edu
#
# This is the Makefile for the CSE 20312 course Lecture 10

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
# Problem 4
#####################################################
# Command: make Prob4
Prob4Objs :=  $(OBJ)/Prob4.o

Prob4: $(Prob4Objs)
	$(PP) $(CXXFLAGS) -o $(EXE)/Prob4 $(Prob4Objs)
	$(EXE)/./Prob4

$(OBJ)/Prob4.o: $(SRC)/Prob4.cpp
	$(PP) $(CXXFLAGS) -c $(SRC)/Prob4.cpp -o $@
	
	
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
	

# make initialize
# Will be called by grader to initialize your objects and executables folders

initialize: 
	mkdir $(OBJ) $(EXE)
	

# Make clean
clean :
	rm -rf *.o $(OBJ)/* $(EXE)/*
