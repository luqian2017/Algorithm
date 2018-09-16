Solution 1: 
Using set. Time complexity O(nlogn)

Solution 2:
Using hash_set. Time complexity O(n).

Note:
1) We can initialize a set or hash_set by 
        unordered_set<int> s(nums1.begin(), nums1.end());

2) After we found an element in s2 already exisits in the set, we can erase it such that we don't need to care the duplicate in s2.