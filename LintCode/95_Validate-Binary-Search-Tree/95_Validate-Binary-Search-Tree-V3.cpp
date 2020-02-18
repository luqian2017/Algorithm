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
     * @return: True if the binary tree is BST, or false
     */
    bool isValidBST(TreeNode * root) {
        return helper(root, LONG_MIN, LONG_MAX);
    }
    
private:
    bool helper(TreeNode * root, long leftMin, long rightMax) {
        if (!root) return true;
        if (root->val <= leftMin|| root->val >= rightMax) return false;
        return helper(root->left, leftMin, root->val) && helper(root->right, root->val, rightMax);
        
    }
};