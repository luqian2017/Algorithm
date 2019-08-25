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
inline bool operator < (TreeNode & a, TreeNode & b) {
    return a.val < b.val;
}
 
class Solution {
public:
    /*
     * @param root: the root of tree
     * @return: the max node
     */
    TreeNode * maxNode(TreeNode * root) {
        if (!root) return NULL;
        gMaxNode = new TreeNode(INT_MIN);
        helper(root);
        return gMaxNode;
    }
    
private:
    TreeNode * gMaxNode;
    void helper(TreeNode * root) {
        if (!root) return;
        if (*gMaxNode < *root) gMaxNode = root;
        helper(root->left);
        helper(root->right);
        return;
    }
    friend bool operator < (TreeNode & a, TreeNode & b);
};