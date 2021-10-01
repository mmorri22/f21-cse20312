# Author: Matthew Morrison
# E-mail: matt.morrison@nd.edu
#
# This is the Makefile for Lecture 17 - CSE 20312

# G++ is for the GCC compiler for C++
PP := g++

# CFLAGS are the compiler flages for when we compile C code in this course
FLAGS := -O2 -g -Wall -Wextra -Wconversion -Wshadow -Werror -lm
CXXFLAGS := -m64 -std=c++11 -Weffc++ $(FLAGS)


# C++ cin Example
# Command: make cin
cin.o: cin.cpp
	$(PP) $(CXXFLAGS) -c cin.cpp

cin_objs :=  cin.o

cin: $(cin_objs)
	$(PP) $(CXXFLAGS) -o cin $(cin_objs)
	
	
# C++ cin_str Example
# Command: make cin_str
cin_str.o: cin_str.cpp
	$(PP) $(CXXFLAGS) -c cin_str.cpp

cin_str_objs :=  cin_str.o

cin_str_str: $(cin_str_str_objs)
	$(PP) $(CXXFLAGS) -o cin_str_str $(cin_str_str_objs)
	
	
# C++ namespace Example
# Command: make namespace
namespace.o: namespace.cpp
	$(PP) $(CXXFLAGS) -c namespace.cpp
	
namespace_objs :=  namespace.o

namespace: $(namespace_objs)
	$(PP) $(CXXFLAGS) -o namespace $(namespace_objs)


# C++ namespace_fixed Example
# Command: make namespace_fixed
namespace_fixed.o: namespace_fixed.cpp
	$(PP) $(CXXFLAGS) -c namespace_fixed.cpp

namespace_fixed_objs :=  namespace_fixed.o

namespace_fixed: $(namespace_fixed_objs)
	$(PP) $(CXXFLAGS) -o namespace_fixed $(namespace_fixed_objs)


# C++ namespace_direct Example
# Command: make namespace_direct
namespace_direct.o: namespace_direct.cpp
	$(PP) $(CXXFLAGS) -c namespace_direct.cpp

namespace_direct_objs :=  namespace_direct.o

namespace_direct: $(namespace_direct_objs)
	$(PP) $(CXXFLAGS) -o namespace_direct $(namespace_direct_objs)


# C++ const Example
# Command: make const
const.o: const.cpp
	$(PP) $(CXXFLAGS) -c const.cpp

const_objs :=  const.o

const: $(const_objs)
	$(PP) $(CXXFLAGS) -o const $(const_objs)


# C++ func_over Example
# Command: make func_over
func_over.o: func_over.cpp
	$(PP) $(CXXFLAGS) -c func_over.cpp

func_over_objs :=  func_over.o

func_over: $(func_over_objs)
	$(PP) $(CXXFLAGS) -o func_over $(func_over_objs)


# C++ ambig Example
# Command: make ambig
ambig.o: ambig.cpp
	$(PP) $(CXXFLAGS) -c ambig.cpp

ambig_objs :=  ambig.o

ambig: $(ambig_objs)
	$(PP) $(CXXFLAGS) -o ambig $(ambig_objs)


# C++ template Example
# Command: make template
template.o: template.cpp
	$(PP) $(CXXFLAGS) -c template.cpp

template_objs :=  template.o

template: $(template_objs)
	$(PP) $(CXXFLAGS) -o template $(template_objs)


# C++ string_vector Example
# Command: make string_vector
string_vector.o: string_vector.cpp
	$(PP) $(CXXFLAGS) -c string_vector.cpp

string_vector_objs :=  string_vector.o

string_vector: $(string_vector_objs)
	$(PP) $(CXXFLAGS) -o string_vector $(string_vector_objs)	


# C++ vector Example
# Command: make vector
vector.o: vector.cpp
	$(PP) $(CXXFLAGS) -c vector.cpp

vector_objs :=  vector.o

vector: $(vector_objs)
	$(PP) $(CXXFLAGS) -o vector $(vector_objs)
	

# Make all
all: cin cin_str namespace_fixed namespace_direct const func_over template string_vector vector

# Make clean
clean :
	rm -rf *.o cin cin_str namespace_fixed namespace_direct const func_over template string_vector vector
