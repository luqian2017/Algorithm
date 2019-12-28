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
     * @return: new root
     */
    TreeNode * upsideDownBinaryTree(TreeNode * root) {
        if (!root || !root->left) return root;
        TreeNode * result = dfs(root);
        root->left = NULL;
        root->right = NULL;

        return result;
    }

private:
    TreeNode * dfs(TreeNode * root) {
        if (!root || !root->left) return root;
        TreeNode *left = root->left;
        TreeNode *right = root->right;
        TreeNode * result = dfs(root->left);
        left->left = right;
        left->right = root;
        return result;
    }
};