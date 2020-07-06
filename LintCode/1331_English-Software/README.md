1331. English Software

Xiao Lin is a representative of the English class in the class. He wants to develop a software to handle the grades of classmates.
Xiao LIn ’s software has a magical feature that can reflect the position of your grades in the class through a percentage. "Classmates with grades exceeding…%".
Suppose this percentage is p, and s score is tested, then p can be calculated by the following formula:
p = (number of people whose score does not exceed s-1) / total number of students in the class * 100%
Please design this software

Example
Example 1:

Input: score= [100,98,87], ask=[1,2,3]
Output: [66,33,0] 
Explanation:
The first person scored 100 points, more than 66% of students
Notice
The score array is given to represent the i-th person to take score[i] points
Give the ask array to represent the score of the i-th individual
Each query will output the corresponding score percentage, no need to output a percent sign
The answer is rounded down（To avoid loss of precision, please calculate multiplication first）


