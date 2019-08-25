549. Top K Frequent Words (Map Reduce)
中文English
Find top k frequent words with map reduce framework.

The mapper's key is the document id, value is the content of the document, words in a document are split by spaces.

For reducer, the output should be at most k key-value pairs, which are the top k words and their frequencies in this reducer. The judge will take care about how to merge different reducers' results to get the global top k frequent words, so you don't need to care about that part.

The k is given in the constructor of TopK class.

Example
Example1

Input:
document A = "lintcode is the best online judge
I love lintcode" and 
document B = "lintcode is an online judge for coding interview
you can test your code online at lintcode"

Output: 
"lintcode", 4
"online", 3
Example2

Input:
document A = "a a a b b b" 和
document B = "a a a b b b"

Output: 
"a", 6
"b", 6
Notice
For the words with same frequency, rank them with alphabet.

