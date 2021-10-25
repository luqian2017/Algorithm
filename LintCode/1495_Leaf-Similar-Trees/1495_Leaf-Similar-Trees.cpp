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
     * @param root1: the first tree
     * @param root2: the second tree
     * @return: returns whether the leaf sequence is the same
     */
    bool leafSimilar(TreeNode * root1, TreeNode * root2) {
        vector<int> leaves1, leaves2;
        helper(root1, leaves1);
        helper(root2, leaves2);
        return leaves1 == leaves2;
    }

private:
    void helper(TreeNode *root, vector<int> &leaves) {
        if (!root) return;
        helper(root->left, leaves);
        if (!root->left && !root->right) leaves.push_back(root->val);
        helper(root->right, leaves);
    }
};