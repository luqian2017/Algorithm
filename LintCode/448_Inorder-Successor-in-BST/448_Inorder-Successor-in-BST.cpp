/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */


class Solution {
public:
    /*
     * @param root: The root of the BST.
     * @param p: You need find the successor node of p.
     * @return: Successor of p.
     */
    TreeNode * inorderSuccessor(TreeNode * root, TreeNode * p) {
        if (!root) return NULL;
        
        TreeNode * successor = NULL;
        
        while(root) {
            if (p->val >= root->val) {
                root = root->right;
            } else {
                if (!successor || root->val < successor->val) {
                    successor = root;
                }
                root = root->left;
            }
        }
        return successor;
        
        
    }
};