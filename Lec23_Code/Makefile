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


# Command: make HashTest1
HashTest1Objs := $(OBJ)/HashTest1.o

HashTest1: $(HashTest1Objs)
	$(PP) $(CXXFLAGS) -o $(EXE)/HashTest1 $(HashTest1Objs)
	$(EXE)/./HashTest1

$(OBJ)/HashTest1.o: $(SRC)/HashTest1.cpp
	$(PP) $(CXXFLAGS) -c $(SRC)/HashTest1.cpp -o $@



# Command: make HashTest2
HashTest2Objs := $(OBJ)/HashTest2.o

HashTest2: $(HashTest2Objs)
	$(PP) $(CXXFLAGS) -o $(EXE)/HashTest2 $(HashTest2Objs)
	$(EXE)/./HashTest2

$(OBJ)/HashTest2.o: $(SRC)/HashTest2.cpp
	$(PP) $(CXXFLAGS) -c $(SRC)/HashTest2.cpp -o $@



# Command: make HashTest3
HashTest3Objs := $(OBJ)/HashTest3.o

HashTest3: $(HashTest3Objs)
	$(PP) $(CXXFLAGS) -o $(EXE)/HashTest3 $(HashTest3Objs)
	$(EXE)/./HashTest3

$(OBJ)/HashTest3.o: $(SRC)/HashTest3.cpp
	$(PP) $(CXXFLAGS) -c $(SRC)/HashTest3.cpp -o $@



# Command: make HashTest4
HashTest4Objs := $(OBJ)/HashTest4.o

HashTest4: $(HashTest4Objs)
	$(PP) $(CXXFLAGS) -o $(EXE)/HashTest4 $(HashTest4Objs)
	$(EXE)/./HashTest4

$(OBJ)/HashTest4.o: $(SRC)/HashTest4.cpp
	$(PP) $(CXXFLAGS) -c $(SRC)/HashTest4.cpp -o $@


# Command: make HashTest5
HashTest5Objs := $(OBJ)/HashTest5.o

HashTest5: $(HashTest5Objs)
	$(PP) $(CXXFLAGS) -o $(EXE)/HashTest5 $(HashTest5Objs)
	$(EXE)/./HashTest5

$(OBJ)/HashTest5.o: $(SRC)/HashTest5.cpp
	$(PP) $(CXXFLAGS) -c $(SRC)/HashTest5.cpp -o $@


# Command: make HashTest6
HashTest6Objs := $(OBJ)/HashTest6.o

HashTest6: $(HashTest6Objs)
	$(PP) $(CXXFLAGS) -o $(EXE)/HashTest6 $(HashTest6Objs)
	$(EXE)/./HashTest6

$(OBJ)/HashTest6.o: $(SRC)/HashTest6.cpp
	$(PP) $(CXXFLAGS) -c $(SRC)/HashTest6.cpp -o $@


# Command: make HashTest7
HashTest7Objs := $(OBJ)/HashTest7.o

HashTest7: $(HashTest7Objs)
	$(PP) $(CXXFLAGS) -o $(EXE)/HashTest7 $(HashTest7Objs)
	$(EXE)/./HashTest7

$(OBJ)/HashTest7.o: $(SRC)/HashTest7.cpp
	$(PP) $(CXXFLAGS) -c $(SRC)/HashTest7.cpp -o $@


# Command: make HashTest8
HashTest8Objs := $(OBJ)/HashTest8.o

HashTest8: $(HashTest8Objs)
	$(PP) $(CXXFLAGS) -o $(EXE)/HashTest8 $(HashTest8Objs)
	$(EXE)/./HashTest8

$(OBJ)/HashTest8.o: $(SRC)/HashTest8.cpp
	$(PP) $(CXXFLAGS) -c $(SRC)/HashTest8.cpp -o $@
	


# Command: make HashTest
HashTestObjs := $(OBJ)/HashTest.o

HashTest: $(HashTestObjs)
	$(PP) $(CXXFLAGS) -o $(EXE)/HashTest $(HashTestObjs)
	$(EXE)/./HashTest

$(OBJ)/HashTest.o: $(SRC)/HashTest.cpp 
	$(PP) $(CXXFLAGS) -c $(SRC)/HashTest.cpp -o $@




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



# make initialize
# Will be called by grader to initialize your objects and executables folders

initialize: 
	mkdir $(OBJ) $(EXE)
	

# Make clean
clean :
	rm -rf *.o $(OBJ)/* $(EXE)/*
