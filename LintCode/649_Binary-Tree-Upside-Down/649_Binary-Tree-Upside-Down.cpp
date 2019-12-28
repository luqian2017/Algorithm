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
        TreeNode *left = root->left, *right = root->right;
        
        TreeNode * result = upsideDownBinaryTree(root->left);
        left->left = right;
        left->right = root;
        root->left = NULL;
        root->right = NULL;

        return result;
    }
};