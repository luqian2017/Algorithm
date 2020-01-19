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
     * @param root: the root of binary tree
     * @return: the maximum weight node
     */
    TreeNode * findSubtree(TreeNode * root) {
        long long maxSum = INT_MIN;
        TreeNode * maxSumNode = NULL;
        
        treeSum(root, maxSum, maxSumNode);
        
        return maxSumNode;
    }

private:
    long long treeSum (TreeNode * root, long long & maxSum, TreeNode * & maxSumNode) {
        long long result;
        if (!root) result = 0;
        else if (!root->left && !root->right) result = root->val;
        else {
            result = treeSum(root->left, maxSum, maxSumNode) + treeSum(root->right, maxSum, maxSumNode) + root->val;
        }
        if (result > maxSum) {
            maxSumNode = root;
            maxSum = max(maxSum, result);
        }
        return result;
    }
};