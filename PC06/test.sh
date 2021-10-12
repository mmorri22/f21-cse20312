#!/bin/sh
# Author: Matthew Morrison
# Email : matt.morrison@nd.edu
# Fall 2021 - Data Structures - Programming Challenge 06 - Grading Script
#
# This script will help TAs evaluate the course PQC programming standards

# Variables for the script
SCRIPT_OUT="grade.out"
REDIRECT="redirect.out"

# Point Breakdown Variables
STUDENT_GRADE=0
TOTAL=700
CHECK_O_PTS=15
CHECK_EXE_PTS=15
CHECK_CLEAN=15
JK_TEST_PQC_TEST=50
BDC_TEST_PQC_TEST=50
JK_TEST_1=20
JK_TEST_2=20
JK_TEST_3=46
JK_TEST_4=47
JK_TEST_5=47
JK_TEST_6=47
BDC_TEST_1=20
BDC_TEST_2=20
BDC_TEST_3=47
BDC_TEST_4=47
BDC_TEST_5=47
BDC_TEST_6=47


# Delete the script.out so student can test multiple times
# and we can still use >> to append while running a test
if test -f $SCRIPT_OUT; then
    rm $SCRIPT_OUT
fi

# Delete redirect so we start fresh
# Redirect is a temporary file that will contain intermediate outputs 
# These outputs will be used to evaluate the program 
if test -f $REDIRECT; then
    rm $REDIRECT
fi

# Write initial messages to the output file
INTRO_MESSAGE="Grading script for Programming Challenge 06"
NAME_MESSAGE="Type in the student's name (or just press Enter):"
ID_MESSAGE="Type in the student's Notre Dame netID name (or just press Enter):"

echo "-----------------------------" >> $SCRIPT_OUT
echo $INTRO_MESSAGE >> $SCRIPT_OUT
echo "" >> $SCRIPT_OUT

# Get the student's name and ND netID
echo $NAME_MESSAGE
read STUDENT_NAME
echo $ID_MESSAGE
read STUDENT_ID

# Print the name and ID to the script.out
echo "Student's Name: $STUDENT_NAME" >> $SCRIPT_OUT
echo "Student's ID  : $STUDENT_ID" >> $SCRIPT_OUT
echo "" >> $SCRIPT_OUT 
echo "These tests evaluate if you met the Production Quality Compilation Standards."  >> $SCRIPT_OUT
echo "To get the best results, run 'make clean' before running this script next time."  >> $SCRIPT_OUT
echo "If you are a student, don't forget to run 'make clean' before you push!"  >> $SCRIPT_OUT


#######################
# Check if there are no .o or executable files 
#######################
echo "" >> $SCRIPT_OUT
echo "-----------------------------" >> $SCRIPT_OUT
echo "Testing for clean pushing to GitHub" >> $SCRIPT_OUT

# Variables 
LIST_OUTPUTS="ls *"


# Test for object files 
CHECK_O_TEST="test -f objects/*.o"

# Test for the executable 
CHECK_EXE="test -f exe/JK_TEST"    

# Next, we check for the object files  
if test -f "objects/JKFF.o" || test -f "objects/BDC.o"; then
    echo "One or more object file exist." >> $SCRIPT_OUT
	echo "Executables must be cleaned prior to GitHub push." >> $SCRIPT_OUT
	echo "Automatic 50 point deduction, per project description" >> $SCRIPT_OUT
	echo "0 / $CHECK_O_PTS" >> $SCRIPT_OUT
	echo "Here are the files currently in the project folder." >> $SCRIPT_OUT
	CHECK_O_TEST_RESULT=$( $LIST_OUTPUTS ) 
	echo "$CHECK_O_TEST_RESULT" >> $SCRIPT_OUT

else
	echo "Student successfully pushed to GitHub with no object files" >> $SCRIPT_OUT
	((STUDENT_GRADE += $CHECK_O_PTS))
	echo "$CHECK_O_PTS / $CHECK_O_PTS" >> $SCRIPT_OUT
fi


