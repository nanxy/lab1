# lab1
A program that takes in a file from the user and converts it into a vector. The average, median and mode are calculated. 



__________________________________________________________________________________________________
This assignment was locked Apr 23 at 11:59pm.
 Objective:
Review the use of files, practice using vectors and sorting 
Assignment:

Write a program that reads a text file containing a set of test scores, calculates the average, median and mode. The file name must be entered by the user. Use the main function provided and implement all other functions.

getScores:
Ask the user for the file name and use it to open the file containing the scores. If the file opening was unsuccessful, ask the user to enter it again until you succeed or return zero to main.
Read all scores to a vector. You will need to pass the vector by reference to this function.
calcAverage:
Calculate the average by adding all scores and dividing by the number of scores.
calcMedian:
Calculate the median. This function should test whether the file has an even or odd number of scores. If there is an odd number of scores, the median is the score in middle, given that the scores are sorted. If there is an even number of scores, you need to average the two in the middle.

calcMode:
Determines the score that appears more often in the data set.
print:
The scores sorted from least to greatest
The average (rounded to one-decimal place), median(rounded to one-decimal place) and mode
Use a range-based for loop in this function
You will need to sort the scores before calculating the median. Use the sort function to sort the vector. Refer to http://www.cplusplus.com/reference/algorithm/sort/ (Links to an external site.)Links to an external site. to learn how to use sort.

You will be graded on following the specification and on how well-structured your program is. Please, refer to the rubric.

Follow the guidelines provided to document your source code.

Rubric
Lab 1 Rubric (1)
Lab 1 Rubric (1)
Criteria	Ratings	Pts
This criterion is linked to a Learning OutcomeCode is well documented.
Full Marks
5.0 pts
No Marks
0.0 pts
5.0 pts
This criterion is linked to a Learning OutcomeDefines function that reads file name from the standard input, checks if file exists before processing, closes file at the end.
Full Marks
6.0 pts
No Marks
0.0 pts
6.0 pts
This criterion is linked to a Learning OutcomeUses std::sort to sort the vector
Full Marks
6.0 pts
No Marks
0.0 pts
6.0 pts
This criterion is linked to a Learning OutcomeDefines function that correctly calculates average
Full Marks
7.0 pts
No Marks
0.0 pts
7.0 pts
This criterion is linked to a Learning OutcomeDefines function that correctly calculates median
Full Marks
8.0 pts
No Marks
0.0 pts
8.0 pts
This criterion is linked to a Learning OutcomeDefines function that correctly determines mode
Full Marks
8.0 pts
No Marks
0.0 pts
8.0 pts
This criterion is linked to a Learning OutcomeProgram is well structured, does not use global variables and is well indented
Full Marks
5.0 pts
No Marks
0.0 pts
5.0 pts
This criterion is linked to a Learning OutcomeOutput is well formatted and has correct data
Full Marks
5.0 pts
No Marks
0.0 pts
5.0 pts
Total Points: 50.0
