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


# In-Class point only
in_class_point.o: in_class.cpp
	$(PP) $(CXXFLAGS) -c in_class.cpp


# In-Class both point and line
in_class.o: in_class.cpp
	$(PP) $(CXXFLAGS) -c in_class.cpp


# in_class Example 
in_class_objs := in_class.o line.o point.o

in_class: $(in_class_objs)
	$(PP) $(CXXFLAGS) -o in_class $(in_class_objs)


# in_class_point Example 
# Command: make point1
in_class_point_objs := in_class_point.o point.o

in_class_point: $(in_class_point_objs)
	$(PP) $(CXXFLAGS) -o in_class_point $(in_class_point_objs)



# passBy Example 
# Command: make passBy
passByObjs := passBy.o

passBy: $(passByObjs)
	$(PP) $(CXXFLAGS) -o passBy $(passByObjs)
	./passBy

passBy.o: passBy.cpp
	$(PP) $(CXXFLAGS) -c passBy.cpp
	


# callBy Example 
# Command: make callBy
callByObjs := callBy.o

callBy: $(callByObjs)
	$(PP) $(CXXFLAGS) -o callBy $(callByObjs)
	./callBy

callBy.o: callBy.cpp
	$(PP) $(CXXFLAGS) -c callBy.cpp


	
# class2 Example 
# Command: make point
class2Objs := class2.o point.o

class2: $(class2Objs)
	$(PP) $(CXXFLAGS) -o class2 $(class2Objs)
	./class2

class2.o: class2.cpp point.h
	$(PP) $(CXXFLAGS) -c class2.cpp



# class3 Example
# Command: make class3 
class3Objs := class3.o line1.o point.o

class3: $(class3Objs)
	$(PP) $(CXXFLAGS) -o class3 $(class3Objs)
	./class3

class3.o: class3.cpp line1.h
	$(PP) $(CXXFLAGS) -c class3.cpp

line1.o: line1.cpp line1.h
	$(PP) $(CXXFLAGS) -c line1.cpp
	
	
	
# class4 Example
# Command: make class4 
class4Objs := class4.o line2.o point.o

class4: $(class4Objs)
	$(PP) $(CXXFLAGS) -o class4 $(class4Objs)
	./class4

class4.o: class4.cpp line2.h
	$(PP) $(CXXFLAGS) -c class4.cpp

line2.o: line2.cpp line2.h
	$(PP) $(CXXFLAGS) -c line2.cpp
	


# classIntro Example
# Command: make classIntro 
classIntroObjs := classIntro.o line.o point.o

classIntro: $(classIntroObjs)
	$(PP) $(CXXFLAGS) -o classIntro $(classIntroObjs)
	./classIntro

classIntro.o: classIntro.cpp line.h
	$(PP) $(CXXFLAGS) -c classIntro.cpp

line.o: line.cpp line.h
	$(PP) $(CXXFLAGS) -c line.cpp

point.o: point.cpp point.h
	$(PP) $(CXXFLAGS) -c point.cpp



# Make all
all: in_class_point in_class

# Make clean
clean :
	rm -rf *.o in_class_point in_class
