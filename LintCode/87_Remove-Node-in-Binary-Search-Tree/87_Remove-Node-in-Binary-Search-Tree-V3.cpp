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
        if (!root) return nullptr;
        if (value < root->val) {
            root->left = removeNode(root->left, value);
        } else if (value > root->val) {
            root->right = removeNode(root->right, value);
        } else {
            if (!root->left || !root->right) {
                TreeNode *temp = (root->left) ? root->left : root->right;
                delete(root);
                return temp;
            } else {
                //find the successor
                TreeNode *successor = root->right;
                while(successor->left) successor = successor->left;
                
                root->val = successor->val;
                root->right = removeNode(root->right, successor->val);
            }
        }
        return root;
    }
};