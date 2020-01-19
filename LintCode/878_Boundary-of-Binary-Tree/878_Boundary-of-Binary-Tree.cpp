class Solution {
public:
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        if (!root) return {};

        result.push_back(root->val);
        dfs_left(root->left);
        dfs_leaves(root);
        dfs_right(root->right);
        return result;
    }

private:
    vector<int> result;
    
    void dfs_left(TreeNode * root) {
        if (!root || (!root->left && !root->right)) return;
        result.push_back(root->val);
        if (root->left) dfs_left(root->left);
        else if (root->right) dfs_left(root->right);
    }
    
    void dfs_leaves(TreeNode * root) {
        if (!root) return;
        if (!root->left && !root->right) result.push_back(root->val);
        dfs_leaves(root->left);
        dfs_leaves(root->right);
    }
    
    void dfs_right(TreeNode * root) {
        if (!root || (!root->left && !root->right)) return;
        if (root->right) dfs_right(root->right);
        else if (root->left) dfs_right(root->left);
        result.push_back(root->val);
    }
};