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
        vector<TreeNode *> pNodes(len, NULL); // index, TreeNode *

        for (int i = 0; i < len;  ++i) {
            pNodes[i] = new TreeNode(A[i]);
            while(!monoDecStack.empty() && (A[monoDecStack.top()] < A[i])) {
                int oldTop = monoDecStack.top();
                monoDecStack.pop();
                pNodes[i]->left = pNodes[oldTop];
            }
            if (!monoDecStack.empty() && (A[monoDecStack.top()] > A[i])) {
                pNodes[monoDecStack.top()]->right = pNodes[i];
            }
            monoDecStack.push(i);
        }
        
        int lastOne = 0;
        while(!monoDecStack.empty()) {
            lastOne = monoDecStack.top();
            monoDecStack.pop();
        }
     
        return pNodes[lastOne];
    }
};