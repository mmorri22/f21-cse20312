# Author: Matthew Morrison
# E-mail: matt.morrison@nd.edu
#
# This is the Makefile for Lecture39

# G++ is for the GCC compiler for C++
PP := g++

# CFLAGS are the compiler flages for when we compile C code in this course
FLAGS := -O2 -g -Wall -Wextra -Wconversion -Wshadow -Werror -lm
CXXFLAGS := -m64 -std=c++11 -Weffc++ $(FLAGS)


# BitShift Example - Show how to call an BitShift
# Command: make BitShift
BitShiftObjs :=  BitShift.o

BitShift: BitShift.o
	$(PP) $(CXXFLAGS) -o BitShift $(BitShiftObjs)
	./BitShift

BitShift.o: BitShift.cpp
	$(PP) $(CXXFLAGS) -c BitShift.cpp	



	
# rmq1 Example - Range Minimum Query in n^2 preprocessing
# Command: make rmq1
rmq1Objs :=  rmq1.o

rmq1: rmq1.o
	$(PP) $(CXXFLAGS) -o rmq1 $(rmq1Objs)
	./rmq1

rmq1.o: rmq1.cpp
	$(PP) $(CXXFLAGS) -c rmq1.cpp
	
	
# rmq2 Example - Range Minimum Query with Sparse Matrix
# Command: make rmq2
rmq2Objs :=  rmq2.o

rmq2: rmq2.o
	$(PP) $(CXXFLAGS) -o rmq2 $(rmq2Objs)
	./rmq2

rmq2.o: rmq2.cpp
	$(PP) $(CXXFLAGS) -c rmq2.cpp
	

# Make all
all: BitShift matrix rmq1 rmq2

# Make clean
clean :
	rm -rf *.o BitShift procMartix matrix rmq1 rmq2
