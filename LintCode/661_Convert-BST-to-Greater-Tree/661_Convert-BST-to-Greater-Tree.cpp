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
     * @return: the new root
     */
    TreeNode * convertBST(TreeNode * root) {
        int sum = 0;
        helper(root, sum);
        return root;
    }
    
    void helper(TreeNode * root, int & sum) {
        if (!root) return;
        
        helper(root->right, sum);
        root->val += sum;
        sum = root->val;
        helper(root->left, sum);
    }
};