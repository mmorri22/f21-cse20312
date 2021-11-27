# Author: Matthew Morrison
# E-mail: matt.morrison@nd.edu
#
# This is the Makefile for Lecture 03 - Part 1

# G++ is for the GCC compiler for C++
PP := g++

# CFLAGS are the compiler flages for when we compile C code in this course
FLAGS := -O0 -g -Wall -Wextra -Wconversion -Wshadow -pedantic -Werror -lm
CXXFLAGS := -m64 -std=c++11 -Weffc++ $(FLAGS)


# passBy Example - Pass By Reference
# Command: make passBy
passByObjs :=  passBy.o

passBy: passBy.o
	$(PP) $(CXXFLAGS) -o passBy $(passByObjs)
	./passBy

passBy.o: passBy.cpp
	$(PP) $(CXXFLAGS) -c passBy.cpp	


# callBy Example - Call By Reference
# Command: make callBy
callByObjs :=  callBy.o

callBy: callBy.o
	$(PP) $(CXXFLAGS) -o callBy $(callByObjs)
	./callBy

callBy.o: callBy.cpp
	$(PP) $(CXXFLAGS) -c callBy.cpp	


# helloCmdLine Example - Shows how char** is structured
# Command: make helloCmdLine
helloCmdLineObjs :=  helloCmdLine.o

helloCmdLine: helloCmdLine.o
	$(PP) $(CXXFLAGS) -o helloCmdLine $(helloCmdLineObjs)
	./helloCmdLine Hello, World!

helloCmdLine.o: helloCmdLine.cpp
	$(PP) $(CXXFLAGS) -c helloCmdLine.cpp	


# array Example - Show how to call an array
# Command: make array
arrayObjs :=  array.o

array: array.o
	$(PP) $(CXXFLAGS) -o array $(arrayObjs)
	./array

array.o: array.cpp
	$(PP) $(CXXFLAGS) -c array.cpp	


# array2 Example - When the length is not known
# Command: make array
array2Objs :=  array2.o

array2: array2.o
	$(PP) $(CXXFLAGS) -o array2 $(array2Objs)
	./array2

array2.o: array2.cpp
	$(PP) $(CXXFLAGS) -c array2.cpp	


# procMatrix Example - MxN matrix in arrays
# Command: make procMatrix
procMatrixObjs :=  procMatrix.o

procMatrix: procMatrix.o
	$(PP) $(CXXFLAGS) -o procMatrix $(procMatrixObjs)
	./procMatrix

procMatrix.o: procMatrix.cpp
	$(PP) $(CXXFLAGS) -c procMatrix.cpp



# matrix Example - MxN matrix in arrays
# Command: make matrix
matrixObjs :=  matrix.o

matrix: matrix.o
	$(PP) $(CXXFLAGS) -o matrix $(matrixObjs)
	./matrix

matrix.o: matrix.cpp
	$(PP) $(CXXFLAGS) -c matrix.cpp	


# Pascal's Triangle Example
# Command: make pascal
pascalTestObjs := pascalTest.o pascal.o

pascalTest: $(pascalTestObjs)
	$(PP) $(CXXFLAGS) -o pascalTest $(pascalTestObjs)
	./pascalTest

pascalTest.o: pascalTest.cpp pascal.h
	$(PP) $(CXXFLAGS) -c pascalTest.cpp

pascal.o: pascal.cpp pascal.h
	$(PP) $(CXXFLAGS) -c pascal.cpp	
	
	
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
all: passBy callBy helloCmdLine array array2 procMartix pascal matrix rmq1 rmq2

# Make clean
clean :
	rm -rf *.o passBy callBy helloCmdLine array array2 procMartix matrix pascal rmq1 rmq2
