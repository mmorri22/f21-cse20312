# This is the Makefile for the CSE 20312 course - Lecture 36

# G++ is for the GCC compiler for C++
PP := g++

# CXXFLAGS are the compiler flages for when we compile C++ code in this course 
FLAGS := -O0 -g -Wall -Wextra -Wconversion -Wshadow -pedantic -Werror 
CXXFLAGS := -m64 -std=c++11 -Weffc++ $(FLAGS) 

# Variables for Folders
INC := include
SRC := src
EXE := exe
OBJ := obj


	
# Command: make SubsetSums
# Initial Examples of bitsets using Subset Sum problem
SubsetSumsObjs := $(OBJ)/SubsetSums.o 

SubsetSums: $(SubsetSumsObjs)
	$(PP) $(CXXFLAGS) -o $(EXE)/SubsetSums $(SubsetSumsObjs)
	$(EXE)/./SubsetSums

$(OBJ)/SubsetSums.o: $(SRC)/SubsetSums.cpp
	$(PP) $(CXXFLAGS) -c $(SRC)/SubsetSums.cpp -o $@



# Command: make HammingDist
# Calculate the Hamming Distance of an unsigned integer
HammingDistObjs := $(OBJ)/HammingDist.o 

HammingDist: $(HammingDistObjs)
	$(PP) $(CXXFLAGS) -o $(EXE)/HammingDist $(HammingDistObjs)
	$(EXE)/./HammingDist

$(OBJ)/HammingDist.o: $(SRC)/HammingDist.cpp
	$(PP) $(CXXFLAGS) -c $(SRC)/HammingDist.cpp -o $@



# Command: make Reverse Dist
# Reverses the Bits of an unsigned int
ReverseBitsObjs := $(OBJ)/ReverseBits.o 

ReverseBits: $(ReverseBitsObjs)
	$(PP) $(CXXFLAGS) -o $(EXE)/ReverseBits $(ReverseBitsObjs)
	$(EXE)/./ReverseBits

$(OBJ)/ReverseBits.o: $(SRC)/ReverseBits.cpp
	$(PP) $(CXXFLAGS) -c $(SRC)/ReverseBits.cpp -o $@
	
	

# Command: make BloomURL
# Initial Examples of Bloom Filter
BloomURLObjs := $(OBJ)/BloomURL.o 

BloomURL: $(BloomURLObjs)
	$(PP) $(CXXFLAGS) -o $(EXE)/BloomURL $(BloomURLObjs)
	$(EXE)/./BloomURL $(SRC)/Access_URLs.txt $(SRC)/NDCSE_URLs.txt

$(OBJ)/BloomURL.o: $(SRC)/BloomURL.cpp
	$(PP) $(CXXFLAGS) -c $(SRC)/BloomURL.cpp -o $@

# Initialize 
initialize:
	mkdir $(OBJ) $(EXE)

# Make all
all: SubsetSums ReverseBits HammingDist BloomURL

# Make clean
clean :
	rm -rf *.o $(OBJ)/* $(EXE)/*