# Next, we check for the executable 
if test -f "exe/JK_TEST.o" || test -f "exe/BDC_Test"; then
    echo "Executable Exists." >> $SCRIPT_OUT
	echo "Executables must be cleaned prior to GitHub push." >> $SCRIPT_OUT
	echo "Automatic 50 point deduction, per project description" >> $SCRIPT_OUT
	echo "0 / $CHECK_EXE_PTS" >> $SCRIPT_OUT
	echo "Here are the files currently in the project folder." >> $SCRIPT_OUT
	CHECK_PC06_TEST_RESULT=$( $LIST_OUTPUTS ) >> $SCRIPT_OUT
	echo "$CHECK_PC06_TEST_RESULT" >> $SCRIPT_OUT

else
	echo "Student successfully pushed to GitHub with no executables" >> $SCRIPT_OUT
	((STUDENT_GRADE += $CHECK_EXE_PTS))
	echo "$CHECK_EXE_PTS / $CHECK_EXE_PTS" >> $SCRIPT_OUT
fi

# Make initialize 
make initialize

#######################
# Test the make clean command 
#######################
echo "" >> $SCRIPT_OUT
echo "-----------------------------" >> $SCRIPT_OUT
echo "Testing make clean" >> $SCRIPT_OUT

MAKE_CLEAN_TEST="make clean"

MAKE_CLEAN_TEST_RESULT=$( $MAKE_CLEAN_TEST )

# Send command to redirect 
echo $MAKE_CLEAN_TEST_RESULT >> $REDIRECT

# Will pass if they ran rm
if grep -e "Nothing to be done" $REDIRECT 

then
	
	echo "$MAKE_CLEAN_TEST did not pass" >> $SCRIPT_OUT
	echo "0 / $CHECK_CLEAN" >> $SCRIPT_OUT

else

	echo "Student successfully implement $MAKE_CLEAN_TEST" >> $SCRIPT_OUT
	echo "$CHECK_CLEAN / $CHECK_CLEAN" >> $SCRIPT_OUT
	echo "" >> $SCRIPT_OUT
	((STUDENT_GRADE += $CHECK_CLEAN))

fi


#######################
# Test the make JK_TEST command 
#######################

echo "" >> $SCRIPT_OUT
echo "-----------------------------" >> $SCRIPT_OUT
echo "Testing make JK_Test" >> $SCRIPT_OUT

make clean >> $SCRIPT_OUT

# make decode comparison variables
MAKE_CLEAN_FORCE="rm -rf objects/* exe/*"
MAKE_JK_TEST_TEST="make JK_Test"
MAKE_GCC="g++"
MAKE_WALL="-Wall"
MAKE_WEXTRA="-Wextra"
MAKE_WCONVERSION="-Wconversion"
MAKE_WERROR="-Werror"
MAKE_STD_C11="-std=c++11"
MAKE_JK_TEST_CLEAN_FORCE=$( $MAKE_CLEAN_FORCE )
MAKE_JK_TEST_TEST_RESULT=$( $MAKE_JK_TEST_TEST )

# Delete redirect and send make result to redirect 
echo $MAKE_JK_TEST_CLEAN_FORCE >> $REDIRECT
echo $MAKE_JK_TEST_TEST_RESULT >> $REDIRECT

# Send results to the script
echo "$MAKE_JK_TEST_TEST output  : " >> $SCRIPT_OUT
echo $MAKE_JK_TEST_TEST_RESULT >> $SCRIPT_OUT
echo "" >> $SCRIPT_OUT
# Add points to overall score or mark as 0 if not for make lucky

# Will pass if their compilation output contains gcc -Wall -Wextra -Wconversion -Werror and -std=c11
if grep -e "$MAKE_GCC" $REDIRECT && grep -e "$MAKE_WEXTRA" $REDIRECT && grep -e "$MAKE_WCONVERSION" $REDIRECT && grep -e "$MAKE_WERROR" $REDIRECT && grep -e "$MAKE_STD_C11" $REDIRECT

then 
	echo "$MAKE_JK_TEST_TEST test passed" >> $SCRIPT_OUT
	echo "Student made a good faith attempt to compile with these flags:" >> $SCRIPT_OUT
	echo "$MAKE_GCC $MAKE_WEXTRA $MAKE_WCONVERSION $MAKE_WERROR $MAKE_STD_C11" >> $SCRIPT_OUT
	echo "Successful compilation is not required to earn these points" >> $SCRIPT_OUT
	echo "$JK_TEST_PQC_TEST / $JK_TEST_PQC_TEST" >> $SCRIPT_OUT
	echo "" >> $SCRIPT_OUT
	((STUDENT_GRADE += $JK_TEST_PQC_TEST))
	
