These code segments follow the order of Lecture 07 - Part 1 for CSE 24312

Follow the order of the slide set found at https://sites.google.com/a/nd.edu/morrison/courses/cse24312/lecture-notes/

The order of compilation and files to understand the design is as follows:


-------------------------------------------------

Command 1 - make sol_1

Files: classes/sol1.h and programs/sol_1.cpp

Slides: 6-8

Shows the Dynamic Array called with a default constructor, and added elements per the problem statement. sol1.h prints the elements out in their initial order. First step in the “Best Time to Buy and Sell Stock” problem

-------------------------------------------------

Command 2 - make sol_2

Files: classes/sol2.h and programs/sol_2.cpp

Slides: 9-10

sol2.h modifies sol1.h by iterating through the array and prints the smallest value and its location and the end. sol_2.cpp calls that function

-------------------------------------------------

Command 3 - make sol_3

Files: classes/sol3.h and programs/sol_3.cpp

Slides: 11-14

sol3.h modifies sol2.h by iterating find the maximum values after the minimum value in the same pass, reducing the time complexity. sol_3.cpp is the same as sol_2.cpp, except it calls sol3.h.

-------------------------------------------------

Command 4 - make sol

Files: classes/sol.h and programs/sol.cpp

Slides: 15-17

sol.h modifies sol3.h by printing the final results as dictated in the problem. sol.cpp is the same as sol_3.cpp, except it calls sol.h.

-------------------------------------------------

Command 5 - make Product1

Files: programs/Product1.cpp

Slides: 24

Set up the initial array cases that will be used to verify the solution for the “Product of Array Except Self” problem.

-------------------------------------------------

Command 6 - make Product2

Files: programs/Product2.cpp

Slides: 25-27

Modified Product1.cpp by performing the forward iteration of the “Product of Array Except Self” problem in the solveArray function.

-------------------------------------------------

Command 7 - make Product3

Files: programs/Product3.cpp

Slides: 28

Modified Product2.cpp by performing adding modularity to the output by creating the runSolution function

-------------------------------------------------

Command 8 - make Product

Files: programs/Product.cpp

Slides: 29-30

Modified Product3.cpp by the reverse iteration of the “Product of Array Except Self” problem in the solveArray function.

-------------------------------------------------

Command 9 - make maxSub1

Files: programs/maxSub1.cpp

Slides: 32-33

Initial step in a Brute Force approach to the "Maximum Subarray" problem. Simply finds the largest element in the array

-------------------------------------------------

Command 9 - make maxSub2

Files: programs/maxSub2.cpp

Slides: 34-36

Modified maxSub1.cpp by adding an iteration in maxSubArrayBrute to calculate the maximum array in O(n^2) time.

-------------------------------------------------

Command 10 - make maxSub3

Files: programs/maxSub3.cpp

Slides: 39-42

Performs a Dynamic Programming Approach to maxSub. In this program, only the intermediate values are calculated to get the best subarray value at each location. Function maxSubArrayDyn is where the changes occur.

-------------------------------------------------

Command 11 - make maxSub4

Files: programs/maxSub4.cpp

Slides: 43-44

Modified maxSub3.cpp by calculating the global maximum value in maxSubArrayDyn

-------------------------------------------------

Command 12 - make maxSub

Files: programs/maxSub.cpp

Slides: 45-46

Modified maxSub4.cpp by changing the if statements in maxSubArrayDyn to ternary conditionals and removing intermediate print statements.