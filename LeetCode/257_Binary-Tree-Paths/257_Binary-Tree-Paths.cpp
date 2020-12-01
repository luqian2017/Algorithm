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
    vector<string> binaryTreePaths(TreeNode* root) {
        if (!root) return {};
        string str;
        dfs(root, str);
        return res;
            
    }
private:
    void dfs(TreeNode *root, string str) {
        if (!root) {
            return;
        }
        str = str + to_string(root->val);
        if (!root->left && !root->right) {
            res.push_back(str);
            return;
        }
        if (root->left) {
            string new_str = str + "->"; 
            dfs(root->left, new_str);
            
        }
        if (root->right) {
            string new_str = str + "->"; 
            dfs(root->right, new_str);            
        }
    }
    vector<string> res;
};