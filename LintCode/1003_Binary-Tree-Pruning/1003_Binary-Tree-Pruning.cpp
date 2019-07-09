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
     * @param root: the root
     * @return: the same tree where every subtree (of the given tree) not containing a 1 has been removed
     */
    TreeNode * pruneTree(TreeNode * root) {
        if (!root) return NULL;
        
        TreeNode * leftNode = pruneTree(root->left);
        TreeNode * rightNode = pruneTree(root->right);
        
        root->left = leftNode;
        root->right = rightNode;
        
        if (!leftNode && !rightNode && root->val == 0) {
            root = NULL;
        }
        return root;
    }
};