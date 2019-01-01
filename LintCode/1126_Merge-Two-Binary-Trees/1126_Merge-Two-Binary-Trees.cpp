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
     * @param t1: the root of the first tree
     * @param t2: the root of the second tree
     * @return: the new binary tree after merge
     */
    TreeNode * mergeTrees(TreeNode * t1, TreeNode * t2) {
        TreeNode * node = NULL;
        if (t1 && t2) {
            node = new TreeNode(t1->val + t2->val);
            node->left = mergeTrees(t1->left, t2->left);
            node->right = mergeTrees(t1->right, t2->right);
        } else if (t1 && !t2) {
            node = new TreeNode(t1->val);
            node->left = mergeTrees(t1->left, NULL);
            node->right = mergeTrees(t1->right, NULL);
        } else if (!t1 && t2) {
            node = new TreeNode(t2->val);
            node->left = mergeTrees(NULL, t2->left);
            node->right = mergeTrees(NULL, t2->right);
        }     
        return node;
    }
    
};