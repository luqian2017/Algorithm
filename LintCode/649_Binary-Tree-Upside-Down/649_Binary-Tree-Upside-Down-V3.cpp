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
     * @return: new root
     */
    TreeNode * upsideDownBinaryTree(TreeNode * root) {
        if (!root || !root->left) return root;
        
        TreeNode * pre = NULL;
    //    TreeNode * cur = root;
        TreeNode * tmp = NULL; //for right child
        TreeNode * next = NULL; //for left child
        while(root) {
            next = root->left;
            root->left = tmp;
            tmp = root->right;
            root->right = pre;
            pre = root;
            root = next;
        }
        
        return pre;        
    }
};