else
	echo "$MAKE_JK_TEST_TEST test failed" >> $SCRIPT_OUT
	echo "0 / $JK_TEST_PQC_TEST" >> $SCRIPT_OUT
	echo "To the grading TA - Manually check if the make JK_TEST does not contain these flags." >> $SCRIPT_OUT
	echo "If it actually works, reward them back the 100 points and delete theese comment." >> $SCRIPT_OUT
	echo "If not, then they violated the PQC rules, and deduct another 300 points." >> $SCRIPT_OUT
	
fi



#######################
# Check if the code successfull compiled 
#######################

# Now the executable SHOULD exist! 
echo "-----------------------------" >> $SCRIPT_OUT
if grep -e "all warnings being treated as errors" $REDIRECT; then

    echo "JK_TEST did not successfully compile." >> $SCRIPT_OUT
	echo "Executables must be cleaned prior to GitHub push." >> $SCRIPT_OUT
	echo "Automatic 50 point deduction, per project description" >> $SCRIPT_OUT
	echo "0 / $JK_TEST_PQC_TEST" >> $SCRIPT_OUT
	echo "Here are the files currently in the project folder." >> $SCRIPT_OUT
	CHECK_O_TEST_RESULT=$( $LIST_OUTPUTS )

else

	echo "JK_TEST Successfully Compiled!" >> $SCRIPT_OUT
	((STUDENT_GRADE += $JK_TEST_PQC_TEST))
	echo "$JK_TEST_PQC_TEST / $JK_TEST_PQC_TEST" >> $SCRIPT_OUT
	
fi

echo "" >> $SCRIPT_OUT

# Delete temporary compilation results
if test -f $REDIRECT; then
    rm $REDIRECT
fi


############################################################
# Running ./exe/JK_Test tests
############################################################

# lucky tests 
JK_TEST_1_TEST="./exe/JK_Test"
JK_TEST_1_EXPECTED="Incorrect number of inputs"

JK_TEST_2_TEST="./exe/JK_Test badfile.txt"
JK_TEST_2_EXPECTED="badfile.txt does not exist"

JK_TEST_3_TEST="./exe/JK_Test JK_test_1.txt"
JK_TEST_3_EXPECTED="0 1
0 1
1 0
0 1
1 0
0 1
1 0
0 1"

JK_TEST_4_TEST="./exe/JK_Test JK_test_2.txt"
JK_TEST_4_EXPECTED="0 1
0 1
0 1
0 1
0 1
0 1
0 1
0 1"

JK_TEST_5_TEST="./exe/JK_Test JK_test_3.txt"
JK_TEST_5_EXPECTED="0 1
0 1
0 1
1 0
1 0
1 0
1 0
0 1
0 1
0 1
0 1"


JK_TEST_6_TEST="./exe/JK_Test JK_test_4.txt"
JK_TEST_6_EXPECTED="0 1
1 0
1 0
1 0
0 1
1 0
1 0
1 0
0 1
0 1
0 1
0 1
1 0
0 1"

echo "" >> $SCRIPT_OUT
echo "-----------------------------" >> $SCRIPT_OUT
echo "Testing JK_Test program" >> $SCRIPT_OUT
echo "" >> $SCRIPT_OUT
echo "-----------------------------" >> $SCRIPT_OUT


#######################
# JK_TEST_1 Test
#######################

# Need to re-compile on first test since $( $MAKE_JK_TEST ) automatically deletes executable
$MAKE_JK_TEST > $REDIRECT
JK_TEST_1_RESULT=$( $JK_TEST_1_TEST )

echo "Expected '$JK_TEST_1_TEST' output: $JK_TEST_1_EXPECTED" >> $SCRIPT_OUT
echo "  Actual '$JK_TEST_1_TEST' output: $JK_TEST_1_RESULT" >> $SCRIPT_OUT
echo "" >> $SCRIPT_OUT


if [ "$JK_TEST_1_EXPECTED" = "$JK_TEST_1_RESULT" ]; 

then 
	echo "$JK_TEST_1_TEST test passed" >> $SCRIPT_OUT
	echo "$JK_TEST_1 / $JK_TEST_1" >> $SCRIPT_OUT
	((STUDENT_GRADE += $JK_TEST_1))
	
else
	echo "JK_TEST_1_TEST test failed" >> $SCRIPT_OUT
	echo "0 / $JK_TEST_1" >> $SCRIPT_OUT
	
