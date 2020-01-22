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
     * @param root: The root of binary tree.
     * @return: An integer
     */
    int maxPathSum(TreeNode * root) {
        
        helper(root);
        return gMaxSum;
    }

private:
    int gMaxSum = INT_MIN;
    int helper(TreeNode * root) {
        if (!root) return 0;

        int leftSum = 0, rightSum = 0, result = 0;
        
        leftSum = helper(root->left);
        rightSum = helper(root->right);
        
        int minSideSum = min(leftSum, rightSum);
        int maxSideSum = max(leftSum, rightSum);
        if (maxSideSum < 0) {
            result = root->val;
        } else {
            result = maxSideSum + root->val;
        } 
        gMaxSum = max(gMaxSum, max(leftSum + rightSum + root->val, result));
        return result;
    }
};