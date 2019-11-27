926. Shortest Word Distance III
中文English
This is a follow up of Shortest Word Distance. The only difference is now word1 could be the same as word2.

Given a list of words and two words word1 and word2, return the shortest distance between these two words in the list.

word1 and word2 may be the same and they represent two individual words in the list.

Example
Example 1:

Input: words = ["practice", "makes", "perfect", "coding", "makes"], word1 = "makes", word2 = “coding"
Output: 1
Example 2:

Input: words =["a","a","c","b"], word1 = "a", word2 = "b"
Output: 2
Notice
You may assume word1 and word2 are both in the list.

Solution 1:
1) Need to differentiate the two cases of "word1 == word2" and "word1 != word2".
For the case "word1 == word2", just record the same word's current position and its previous position.