fi

#######################
# JK_TEST_2 Test
#######################

echo "" >> $SCRIPT_OUT
echo "-----------------------------" >> $SCRIPT_OUT

JK_TEST_2_RESULT=$( $JK_TEST_2_TEST )

echo "Expected '$JK_TEST_2_TEST' output: $JK_TEST_2_EXPECTED" >> $SCRIPT_OUT
echo "  Actual '$JK_TEST_2_TEST' output: $JK_TEST_2_RESULT" >> $SCRIPT_OUT
echo "" >> $SCRIPT_OUT


if [ "$JK_TEST_2_EXPECTED" = "$JK_TEST_2_RESULT" ]; 

then 
	echo "$JK_TEST_2_TEST test passed" >> $SCRIPT_OUT
	echo "$JK_TEST_2 / $JK_TEST_2" >> $SCRIPT_OUT
	((STUDENT_GRADE += $JK_TEST_2))
	
else
	echo "JK_TEST_2_TEST test failed" >> $SCRIPT_OUT
	echo "0 / $JK_TEST_2" >> $SCRIPT_OUT
	
fi


#######################
# JK_TEST_3 Test
#######################

echo "" >> $SCRIPT_OUT
echo "-----------------------------" >> $SCRIPT_OUT

JK_TEST_3_RESULT=$( $JK_TEST_3_TEST )

echo "Expected '$JK_TEST_3_TEST' output: $JK_TEST_3_EXPECTED" >> $SCRIPT_OUT
echo "  Actual '$JK_TEST_3_TEST' output: $JK_TEST_3_RESULT" >> $SCRIPT_OUT
echo "" >> $SCRIPT_OUT


if [ "$JK_TEST_3_EXPECTED" = "$JK_TEST_3_RESULT" ]; 

then 
	echo "$JK_TEST_3_TEST test passed" >> $SCRIPT_OUT
	echo "$JK_TEST_3 / $JK_TEST_3" >> $SCRIPT_OUT
	((STUDENT_GRADE += $JK_TEST_3))
	
else
	echo "JK_TEST_3_TEST test failed" >> $SCRIPT_OUT
	echo "0 / $JK_TEST_3" >> $SCRIPT_OUT
	
fi


#######################
# JK_TEST_4 Test
#######################

echo "" >> $SCRIPT_OUT
echo "-----------------------------" >> $SCRIPT_OUT

JK_TEST_4_RESULT=$( $JK_TEST_4_TEST )

echo "Expected '$JK_TEST_4_TEST' output: $JK_TEST_4_EXPECTED" >> $SCRIPT_OUT
echo "  Actual '$JK_TEST_4_TEST' output: $JK_TEST_4_RESULT" >> $SCRIPT_OUT
echo "" >> $SCRIPT_OUT


if [ "$JK_TEST_4_EXPECTED" = "$JK_TEST_4_RESULT" ]; 

then 
	echo "$JK_TEST_4_TEST test passed" >> $SCRIPT_OUT
	echo "$JK_TEST_4 / $JK_TEST_4" >> $SCRIPT_OUT
	((STUDENT_GRADE += $JK_TEST_4))
	
else
	echo "JK_TEST_4_TEST test failed" >> $SCRIPT_OUT
	echo "0 / $JK_TEST_4" >> $SCRIPT_OUT
	
fi


#######################
# JK_TEST_5 Test
#######################

echo "" >> $SCRIPT_OUT
echo "-----------------------------" >> $SCRIPT_OUT

JK_TEST_5_RESULT=$( $JK_TEST_5_TEST )

echo "Expected '$JK_TEST_5_TEST' output: $JK_TEST_5_EXPECTED" >> $SCRIPT_OUT
echo "  Actual '$JK_TEST_5_TEST' output: $JK_TEST_5_RESULT" >> $SCRIPT_OUT
echo "" >> $SCRIPT_OUT


if [ "$JK_TEST_5_EXPECTED" = "$JK_TEST_5_RESULT" ]; 

then 
	echo "$JK_TEST_5_TEST test passed" >> $SCRIPT_OUT
	echo "$JK_TEST_5 / $JK_TEST_5" >> $SCRIPT_OUT
	((STUDENT_GRADE += $JK_TEST_5))
	
else
	echo "JK_TEST_5_TEST test failed" >> $SCRIPT_OUT
	echo "0 / $JK_TEST_5" >> $SCRIPT_OUT
	
