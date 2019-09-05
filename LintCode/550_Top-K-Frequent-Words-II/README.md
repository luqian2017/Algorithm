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


解法1：用set和map。
注意:
1) 因为是real-time数据，可以用最小堆。但是C++的priority_heap不能根据堆元素的改变值动态调整堆，那我们就用set来实现。每次当word在set中时，将words[word]++，然后将set中的word删除再加入，这样就可以实现动态调节，而且set会自动排好序。
2) 这里是real-time数据，所以只能实现迄今为止来的数据中的topK。
3) C++的priority_queue不提供adjust函数，可以用set来替代。
4) set<string, cmp>可以同时定义string的比较函数
5) words和q里面的元素不一样。words里面的元素永远不删除，而q里面只保留最多k个元素。
