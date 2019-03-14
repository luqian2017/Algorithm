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
    // @param nestedList a list of NestedInteger
    // @return a list of integer
    vector<int> flatten(vector<NestedInteger> &nestedList) {
        int n = nestedList.size();
        vector<int> result;
        helper(nestedList, result);
        return result;
    }

private:
    void helper(const vector<NestedInteger> &nestedList, vector<int> &result) {
        int n = nestedList.size();
        for (int i = 0; i < n; ++i) {
            if (nestedList[i].isInteger()) {
                result.push_back(nestedList[i].getInteger());
            } else {
                helper(nestedList[i].getList(), result);
            }
        }
    }
};