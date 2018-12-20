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
     * @return: the maximum weight node
     */
    TreeNode * findSubtree(TreeNode * root) {
        if (!root) return NULL;
        
        helper(root);
        return g_maxSubTreeNode;
    }
    
    int helper(TreeNode *root) {
        if (!root) return 0;

        int sumLeft = helper(root->left);
        int sumRight = helper(root->right);
        int sumTotal = sumLeft + sumRight + root->val;
        
        if (sumLeft >= g_maxSubTree) {
            g_maxSubTreeNode = root->left;
            g_maxSubTree = sumLeft;
        } 
        
        if (sumRight >= g_maxSubTree) {
            g_maxSubTreeNode = root->right;
            g_maxSubTree = sumRight;
        } 
        
        if (sumTotal >= g_maxSubTree) {
            g_maxSubTreeNode = root;
            g_maxSubTree = sumTotal;
        }
        
        return sumTotal;
    }
    
private:
    TreeNode * g_maxSubTreeNode;
    int g_maxSubTree = INT_MIN;
};