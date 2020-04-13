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
     * @param root: the tree
     * @param sum: the sum
     * @return:  if the tree has a root-to-leaf path 
     */
    bool pathSum(TreeNode * root, int sum) {
        if (!root) {
            if (sum == 0) return true;
            else return false;
        }
        return pathSum(root->left, sum - root->val) || pathSum(root->right, sum -root->val);
    }
};