# Author: [Your Names]
# E-mail: [Your Email]
#
# This is the Makefile for Programming Challenge 05 - CSE 20312

# gcc is for the compiler for C
PP := g++

# CFLAGS are the compiler flages for when we compile C code in this course
FLAGS := -O2 -g -Wall -Wextra -Wconversion -Wshadow -Werror -lm
CXXFLAGS := -m64 -std=c++11 -Weffc++ $(FLAGS)

# Folder Variables
SRC := src
INC := include
OBJ := objects
EXE := exe


# Initialize the folders for the objects and executables
initialize:
	mkdir $(OBJ) $(EXE)
	
	
# Max Sub Brute Force Approach
$(OBJ)/max_sub_brute.o: $(SRC)/max_sub_brute.cpp
	$(PP) $(CXXFLAGS) -c $(SRC)/max_sub_brute.cpp -o $@

# Max Sub Brute Force Approach
max_sub_brute: $(OBJ)/max_sub_brute.o
	$(PP) $(CXXFLAGS) -o $(EXE)/max_sub_brute $(OBJ)/max_sub_brute.o


# Max Sub Dynamic Force Approach
$(OBJ)/max_sub_dyn.o: $(SRC)/max_sub_dyn.cpp
	$(PP) $(CXXFLAGS) -c $(SRC)/max_sub_dyn.cpp -o $@

# Max Sub Dynamic Force Approach
max_sub_dyn: $(OBJ)/max_sub_dyn.o
	$(PP) $(CXXFLAGS) -o $(EXE)/max_sub_dyn $(OBJ)/max_sub_dyn.o


# Max Product Subarray Approach
$(OBJ)/max_prod_sub.o: $(SRC)/max_prod_sub.cpp
	$(PP) $(CXXFLAGS) -c $(SRC)/max_prod_sub.cpp -o $@

# Max Product Subarray Approach
max_prod_sub: $(OBJ)/max_prod_sub.o
	$(PP) $(CXXFLAGS) -o $(EXE)/max_prod_sub $(OBJ)/max_prod_sub.o
	
# Make clean
clean:
	rm -rf $(OBJ)/* $(EXE)/*