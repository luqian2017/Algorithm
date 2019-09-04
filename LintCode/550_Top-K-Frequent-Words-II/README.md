550. Top K Frequent Words II
中文English
Find top k frequent words in realtime data stream.

Implement three methods for Topk Class:

TopK(k). The constructor.
add(word). Add a new word.
topk(). Get the current top k frequent words.
Example
Example 1:

Input：
TopK(2)
add("lint")
add("code")
add("code")
topk()
Output：["code", "lint"]
Explanation：
"code" appears twice and "lint" appears once, they are the two most frequent words.
Example 2:

Input：
TopK(1)
add("aa")
add("ab")
topk()
Output：["aa"]
Explanation：
"aa" and "ab" appear once , but aa's dictionary order is less than ab's.
Notice
If two words have the same frequency, rank them by dictionary order.

