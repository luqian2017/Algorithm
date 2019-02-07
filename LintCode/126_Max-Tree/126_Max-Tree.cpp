/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */

class Solution {
public:
    /**
     * @param A: Given an integer array with no duplicates.
     * @return: The root of max tree.
     */
    TreeNode * maxTree(vector<int> &A) {
        
        int len = A.size();
        if (len == 0) return NULL;
        
        stack<int> monoDecStack; // mono decreasing stack
        map<int, TreeNode *> mp; // index, TreeNode *

        for (int i = 0; i < len;  ++i) {
            mp[i] = new TreeNode(A[i]);
            while(!monoDecStack.empty() && (A[monoDecStack.top()] < A[i])) {
                int oldTop = monoDecStack.top();
                monoDecStack.pop();
                mp[i]->left = mp[oldTop];
            }
            if (!monoDecStack.empty() && (A[monoDecStack.top()] > A[i])) {
                mp[monoDecStack.top()]->right = mp[i];
            }
            monoDecStack.push(i);
        }
        
        int lastOne = 0;
        while(!monoDecStack.empty()) {
            lastOne = monoDecStack.top();
            monoDecStack.pop();
        }
     
        return mp[lastOne];
    }
};