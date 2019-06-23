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
     * @param root: a TreeNode, the root of the binary tree
     * @return: nothing
     */
    void invertBinaryTree(TreeNode * root) {
        if (!root) return;
        
        helper(root);
        
        return;
    }

private:
    TreeNode * helper(TreeNode * root) {
        if (!root) return NULL;

        TreeNode * origRight = root->right;
        root->right = helper(root->left);
        root->left = helper(origRight);
        
        return root;
    }
};