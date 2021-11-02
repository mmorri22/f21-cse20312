# This is the Makefile for the CSE 20312 course - Lecture 25

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

# Command: make Prob1
Prob1Objs := $(OBJ)/Prob1.o

Prob1: $(Prob1Objs)
	$(PP) $(CXXFLAGS) -o $(EXE)/Prob1 $(Prob1Objs)
	$(EXE)/./Prob1

$(OBJ)/Prob1.o: $(SRC)/Prob1.cpp
	$(PP) $(CXXFLAGS) -c $(SRC)/Prob1.cpp -o $@


# Command: make Prob2
Prob2Objs := $(OBJ)/Prob2.o

Prob2: $(Prob2Objs)
	$(PP) $(CXXFLAGS) -o $(EXE)/Prob2 $(Prob2Objs)
	$(EXE)/./Prob2

$(OBJ)/Prob2.o: $(SRC)/Prob2.cpp
	$(PP) $(CXXFLAGS) -c $(SRC)/Prob2.cpp -o $@


# Command: make SplayTest
# Shows a successful Splay Tree Test
SplayTestObjs := $(OBJ)/SplayTest.o

SplayTest: $(SplayTestObjs)
	$(PP) $(CXXFLAGS) -o $(EXE)/SplayTest $(SplayTestObjs)
	$(EXE)/./SplayTest

$(OBJ)/SplayTest.o: $(SRC)/SplayTest.cpp $(INC)/SplayTree.h
	$(PP) $(CXXFLAGS) -c $(SRC)/SplayTest.cpp -o $@



# Command: make CacheExample
# Shows a SplayTree accessing memory locations
CacheExampleObjs := $(OBJ)/CacheExample.o

CacheExample: $(CacheExampleObjs)
	$(PP) $(CXXFLAGS) -o $(EXE)/CacheExample $(CacheExampleObjs)
	$(EXE)/./CacheExample

$(OBJ)/CacheExample.o: $(SRC)/CacheExample.cpp $(INC)/SplayTree.h
	$(PP) $(CXXFLAGS) -c $(SRC)/CacheExample.cpp -o $@
	

	
# Command: make TreapInsert
# Tests the Treap Insert Results
TreapInsertObjs := $(OBJ)/TreapInsert.o 

TreapInsert: $(TreapInsertObjs)
	$(PP) $(CXXFLAGS) -o $(EXE)/TreapInsert $(TreapInsertObjs)
	$(EXE)/./TreapInsert

$(OBJ)/TreapInsert.o: $(SRC)/TreapInsert.cpp $(INC)/Treap2.h
	$(PP) $(CXXFLAGS) -c $(SRC)/TreapInsert.cpp -o $@


# Command: make InsertRandom
# Tests the Treap Insert Results
InsertRandomObjs := $(OBJ)/InsertRandom.o 

InsertRandom: $(InsertRandomObjs)
	$(PP) $(CXXFLAGS) -o $(EXE)/InsertRandom $(InsertRandomObjs)
	$(EXE)/./InsertRandom

$(OBJ)/InsertRandom.o: $(SRC)/InsertRandom.cpp $(INC)/Treap3.h
	$(PP) $(CXXFLAGS) -c $(SRC)/InsertRandom.cpp -o $@
	
	
# Command: make InsertRandom2
# Tests height for 100 versions of 100 inserts
InsertRandom2Objs := $(OBJ)/InsertRandom2.o 

InsertRandom2: $(InsertRandom2Objs)
	$(PP) $(CXXFLAGS) -o $(EXE)/InsertRandom2 $(InsertRandom2Objs)
	$(EXE)/./InsertRandom2

$(OBJ)/InsertRandom2.o: $(SRC)/InsertRandom2.cpp $(INC)/Treap4.h
	$(PP) $(CXXFLAGS) -c $(SRC)/InsertRandom2.cpp -o $@
	
	
# Command: make TreapTest
# Tests the Treap Insert Results
TreapTestObjs := $(OBJ)/TreapTest.o 

TreapTest: $(TreapTestObjs)
	$(PP) $(CXXFLAGS) -o $(EXE)/TreapTest $(TreapTestObjs)
	$(EXE)/./TreapTest

$(OBJ)/TreapTest.o: $(SRC)/TreapTest.cpp $(INC)/Treap.h
	$(PP) $(CXXFLAGS) -c $(SRC)/TreapTest.cpp -o $@


# Command: make Prob4
Prob4Objs := $(OBJ)/Prob4.o

Prob4: $(Prob4Objs)
	$(PP) $(CXXFLAGS) -o $(EXE)/Prob4 $(Prob4Objs)
	$(EXE)/./Prob4

$(OBJ)/Prob4.o: $(SRC)/Prob4.cpp
	$(PP) $(CXXFLAGS) -c $(SRC)/Prob4.cpp -o $@

# Initialize 
initialize:
	mkdir $(OBJ) $(EXE)

# Make all
all: SubsetSums BloomURL

# Make clean
clean :
	rm -rf *.o $(OBJ)/* $(EXE)/*
