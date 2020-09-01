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
     * @param sum: 
     * @return: the num of sum path
     */
    int pathSum(TreeNode * root, int sum) {
        helper(root, sum);
        return count;
    }

private:
    int count = 0;

    void dfs(TreeNode * root, int sum) {
        if (!root) return;
        if (root->val == sum) {
            count++;
            return;
        }
        
        dfs(root->left, sum - root->val);
        dfs(root->right, sum - root->val);
    }
    
    void helper(TreeNode * root, int sum) {
        if (!root) return;
        dfs(root, sum);
        helper(root->left, sum);
        helper(root->right, sum);
    }
};