fi


#######################
# JK_TEST_6 Test
#######################

echo "" >> $SCRIPT_OUT
echo "-----------------------------" >> $SCRIPT_OUT

JK_TEST_6_RESULT=$( $JK_TEST_6_TEST )

echo "Expected '$JK_TEST_6_TEST' output: $JK_TEST_6_EXPECTED" >> $SCRIPT_OUT
echo "  Actual '$JK_TEST_6_TEST' output: $JK_TEST_6_RESULT" >> $SCRIPT_OUT
echo "" >> $SCRIPT_OUT


if [ "$JK_TEST_6_EXPECTED" = "$JK_TEST_6_RESULT" ]; 

then 
	echo "$JK_TEST_6_TEST test passed" >> $SCRIPT_OUT
	echo "$JK_TEST_6  / $JK_TEST_6 " >> $SCRIPT_OUT
	((STUDENT_GRADE += $JK_TEST_6 ))
	
else
	echo "JK_TEST_6_TEST test failed" >> $SCRIPT_OUT
	echo "0 / $JK_TEST_6 " >> $SCRIPT_OUT
	
fi


############################################################
# Running ./BDC_Test tests
############################################################

# BDC_Test tests 
BDC_TEST_1_TEST="./exe/BDC_Test"
BDC_TEST_1_EXPECTED="Incorrect number of inputs"

BDC_TEST_2_TEST="./exe/BDC_Test badfile.txt"
BDC_TEST_2_EXPECTED="badfile.txt does not exist"

BDC_TEST_3_TEST="./exe/BDC_Test BDC_test_1.txt"
BDC_TEST_3_EXPECTED="Initial value in main: 0 0 0 0 0
0 0 0 1 1
0 0 1 0 2
0 0 1 1 3
0 1 0 0 4
0 1 0 1 5
0 1 1 0 6
0 1 1 1 7
1 0 0 0 8
1 0 0 1 9
1 0 1 0 10
1 0 1 1 11
1 1 0 0 12
1 1 0 1 13
1 1 1 0 14
1 1 1 1 15
1 1 1 0 14
1 1 0 1 13
1 1 0 0 12
1 0 1 1 11
1 0 1 0 10
1 0 0 1 9
1 0 0 0 8
0 1 1 1 7
0 1 1 0 6
0 1 0 1 5
0 1 0 0 4
0 0 1 1 3
0 0 1 0 2
0 0 0 1 1
0 0 0 0 0
1 1 1 1 15
1 1 1 0 14
Final value in main: 1 1 1 0 14"

BDC_TEST_4_TEST="./exe/BDC_Test BDC_test_2.txt"
BDC_TEST_4_EXPECTED="Initial value in main: 0 0 0 0 0
0 0 0 0 0
0 0 0 0 0
0 0 0 0 0
0 0 0 0 0
0 0 0 0 0
0 0 0 0 0
0 0 0 0 0
0 0 0 0 0
0 0 0 0 0
0 0 0 0 0
0 0 0 0 0
0 0 0 0 0
0 0 0 0 0
0 0 0 0 0
0 0 0 0 0
0 0 0 0 0
0 0 0 0 0
0 0 0 0 0
0 0 0 0 0
0 0 0 0 0
0 0 0 0 0
0 0 0 0 0
0 0 0 0 0
0 0 0 0 0
0 0 0 0 0
0 0 0 0 0
0 0 0 0 0
Final value in main: 0 0 0 0 0"


BDC_TEST_5_TEST="./exe/BDC_Test BDC_test_3.txt"
BDC_TEST_5_EXPECTED="Initial value in main: 0 0 0 0 0
0 0 0 0 0
0 0 0 1 1
0 0 0 1 1
0 0 1 0 2
0 0 1 0 2
0 0 1 1 3
0 0 1 1 3
0 1 0 0 4
0 1 0 0 4
0 1 0 1 5
0 1 0 1 5
0 1 0 0 4
0 1 0 0 4
0 0 1 1 3
0 0 1 1 3
0 0 1 0 2
0 0 1 0 2
0 0 0 1 1
0 0 0 1 1
0 0 0 0 0
0 0 0 0 0
1 1 1 1 15
1 1 1 1 15
1 1 1 0 14
1 1 1 0 14
1 1 0 1 13
1 1 0 1 13
Final value in main: 1 1 0 1 13"


