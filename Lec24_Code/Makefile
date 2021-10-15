# Author: Matthew Morrison
# E-mail: matt.morrison@nd.edu
#
# This is the Makefile for the CSE 20312 course Lecture 23

# G++ is for the GCC compiler for C++
PP := g++

# CXXFLAGS are the compiler flages for when we compile C++ code in this course 
FLAGS := -O2 -g -Wall -Wextra -Wconversion -Wshadow -pedantic -Werror
CXXFLAGS := -m64 -std=c++11 -Weffc++ $(FLAGS)


INC := include
SRC := src
OBJ := objects
EXE := exe


# Command: make HashTest1
HashTest1Objs := $(OBJ)/HashTest1.o

HashTest1: $(HashTest1Objs)
	$(PP) $(CXXFLAGS) -o $(EXE)/HashTest1 $(HashTest1Objs)

$(OBJ)/HashTest1.o: $(SRC)/HashTest1.cpp
	$(PP) $(CXXFLAGS) -c $(SRC)/HashTest1.cpp -o $@



# Command: make HashTest2
HashTest2Objs := $(OBJ)/HashTest2.o

HashTest2: $(HashTest2Objs)
	$(PP) $(CXXFLAGS) -o $(EXE)/HashTest2 $(HashTest2Objs)

$(OBJ)/HashTest2.o: $(SRC)/HashTest2.cpp
	$(PP) $(CXXFLAGS) -c $(SRC)/HashTest2.cpp -o $@



# Command: make HashTest3
HashTest3Objs := $(OBJ)/HashTest3.o

HashTest3: $(HashTest3Objs)
	$(PP) $(CXXFLAGS) -o $(EXE)/HashTest3 $(HashTest3Objs)

$(OBJ)/HashTest3.o: $(SRC)/HashTest3.cpp
	$(PP) $(CXXFLAGS) -c $(SRC)/HashTest3.cpp -o $@



# Command: make HashTest4
HashTest4Objs := $(OBJ)/HashTest4.o

HashTest4: $(HashTest4Objs)
	$(PP) $(CXXFLAGS) -o $(EXE)/HashTest4 $(HashTest4Objs)

$(OBJ)/HashTest4.o: $(SRC)/HashTest4.cpp
	$(PP) $(CXXFLAGS) -c $(SRC)/HashTest4.cpp -o $@


# Command: make HashTest5
HashTest5Objs := $(OBJ)/HashTest5.o

HashTest5: $(HashTest5Objs)
	$(PP) $(CXXFLAGS) -o $(EXE)/HashTest5 $(HashTest5Objs)

$(OBJ)/HashTest5.o: $(SRC)/HashTest5.cpp
	$(PP) $(CXXFLAGS) -c $(SRC)/HashTest5.cpp -o $@


# Command: make HashTest6
HashTest6Objs := $(OBJ)/HashTest6.o

HashTest6: $(HashTest6Objs)
	$(PP) $(CXXFLAGS) -o $(EXE)/HashTest6 $(HashTest6Objs)

$(OBJ)/HashTest6.o: $(SRC)/HashTest6.cpp
	$(PP) $(CXXFLAGS) -c $(SRC)/HashTest6.cpp -o $@


# Command: make HashTest7
HashTest7Objs := $(OBJ)/HashTest7.o

HashTest7: $(HashTest7Objs)
	$(PP) $(CXXFLAGS) -o $(EXE)/HashTest7 $(HashTest7Objs)

$(OBJ)/HashTest7.o: $(SRC)/HashTest7.cpp
	$(PP) $(CXXFLAGS) -c $(SRC)/HashTest7.cpp -o $@


# Command: make Google
GoogleObjs := $(OBJ)/Google.o

Google: $(GoogleObjs)
	$(PP) $(CXXFLAGS) -o $(EXE)/Google $(GoogleObjs)

$(OBJ)/Google.o: $(SRC)/Google.cpp
	$(PP) $(CXXFLAGS) -c $(SRC)/Google.cpp -o $@



# make initialize
# Will be called by grader to initialize your objects and executables folders

initialize: 
	mkdir $(OBJ) $(EXE)
	

# Make clean
clean :
	rm -rf $(OBJ)/* $(EXE)/*
