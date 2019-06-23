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
     * @param root: A Tree
     * @return: Preorder in ArrayList which contains node values.
     */
    vector<int> preorderTraversal(TreeNode * root) {
        vector<int> result;
        helper(root, result);
        return result;
    }
    
private:
    void helper(TreeNode * root, vector<int> & result) {
        if (!root) return;
        result.push_back(root->val);
        helper(root->left, result);
        helper(root->right, result);
    }
};