BDC_TEST_6_TEST="./exe/BDC_Test BDC_test_4.txt"
BDC_TEST_6_EXPECTED="Initial value in main: 0 0 0 0 0
0 0 0 0 0
0 0 0 1 1
0 0 1 0 2
0 0 1 1 3
0 0 1 1 3
0 0 1 1 3
0 0 1 1 3
0 1 0 0 4
0 1 0 1 5
0 1 1 0 6
0 1 1 0 6
0 1 1 0 6
0 1 1 0 6
0 1 0 1 5
0 1 0 0 4
0 0 1 1 3
0 0 1 1 3
0 0 1 1 3
0 0 1 1 3
0 0 1 0 2
0 0 0 1 1
0 0 0 0 0
0 0 0 0 0
0 0 0 0 0
0 0 0 0 0
1 1 1 1 15
1 1 1 0 14
Final value in main: 1 1 1 0 14"


#######################
# Test the make BDC_Test command 
#######################

echo "" >> $SCRIPT_OUT
echo "-----------------------------" >> $SCRIPT_OUT
echo "Testing make BDC_Test" >> $SCRIPT_OUT

make clean >> $SCRIPT_OUT


# make decode comparison variables
MAKE_BDC_Test_TEST="make BDC_Test"
MAKE_BDC_Test_CLEAN_FORCE=$( $MAKE_CLEAN_FORCE )
MAKE_BDC_Test_TEST_RESULT=$( $MAKE_BDC_Test_TEST )

# Delete redirect and send make result to redirect 
echo $MAKE_BDC_Test_CLEAN_FORCE >> $REDIRECT
echo $MAKE_BDC_Test_TEST_RESULT >> $REDIRECT

# Send results to the script
echo "$MAKE_BDC_Test_TEST output  : " >> $SCRIPT_OUT
echo $MAKE_BDC_Test_TEST_RESULT >> $SCRIPT_OUT
echo "" >> $SCRIPT_OUT
# Add points to overall score or mark as 0 if not for make lucky

# Will pass if their compilation output contains gcc -Wall -Wextra -Wconversion -Werror and -std=c11
if grep -e "$MAKE_GCC" $REDIRECT && grep -e "$MAKE_WEXTRA" $REDIRECT && grep -e "$MAKE_WCONVERSION" $REDIRECT && grep -e "$MAKE_WERROR" $REDIRECT && grep -e "$MAKE_STD_C11" $REDIRECT

then 
	echo "$MAKE_BDC_Test_TEST test passed" >> $SCRIPT_OUT
	echo "Student made a good faith attempt to compile with these flags:" >> $SCRIPT_OUT
	echo "$MAKE_GCC $MAKE_WEXTRA $MAKE_WCONVERSION $MAKE_WERROR $MAKE_STD_C11" >> $SCRIPT_OUT
	echo "Successful compilation is not required to earn these points" >> $SCRIPT_OUT
	echo "$BDC_TEST_PQC_TEST / $BDC_TEST_PQC_TEST" >> $SCRIPT_OUT
	echo "" >> $SCRIPT_OUT
	((STUDENT_GRADE += $BDC_TEST_PQC_TEST))
	
else
	echo "$MAKE_BDC_Test_TEST test failed" >> $SCRIPT_OUT
	echo "0 / $BDC_TEST_PQC_TEST" >> $SCRIPT_OUT
	echo "To the grading TA - Manually check if the make BDC_Test does not contain these flags." >> $SCRIPT_OUT
	echo "If it actually works, reward them back the 100 points and delete theese comment." >> $SCRIPT_OUT
	echo "If not, then they violated the PQC rules, and deduct another 300 points." >> $SCRIPT_OUT
	
fi



#######################
# Check if the code successfull compiled 
#######################

# Now the executable SHOULD exist! 
echo "-----------------------------" >> $SCRIPT_OUT
if grep -e "all warnings being treated as errors" $REDIRECT; then

    echo "BDC_Test did not successfully compile." >> $SCRIPT_OUT
	echo "Executables must be cleaned prior to GitHub push." >> $SCRIPT_OUT
	echo "Automatic 50 point deduction, per project description" >> $SCRIPT_OUT
	echo "0 / $BDC_TEST_PQC_TEST" >> $SCRIPT_OUT
	echo "Here are the files currently in the project folder." >> $SCRIPT_OUT
	CHECK_O_TEST_RESULT=$( $LIST_OUTPUTS )

