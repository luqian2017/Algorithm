1145. Associated query

Given an employee table datalist1, store the employee ID and the employee name.

Given an employee hours table datalist2, store the employee ID, month, and hour.

Calculate the monthly working hours and total working hours of each employee from January to march.

Input description:

[[employee ID, employee name],[employee ID, employee name],...]

[[employee ID, month, hour, month, hour, month, hour],[employee ID, month, hour, month, hour, month, hour],...]

Output description:

[[employee name, January hours, February hours, march hours, total hours],[employee name, January hours, February hours, march hours, total hours],...]

Example
Input: 
[["1","zhangwei01"]]
[["1","01","200","02","150","03","196"]]
Output: 
[["zhangwei01","200","150","196","546"]]
Notice
The relevant data are presented in the two tables from small to large according to the employee ID, and the data in the returned table should also be arranged from small to large according to the employee ID.