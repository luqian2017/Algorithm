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
    * @param root: root of the given tree
    * @return: whether it is a mirror of itself
    */
    bool isSymmetric(TreeNode * root) {
        return helper(root, root);
    }
    
    bool helper(TreeNode * root1, TreeNode * root2) {
        if (!root1 && !root2) return true;
        if (!root1 || !root2) return false;
        if (root1->val != root2->val) return false;
        return helper(root1->left, root2->right) && helper(root1->right, root2->left);
    }
};
