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
        return g_max;
    }
private:
    int g_max = INT_MIN;
    int helper(TreeNode *root) {
        if (!root) return 0;
        int sum_left = helper(root->left);
        int sum_right = helper(root->right);
        
        g_max = max(g_max, root->val);
        g_max = max(g_max, root->val + sum_left);
        g_max = max(g_max, root->val + sum_right);
        g_max = max(g_max, root->val + sum_left + sum_right);
            
        return root->val + max(sum_left, sum_right);
    }
};