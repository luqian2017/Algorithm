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
        gMaxtreeSumNode = NULL;
        gMaxtreeSum = INT_MIN;
        treeSum(root);
        
        return gMaxtreeSumNode;
    }

private:
    long long treeSum (TreeNode * root) {
        long long result;
        if (!root) result = 0;
        else if (!root->left && !root->right) result = root->val;
        else {
            result = treeSum(root->left) + treeSum(root->right) + root->val;
        }
        if (result > gMaxtreeSum) {
            gMaxtreeSumNode = root;
            gMaxtreeSum = max(gMaxtreeSum, result);
        }
        return result;
    }
    
    long long gMaxtreeSum;
    TreeNode * gMaxtreeSumNode;
};