else

	echo "BDC_Test Successfully Compiled!" >> $SCRIPT_OUT
	((STUDENT_GRADE += $BDC_TEST_PQC_TEST))
	echo "$BDC_TEST_PQC_TEST / $BDC_TEST_PQC_TEST" >> $SCRIPT_OUT
	
fi

echo "" >> $SCRIPT_OUT

# Delete temporary compilation results
if test -f $REDIRECT; then
    rm $REDIRECT
fi



#######################
# BDC_TEST_1 Test
#######################

# Need to re-compile on first test since $( $MAKE_BDC_TEST ) automatically deletes executable
$MAKE_BDC_TEST > $REDIRECT

# Run the test and save the output 
BDC_TEST_1_RESULT=$( $BDC_TEST_1_TEST )

echo "Expected '$BDC_TEST_1_TEST' output: $BDC_TEST_1_EXPECTED" >> $SCRIPT_OUT
echo "  Actual '$BDC_TEST_1_TEST' output: $BDC_TEST_1_RESULT" >> $SCRIPT_OUT
echo "" >> $SCRIPT_OUT


if [ "$BDC_TEST_1_EXPECTED" = "$BDC_TEST_1_RESULT" ]; 

then 
	echo "$BDC_TEST_1_TEST test passed" >> $SCRIPT_OUT
	echo "$BDC_TEST_1 / $BDC_TEST_1" >> $SCRIPT_OUT
	((STUDENT_GRADE += $BDC_TEST_1))
	
else
	echo "BDC_TEST_1_TEST test failed" >> $SCRIPT_OUT
	echo "0 / $BDC_TEST_1" >> $SCRIPT_OUT
	
fi

echo "" >> $SCRIPT_OUT
echo "-----------------------------" >> $SCRIPT_OUT

#######################
# BDC_TEST_2 Test
#######################


BDC_TEST_2_RESULT=$( $BDC_TEST_2_TEST )

echo "Expected '$BDC_TEST_2_TEST' output: $BDC_TEST_2_EXPECTED" >> $SCRIPT_OUT
echo "  Actual '$BDC_TEST_2_TEST' output: $BDC_TEST_2_RESULT" >> $SCRIPT_OUT
echo "" >> $SCRIPT_OUT


if [ "$BDC_TEST_2_EXPECTED" = "$BDC_TEST_2_RESULT" ]; 

then 
	echo "$BDC_TEST_2_TEST test passed" >> $SCRIPT_OUT
	echo "$BDC_TEST_2 / $BDC_TEST_2" >> $SCRIPT_OUT
	((STUDENT_GRADE += $BDC_TEST_2))
	
else
	echo "BDC_TEST_2_TEST test failed" >> $SCRIPT_OUT
	echo "0 / $BDC_TEST_2" >> $SCRIPT_OUT
	echo "Note: Check to see if you are printing an extra ENDL at the end if the outputs appear to match" >> $SCRIPT_OUT
	
fi

echo "" >> $SCRIPT_OUT
echo "-----------------------------" >> $SCRIPT_OUT


#######################
# BDC_TEST_3 Test
#######################

BDC_TEST_3_RESULT=$( $BDC_TEST_3_TEST )

echo "Expected '$BDC_TEST_3_TEST' output: $BDC_TEST_3_EXPECTED" >> $SCRIPT_OUT
echo "  Actual '$BDC_TEST_3_TEST' output: $BDC_TEST_3_RESULT" >> $SCRIPT_OUT
echo "" >> $SCRIPT_OUT


if [ "$BDC_TEST_3_EXPECTED" = "$BDC_TEST_3_RESULT" ]; 

then 
	echo "$BDC_TEST_3_TEST test passed" >> $SCRIPT_OUT
	echo "$BDC_TEST_3 / $BDC_TEST_3" >> $SCRIPT_OUT
	((STUDENT_GRADE += $BDC_TEST_3))
	
else
	echo "BDC_TEST_3_TEST test failed" >> $SCRIPT_OUT
	echo "0 / $BDC_TEST_3" >> $SCRIPT_OUT
	echo "Note: Check to see if you are printing a space at the end if the outputs appear to match" >> $SCRIPT_OUT
	
fi

echo "" >> $SCRIPT_OUT
echo "-----------------------------" >> $SCRIPT_OUT


