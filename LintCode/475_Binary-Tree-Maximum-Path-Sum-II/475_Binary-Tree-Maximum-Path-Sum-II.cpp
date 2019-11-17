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
     * @param root: the root of binary tree.
     * @return: An integer
     */
    int maxPathSum2(TreeNode * root) {
        if (!root) return 0;
        int result = 0;
        
        result = max(maxPathSum2(root->left), maxPathSum2(root->right));
        
        if (result < 0) return root->val;
        else return result + root->val;
    }

};