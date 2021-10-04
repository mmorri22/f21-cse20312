# Author: Matthew Morrison
# E-mail: matt.morrison@nd.edu
#
# This is the Makefile for Lecture 04 - Part 1

# G++ is for the GCC compiler for C++
PP := g++

# CFLAGS are the compiler flages for when we compile C code in this course
FLAGS := -O2 -g -Wall -Wextra -Wconversion -Wshadow -pedantic -Werror -lm
CXXFLAGS := -m64 -std=c++11 -Weffc++ $(FLAGS)


# point compilation
point.o: point.cpp
	$(PP) $(CXXFLAGS) -c point.cpp


# line compilation
line.o: line.cpp
	$(PP) $(CXXFLAGS) -c line.cpp	

##### MID POINT COMPILATION
# In-Class point only
in_class_point.o: in_class.cpp
	$(PP) $(CXXFLAGS) -c in_class.cpp

# in_class_point Example 
in_class_point_objs := in_class_point.o point.o

in_class_point: $(in_class_point_objs)
	$(PP) $(CXXFLAGS) -o in_class_point $(in_class_point_objs)
	
	

#### FINAL COMPILATION
# In-Class both point and line
in_class.o: in_class.cpp
	$(PP) $(CXXFLAGS) -c in_class.cpp


# in_class Example 
in_class_objs := in_class.o line.o point.o

in_class: $(in_class_objs)
	$(PP) $(CXXFLAGS) -o in_class $(in_class_objs)






# Make all
all: in_class_point in_class

# Make clean
clean :
	rm -rf *.o in_class_point in_class
