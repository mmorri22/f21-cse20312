# This is the Makefile for the CSE 20312 course Lecture 17

# G++ is for the GCC compiler for C++
PP := g++

# CXXFLAGS are the compiler flages for when we compile C++ code in this course 
FLAGS := -O2 -g -Wall -Wextra -Wconversion -Wshadow -pedantic -Werror 
CXXFLAGS := -m64 -std=c++11 -Weffc++ $(FLAGS) 

# Variables for Folders
INC := inc
SRC := src
EXE := exe
OBJ := obj


# Command: make Prob1
# DFS Review
Prob1Objs := $(OBJ)/Prob1.o 

Prob1: $(Prob1Objs)
	$(PP) $(CXXFLAGS) -o $(EXE)/Prob1 $(Prob1Objs)
	$(EXE)/./Prob1

$(OBJ)/Prob1.o: $(SRC)/Prob1.cpp
	$(PP) $(CXXFLAGS) -c $(SRC)/Prob1.cpp -o $@



# Command: make Prob2
# Topological Sort Review
Prob2Objs := $(OBJ)/Prob2.o 

Prob2: $(Prob2Objs)
	$(PP) $(CXXFLAGS) -o $(EXE)/Prob2 $(Prob2Objs)
	$(EXE)/./Prob2

$(OBJ)/Prob2.o: $(SRC)/Prob2.cpp
	$(PP) $(CXXFLAGS) -c $(SRC)/Prob2.cpp -o $@


# Command: make Prob3
# BFS Review
Prob3Objs := $(OBJ)/Prob3.o 

Prob3: $(Prob3Objs)
	$(PP) $(CXXFLAGS) -o $(EXE)/Prob3 $(Prob3Objs)
	$(EXE)/./Prob3

$(OBJ)/Prob3.o: $(SRC)/Prob3.cpp
	$(PP) $(CXXFLAGS) -c $(SRC)/Prob3.cpp -o $@	


# Command: make Prob4
# BFS Review
Prob4Objs := $(OBJ)/Prob4.o 

Prob4: $(Prob4Objs)
	$(PP) $(CXXFLAGS) -o $(EXE)/Prob4 $(Prob4Objs)
	$(EXE)/./Prob4

$(OBJ)/Prob4.o: $(SRC)/Prob4.cpp
	$(PP) $(CXXFLAGS) -c $(SRC)/Prob4.cpp -o $@	

# Command: make Dijkstra
# Initial Examples of Dijkstra
DijkstraObjs := $(OBJ)/Dijkstra.o 

Dijkstra: $(DijkstraObjs)
	$(PP) $(CXXFLAGS) -o $(EXE)/Dijkstra $(DijkstraObjs)
	$(EXE)/./Dijkstra

$(OBJ)/Dijkstra.o: $(SRC)/Dijkstra.cpp
	$(PP) $(CXXFLAGS) -c $(SRC)/Dijkstra.cpp -o $@



# Command: make MST
MSTObjs := $(OBJ)/MST.o 

MST: $(MSTObjs)
	$(PP) $(CXXFLAGS) -o $(EXE)/MST $(MSTObjs)
	$(EXE)/./MST

$(OBJ)/MST.o: $(SRC)/MST.cpp
	$(PP) $(CXXFLAGS) -c $(SRC)/MST.cpp -o $@


# Command: make MST2
MST2Objs := $(OBJ)/MST2.o 

MST2: $(MST2Objs)
	$(PP) $(CXXFLAGS) -o $(EXE)/MST2 $(MST2Objs)
	$(EXE)/./MST2

$(OBJ)/MST2.o: $(SRC)/MST2.cpp
	$(PP) $(CXXFLAGS) -c $(SRC)/MST2.cpp -o $@


MST3Objs := $(OBJ)/MST3.o 

MST3: $(MST3Objs)
	$(PP) $(CXXFLAGS) -o $(EXE)/MST2 $(MST3Objs)
	$(EXE)/./MST2

$(OBJ)/MST3.o: $(SRC)/MST3.cpp
	$(PP) $(CXXFLAGS) -c $(SRC)/MST3.cpp -o $@


# Command: make Connected
ConnectedObjs := $(OBJ)/Connected.o 

Connected: $(ConnectedObjs)
	$(PP) $(CXXFLAGS) -o $(EXE)/Connected $(ConnectedObjs)
	$(EXE)/./Connected

$(OBJ)/Connected.o: $(SRC)/Connected.cpp
	$(PP) $(CXXFLAGS) -c $(SRC)/Connected.cpp -o $@	



# Command: make Union
UnionObjs := $(OBJ)/Union.o 

Union: $(UnionObjs)
	$(PP) $(CXXFLAGS) -o $(EXE)/Union $(UnionObjs)
	$(EXE)/./Union

$(OBJ)/Union.o: $(SRC)/Union.cpp
	$(PP) $(CXXFLAGS) -c $(SRC)/Union.cpp -o $@	



# Command: make numConnected
numConnectedObjs := $(OBJ)/numConnected.o 

numConnected: $(numConnectedObjs)
	$(PP) $(CXXFLAGS) -o $(EXE)/numConnected $(numConnectedObjs)
	$(EXE)/./numConnected

$(OBJ)/numConnected.o: $(SRC)/numConnected.cpp
	$(PP) $(CXXFLAGS) -c $(SRC)/numConnected.cpp -o $@	
	

# make initialize
# Will be called by grader to initialize your objects and executables folders
initialize: 
	mkdir $(OBJ) $(EXE)


# Make clean
clean :
	rm -rf $(OBJ)/* $(EXE)/*
