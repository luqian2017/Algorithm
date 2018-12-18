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
     * @param root: the root
     * @return: minimum sum
     */
    int minimumSum(TreeNode * root) {
        if (!root) return 0;
        if (!root->left && !root->right) return root->val;
        if (!root->left && root->right) return root->val + minimumSum(root->right);
        if (root->left && !root->right) return root->val + minimumSum(root->left);
        return root->val + min(minimumSum(root->left), minimumSum(root->right));
    }
};