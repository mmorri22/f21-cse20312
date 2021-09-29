# Author: Matthew Morrison
# E-mail: matt.morrison@nd.edu
#
# This is the Makefile for Lecture 17 - CSE 20312

# G++ is for the GCC compiler for C++
PP := g++

# CFLAGS are the compiler flages for when we compile C code in this course
FLAGS := -O2 -g -Wall -Wextra -Wconversion -Wshadow -Werror -lm
CXXFLAGS := -m64 -std=c++11 -Weffc++ $(FLAGS)

# C++ Hello, World Example
# Command: make hello
hello.o: hello.cpp
	$(PP) $(CXXFLAGS) -c hello.cpp

hello_objs :=  hello.o

hello: $(hello_objs)
	$(PP) $(CXXFLAGS) -o hello $(hello_objs)
	
	
# C++ output Example
# Command: make output
output.o: output.cpp
	$(PP) $(CXXFLAGS) -c output.cpp

output_objs :=  output.o

output: $(output_objs)
	$(PP) $(CXXFLAGS) -o output $(output_objs)


# C++ call_by Example
# Command: make call_by
call_by.o: call_by.cpp
	$(PP) $(CXXFLAGS) -c call_by.cpp

call_by_objs :=  call_by.o

call_by: $(call_by_objs)
	$(PP) $(CXXFLAGS) -o call_by $(call_by_objs)


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
	

# Make all
all: hello output call_by cin cin_str namespace_fixed

# Make clean
clean : ; rm -rf *.o hello output call_by cin cin_str namespace_fixed
