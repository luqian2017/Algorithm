417. Valid Number
中文English
Validate if a given string is numeric.

Example
Example 1:

Input: "0"
Output: true
Explanation: "0" can be converted to 0
Example 2:

Input: "0.1"
Output: true
Explanation: "0.1" can be converted to 0.1
Example 3:

Input: "abc"
Output: false
Example 4:

Input: "1 a"
Output: false
Example 5:

Input: "2e10"
Output: true
Explanation: "2e10" represents 20,000,000,000

Solution:
1) First getting rid of the leading and last empty chars. Get l and r.
2) go through l..r, if digit, continue; otherwise, write down the location of dot and e.