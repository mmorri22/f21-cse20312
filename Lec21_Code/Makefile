# Author: Matthew Morrison
# E-mail: matt.morrison@nd.edu
#
# This is the Makefile for the CSE 20312 course Lecture 20

# G++ is for the GCC compiler for C++
PP := g++


# CXXFLAGS are the compiler flages for when we compile C++ code in this course 
FLAGS := -O2 -g -Wall -Wextra -Wconversion -Wshadow -Werror 
CXXFLAGS := -m64 -std=c++11 -Weffc++ $(FLAGS) 


INC := include
SRC := src
OBJ := obj
EXE := exe


# Command: make sll_test
$(OBJ)/sll_test.o: $(SRC)/sll_test.cpp
	$(PP) $(CXXFLAGS) -c $(SRC)/sll_test.cpp -o $@

sll_test_objs := $(OBJ)/sll_test.o

sll_test: $(sll_test_objs)
	$(PP) $(CXXFLAGS) -o $(EXE)/sll_test $(sll_test_objs)



# Command: make stack_test
$(OBJ)/stack_test.o: $(SRC)/stack_test.cpp
	$(PP) $(CXXFLAGS) -c $(SRC)/stack_test.cpp -o $@

stack_test_objs := $(OBJ)/stack_test.o

stack_test: $(stack_test_objs)
	$(PP) $(CXXFLAGS) -o $(EXE)/stack_test $(stack_test_objs)


# Command: make max_stack_sol
$(OBJ)/max_stack_sol.o: $(SRC)/max_stack_sol.cpp
	$(PP) $(CXXFLAGS) -c $(SRC)/max_stack_sol.cpp -o $@

max_stack_sol_objs := $(OBJ)/max_stack_sol.o

max_stack_sol: $(max_stack_sol_objs)
	$(PP) $(CXXFLAGS) -o $(EXE)/max_stack_sol $(max_stack_sol_objs)
	

# Command: make dll_test
$(OBJ)/dll_test.o: $(SRC)/dll_test.cpp
	$(PP) $(CXXFLAGS) -c $(SRC)/dll_test.cpp -o $@

dll_test_objs := $(OBJ)/dll_test.o

dll_test: $(dll_test_objs)
	$(PP) $(CXXFLAGS) -o $(EXE)/dll_test $(dll_test_objs)



# Command: make queue_test
$(OBJ)/queue_test.o: $(SRC)/queue_test.cpp
	$(PP) $(CXXFLAGS) -c $(SRC)/queue_test.cpp -o $@

queue_test_objs := $(OBJ)/queue_test.o

queue_test: $(queue_test_objs)
	$(PP) $(CXXFLAGS) -o $(EXE)/queue_test $(queue_test_objs)


# Command: make deque_test
$(OBJ)/deque_test.o: $(SRC)/deque_test.cpp
	$(PP) $(CXXFLAGS) -c $(SRC)/deque_test.cpp -o $@

deque_test_objs := $(OBJ)/deque_test.o

deque_test: $(deque_test_objs)
	$(PP) $(CXXFLAGS) -o $(EXE)/deque_test $(deque_test_objs)


# Command: make pq_test
$(OBJ)/pq_test.o: $(SRC)/pq_test.cpp
	$(PP) $(CXXFLAGS) -c $(SRC)/pq_test.cpp -o $@

pq_test_objs := $(OBJ)/pq_test.o

pq_test: $(pq_test_objs)
	$(PP) $(CXXFLAGS) -o $(EXE)/pq_test $(pq_test_objs)



# Command: make ComplexTest
# Shows allocating templated generic types on the heap
# using imperative and procedural programming

ComplexTestObjs := $(OBJ)/ComplexTest.o $(OBJ)/Complex.o

ComplexTest: $(ComplexTestObjs)
	$(PP) $(CXXFLAGS) -o $(EXE)/ComplexTest $(ComplexTestObjs)
	$(EXE)/./ComplexTest

$(OBJ)/ComplexTest.o: $(SRC)/ComplexTest.cpp
	$(PP) $(CXXFLAGS) -c $(SRC)/ComplexTest.cpp -o $@

$(OBJ)/Complex.o: $(SRC)/Complex.cpp
	$(PP) $(CXXFLAGS) -c $(SRC)/Complex.cpp -o $@


	


# make initialize
# Will be called by grader to initialize your objects and executables folders
initialize: 
	mkdir objects executables


# Make all
all: tempDest vector quadPair quadPair2 iterator

# Make clean
clean :
	rm -rf *.o $(OBJ)/* $(EXE)/*
