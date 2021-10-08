#!/bin/sh
# Grading script developed by Matthew Morrison
# Spring 2021 - Data Structures - Lecture 11 - Grading Script

# Script Re-direct 
SCRIPT_OUT=grade.out
REDIRECT=redirect.out 

# Point Breakdown Variables
STUDENT_GRADE=0
PROB1=35
PROB2=40
PROB3=35
TOTAL=110

# Files
PROB1_FILE=Prob1.txt
PROB2_FILE=Prob2.txt
PROB3_FILE=Prob3.txt

# Delete grade.out if they ran it before
rm $SCRIPT_OUT

if test -f "$PROB1_FILE";

then 
	echo "$PROB1_FILE completed" >> $SCRIPT_OUT
	echo "$PROB1 / $PROB1" >> $SCRIPT_OUT
	((STUDENT_GRADE += $PROB1))
	
else
	echo "$PROB1_FILE not completed" >> $SCRIPT_OUT
	echo "0 / $PROB1" >> $SCRIPT_OUT

fi


if test -f "$PROB2_FILE";

then 
	echo "$PROB2_FILE completed" >> $SCRIPT_OUT
	echo "$PROB2 / $PROB2" >> $SCRIPT_OUT
	((STUDENT_GRADE += $PROB2))
	
else
	echo "$PROB2_FILE not completed" >> $SCRIPT_OUT
	echo "0 / $PROB2" >> $SCRIPT_OUT

fi

if test -f "$PROB3_FILE";

then 
	echo "$PROB3_FILE completed" >> $SCRIPT_OUT
	echo "$PROB3 / $PROB3" >> $SCRIPT_OUT
	((STUDENT_GRADE += $PROB3))
	
else
	echo "$PROB3_FILE not completed" >> $SCRIPT_OUT
	echo "0 / $PROB3" >> $SCRIPT_OUT

fi


# Final Grade to both the screen and the script file.
echo "-----------------------------" >> $SCRIPT_OUT
echo "" >> $SCRIPT_OUT
echo "Lec11 Grade: $STUDENT_GRADE / $TOTAL "
echo "Lec11 Grade: $STUDENT_GRADE / $TOTAL " >> $SCRIPT_OUT
echo "Run 'vim $SCRIPT_OUT' to see the result of the test script"


if [ $STUDENT_GRADE = $TOTAL ]

then
	echo "Full Credit Submission."
	
# Remove the object and executable files
	
	make clean > $REDIRECT
	rm $REDIRECT

# Otherwise, encourage the students to retry and resubmit

else
	echo "Review the code and try again. You can do it!"
	
fi
