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
     * @param root: the given BST
     * @param p: the given node
     * @return: the in-order predecessor of the given node in the BST
     */
    TreeNode * inorderPredecessor(TreeNode * root, TreeNode * p) {
        TreeNode * pred = NULL;
        while(root) {
            if (p->val <= root->val) {
                root = root->left;
            } else {
                if (!pred || root->val > pred->val) {
                    pred = root;
                }
                root = root->right;
            }
        }
        return pred;
    }
};