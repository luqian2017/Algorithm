/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if (!root) return true;
        if (!root->left && !root->right) return true;
        if (!isBalanced(root->left) || !isBalanced(root->right)) return false;
        int left_height = dfs(root->left);
        int right_height = dfs(root->right);
        return abs(dfs(root->left) - dfs(root->right)) <= 1;
    }
private:
    //get height
    int dfs(TreeNode* root) {
        if (!root) return 0;
        if (!root->left && !root->right) return 1;
        return max(dfs(root->left), dfs(root->right)) + 1;
    }
};