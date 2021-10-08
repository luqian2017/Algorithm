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
     * @param root: a binary search tree
     * @return: Root of a tree
     */
    TreeNode * increasingBST(TreeNode * root) {
        TreeNode * dummyRoot = new TreeNode(0);
        node = dummyRoot;
        inOrderTravel(root);
        return dummyRoot->right;
    }
private:
    void inOrderTravel(TreeNode * root) {
        if (!root) return;
        inOrderTravel(root->left);
        node->right = new TreeNode(root->val);
        node = node->right;
        inOrderTravel(root->right);
    }
    TreeNode * node;
};