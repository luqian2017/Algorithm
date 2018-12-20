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
     * @param root: 
     * @return: the sum of leafnode
     */
    int sumLeafNode(TreeNode * root) {
        if (!root) return 0;
        if (!root->left && !root->right) return root->val;
        return sumLeafNode(root->left) + sumLeafNode(root->right);
    }
    
};