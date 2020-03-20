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
     * @param root: a root of binary tree
     * @return: return a integer
     */
    int diameterOfBinaryTree(TreeNode * root) {
        if (!root) return 0;
        int candidate = maxDistToLeaves(root->left) + maxDistToLeaves(root->right);
        return max(max(diameterOfBinaryTree(root->left), diameterOfBinaryTree(root->right)), candidate);
    }
    
private:
    int maxDistToLeaves(TreeNode * root) {
        if (!root) return 0;
        if (!root->left && !root->right) return 1;
        return max(maxDistToLeaves(root->left), maxDistToLeaves(root->right)) + 1;
    }
};