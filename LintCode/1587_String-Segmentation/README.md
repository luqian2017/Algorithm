1587. String Segmentation

Now there is a string, the first character represents the first-level separator, separating different key-value pairs, the second character represents the second-level separator, separating key and value and the next string represents the string to be processed.
Please give all valid key-value pairs.

Example
Example1
input:"#:a:3#b:8#c:9"
output:[["a","3"],["b","8"],["c","9"]]
Example 2
input:"#:aa:3#b:853#:9"
output:[["aa","3"],["b","853"]]
Notice
Valid key-value pairs are key-value pairs that neither key nor value is empty.
The problem ensures that the separator is not letters or numbers, and the string to be processed contains only two types of separators, lowercase letters and numbers.
There can be at most one second-level separator between two first-level separators.
The length of the string in problem is no more than 1000.