#######################
# BDC_TEST_4 Test
#######################

BDC_TEST_4_RESULT=$( $BDC_TEST_4_TEST )

echo "Expected '$BDC_TEST_4_TEST' output: $BDC_TEST_4_EXPECTED" >> $SCRIPT_OUT
echo "  Actual '$BDC_TEST_4_TEST' output: $BDC_TEST_4_RESULT" >> $SCRIPT_OUT
echo "" >> $SCRIPT_OUT


if [ "$BDC_TEST_4_EXPECTED" = "$BDC_TEST_4_RESULT" ]; 

then 
	echo "$BDC_TEST_4_TEST test passed" >> $SCRIPT_OUT
	echo "$BDC_TEST_4 / $BDC_TEST_4" >> $SCRIPT_OUT
	((STUDENT_GRADE += $BDC_TEST_4))
	
else
	echo "BDC_TEST_4_TEST test failed" >> $SCRIPT_OUT
	echo "0 / $BDC_TEST_4" >> $SCRIPT_OUT
	echo "Note: Check to see if you are printing a space at the end if the outputs appear to match" >> $SCRIPT_OUT
	
fi

echo "" >> $SCRIPT_OUT
echo "-----------------------------" >> $SCRIPT_OUT


#######################
# BDC_TEST_5 Test
#######################

BDC_TEST_5_RESULT=$( $BDC_TEST_5_TEST )

echo "Expected '$BDC_TEST_5_TEST' output: $BDC_TEST_5_EXPECTED" >> $SCRIPT_OUT
echo "  Actual '$BDC_TEST_5_TEST' output: $BDC_TEST_5_RESULT" >> $SCRIPT_OUT
echo "" >> $SCRIPT_OUT


if [ "$BDC_TEST_5_EXPECTED" = "$BDC_TEST_5_RESULT" ]; 

then 
	echo "$BDC_TEST_5_TEST test passed" >> $SCRIPT_OUT
	echo "$BDC_TEST_5 / $BDC_TEST_5" >> $SCRIPT_OUT
	((STUDENT_GRADE += $BDC_TEST_5))
	
else
	echo "$BDC_TEST_5_TEST test failed" >> $SCRIPT_OUT
	echo "0 / $BDC_TEST_5" >> $SCRIPT_OUT
	echo "Note: Check to see if you are printing a space at the end if the outputs appear to match" >> $SCRIPT_OUT
	
fi

echo "" >> $SCRIPT_OUT
echo "-----------------------------" >> $SCRIPT_OUT


#######################
# BDC_TEST_6 Test
#######################

BDC_TEST_6_RESULT=$( $BDC_TEST_6_TEST )

echo "Expected '$BDC_TEST_6_TEST' output: $BDC_TEST_6_EXPECTED" >> $SCRIPT_OUT
echo "  Actual '$BDC_TEST_6_TEST' output: $BDC_TEST_6_RESULT" >> $SCRIPT_OUT
echo "" >> $SCRIPT_OUT


if [ "$BDC_TEST_6_EXPECTED" = "$BDC_TEST_6_RESULT" ]; 

then 
	echo "$BDC_TEST_6_TEST test passed" >> $SCRIPT_OUT
	echo "$BDC_TEST_6 / $BDC_TEST_6" >> $SCRIPT_OUT
	((STUDENT_GRADE += $BDC_TEST_6))
	
else
	echo "BDC_TEST_6_TEST test failed" >> $SCRIPT_OUT
	echo "0 / $BDC_TEST_6" >> $SCRIPT_OUT
	echo "Note: Check to see if you are printing a space at the end if the outputs appear to match" >> $SCRIPT_OUT
	
fi

echo "" >> $SCRIPT_OUT
echo "-----------------------------" >> $SCRIPT_OUT




# Final Grade to both the screen and the script file.
echo "-----------------------------" >> $SCRIPT_OUT
echo "" >> $SCRIPT_OUT
echo "PC06 Testing Portion Grade for $STUDENT_NAME ($STUDENT_ID): $STUDENT_GRADE / $TOTAL " >> $SCRIPT_OUT
echo "PC06 Testing Portion Grade for $STUDENT_NAME ($STUDENT_ID): $STUDENT_GRADE / $TOTAL "
echo "Run 'vim $SCRIPT_OUT' to see the result of the test script"


# Clean and delete re-directions
make clean > $REDIRECT

rm $REDIRECT
