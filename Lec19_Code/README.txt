These code segments follow the order of Lecture 04 - Part 1 for CSE 24312

Follow the order of the slide set found at https://sites.google.com/a/nd.edu/morrison/courses/cse24312/lecture-notes/

The order of compilation and files to understand the design is as follows:


-------------------------------------------------
Command 1 - make class1

Files: point1.h point1.cpp class1.cpp

Slides: 2-12

point1.h and point1.cpp show how to build a basic class, with a default constructor and an overloaded constructor. point1.g and point1.cpp have get/set methods, and const methods are introduced. 

class1.cpp calls both constructors and prints the values to the output using the get methods. Then, the set methods are used to update the point using the default constructor, and it is printed again.

-------------------------------------------------
Command 2 - make passBy

Files: passBy.cpp

Slides: 13-15

This file passes a char array by reference, as well as ints by value and reference to show the difference on how they work on the stack and the heap. This is shown to set up how pass and call by reference are used in C++ to construct classes, specifically with overloaded operators.

-------------------------------------------------
Command 3 - make callBy

Files: callBy.cpp

Slides: 16-20

callBy.cpp shows the how "Call By Reference" is structured, as well as how it is used to abstract pointer complexity from the user in C++

-------------------------------------------------
Command 3 - make class2

Files: point.h, point.cpp, and class2.cpp

Slides: 21-24

Builds off knowledge from "Call by Reference" to build an overloaded friend operator to print results of point class. point.h and point.cpp build off point1.h/.cpp by including the overloaded operator, which uses const and call by reference.

-------------------------------------------------
Command 4 - make class3

Files: point.h, point.cpp, line1.h, line1.h and class3.cpp

Slides: 25-27

The line class in line1.h and line1.cpp shows Aggregation by calling class point.h in line.h. The design of line1 is similar to point with get/set and overloaded functions.

-------------------------------------------------
Command 5 - make class4

Files: point.h, point.cpp, line2.h, line2.h and class3.cpp

Slides: 28-29

line2.h/.cpp have a modification from line1.h/.cpp where another constructor is added with COORDINATES instead of points.

-------------------------------------------------
Command 6 - make classIntro

Files: point.h, point.cpp, line.h, line.h and classIntro.cpp

Complete wrap-up of all concepts

