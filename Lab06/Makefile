# Author: Matthew Morrison
# E-mail: matt.morrison@nd.edu
#
# This is the Makefile for the CSE 20312 course - Lab 06

# G++ is for the GCC compiler for C++
PP := g++

# CXXFLAGS are the compiler flages for when we compile C++ code in this course 
FLAGS := -O2 -g -Wall -Wextra -Wconversion -Wshadow -Werror 
CXXFLAGS := -m64 -std=c++11 -Weffc++ $(FLAGS) 


# Command: make Stocks_1
Stocks_1.o: Stocks_1.cpp
	$(PP) $(CXXFLAGS) -c Stocks_1.cpp -o $@
	
Stocks_1_objs := Stocks_1.o

Stocks_1: $(Stocks_1_objs)
	$(PP) $(CXXFLAGS) -o Stocks_1 $(Stocks_1_objs)


# Command: make Stocks
Stocks.o: Stocks.cpp
	$(PP) $(CXXFLAGS) -c Stocks.cpp -o $@
	
Stocks_objs := Stocks.o

Stocks: $(Stocks_objs)
	$(PP) $(CXXFLAGS) -o Stocks $(Stocks_objs)


# Command: make Product
ProductObjs := Product.o

Product: $(ProductObjs)
	$(PP) $(CXXFLAGS) -o Product $(ProductObjs)

Product.o: Product.cpp
	$(PP) $(CXXFLAGS) -c Product.cpp -o $@


# Command: make Product_Lab
Product_LabObjs := Product_Lab.o

Product_Lab: $(Product_LabObjs)
	$(PP) $(CXXFLAGS) -o Product_Lab $(Product_LabObjs)

Product_Lab.o: Product_Lab.cpp
	$(PP) $(CXXFLAGS) -c Product_Lab.cpp -o $@



# Make all
all: Stocks_1 Stocks Product Product_Lab

# Make clean
clean :
	rm -rf *.o Stocks_1 Stocks Product Product_Lab
