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
     * @param root: The root of binary tree
     * @return: root of new tree
     */
    TreeNode * cloneTree(TreeNode * root) {
        if (!root) return NULL;
        TreeNode * copyRoot = new TreeNode(root->val);
        copyRoot->left = cloneTree(root->left);
        copyRoot->right = cloneTree(root->right);
        return copyRoot;
    }
};