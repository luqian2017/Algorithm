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
        helper(root, p);
        return successor;
    }
private:
    void helper(TreeNode *root, TreeNode *p) {
        if (!root) return;
        helper(root->left, p);

        if (find) {
            successor = root;
            find = false;
            return;
        } else {
            if (root == p) find = true;
        }

        helper(root->right, p);
        
    }
    bool find = false;
    TreeNode * successor = NULL;
};