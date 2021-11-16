# Author: Matthew Morrison
# E-mail: matt.morrison@nd.edu
#
# This is the Makefile for the CSE 20312 Optional Lecture 05

# G++ is for the GCC compiler for C++
PP := g++

# CFLAGS are the compiler flages for when we compile C code in this course 
FLAGS := -O2 -g -Wall -Wextra -Wconversion -Wshadow -Werror 
CFLAGS := -std=c11 $(FLAGS)
CXXFLAGS := -m64 -std=c++11 -Weffc++ $(FLAGS) 


# Command: make Courses
CoursesObjs :=  Courses.o

Courses: $(CoursesObjs)
	$(PP) $(CXXFLAGS) -o Courses $(CoursesObjs)
	./Courses

Courses.o: Courses.cpp
	$(PP) $(CXXFLAGS) -c Courses.cpp -o $@



# Command: make LongConSeq
LongConSeqObjs :=  LongConSeq.o

LongConSeq: $(LongConSeqObjs)
	$(PP) $(CXXFLAGS) -o LongConSeq $(LongConSeqObjs)
	./LongConSeq

LongConSeq.o: LongConSeq.cpp
	$(PP) $(CXXFLAGS) -c LongConSeq.cpp -o $@



# Make all
all: Courses LongConSeq

# Make clean
clean :
	rm -rf *.o Courses LongConSeq
	
	
	
# Make initialize
initialize :
	mkdir $(OBJ) $(EXE)
	
	

