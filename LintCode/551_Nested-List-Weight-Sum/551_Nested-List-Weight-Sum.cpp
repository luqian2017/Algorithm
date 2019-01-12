/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer,
 *     // rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds,
 *     // if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds,
 *     // if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
public:
    int depthSum(const vector<NestedInteger>& nestedList) {
        int result = 0;
        
        for (auto i : nestedList) {
            result += helper(i, 1);
        }
        
        return result;
    }
    
    int helper(const NestedInteger &nestInt, int depth) {
        if (nestInt.isInteger()) return nestInt.getInteger() * depth;
        
        int len = nestInt.getList().size();
        int result = 0;
        vector<NestedInteger> nestList = nestInt.getList();
        for (int i = 0; i < len; ++i) {
            result += helper(nestList[i], (depth + 1));
        }
        return result;
    }
};