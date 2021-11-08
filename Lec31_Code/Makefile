# Author: Matthew Morrison
# E-mail: matt.morrison@nd.edu
#
# This is the Makefile for the CSE 20312 course Lecture 31

# G++ is for the GCC compiler for C++
PP := g++

# CXXFLAGS are the compiler flages for when we compile C++ code in this course 
FLAGS := -O2 -g -Wall -Wextra -Wconversion -Wshadow -pedantic -Werror 
CXXFLAGS := -m64 -std=c++11 -Weffc++ $(FLAGS) 

#####################################################
# DFS Solution
#####################################################
DFS.o: DFS.cpp
	$(PP) $(CXXFLAGS) -c DFS.cpp -o $@	
	
DFSObjs := DFS.o 

DFS: $(DFSObjs)
	$(PP) $(CXXFLAGS) -o DFS $(DFSObjs)
	./DFS

#####################################################
# DFS Solution
#####################################################
DFS_sol.o: DFS_sol.cpp
	$(PP) $(CXXFLAGS) -c DFS_sol.cpp -o $@	
	
DFS_solObjs := DFS_sol.o 

DFS_sol: $(DFS_solObjs)
	$(PP) $(CXXFLAGS) -o DFS_sol $(DFS_solObjs)
	./DFS_sol


# Make clean
clean :
	rm -rf *.o DFS DFS_sol