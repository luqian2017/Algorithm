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
     * @param root: t
     * @return: the sum of all left leaves
     */
    int sumOfLeftLeaves(TreeNode * root) {
        int leftSum = 0;
        dfs(root, leftSum);
        return leftSum;
    }

private:
    void dfs(TreeNode * root, int &leftSum) {
        if (!root) return;
        if (root->left && !root->left->left && !root->left->right) {
            leftSum += root->left->val;   
        } else {
            dfs(root->left, leftSum);
        } 
        dfs(root->right, leftSum);
    }
    
};