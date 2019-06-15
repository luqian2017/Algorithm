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
    /*
     * @param root: The root of the binary search tree.
     * @param value: Remove the node with given value.
     * @return: The root of the binary search tree after removal.
     */
    TreeNode * removeNode(TreeNode * root, int value) {
        if (!root) return NULL;
   
        if (root->val == value) {
            if (!root->left) return root->right;
            if (!root->right) return root->left;
            
            //find the maximum node in left sub-tree
            TreeNode * node = root->left;
            while(node->right) {
                node = node->right;
            }
            node->right = root->right;
            return root->left;
        }
        
        if (root->val > value) {
            root->left = removeNode(root->left, value);    
        } else {
            root->right = removeNode(root->right, value);
        }
        
        return root;
    }
};