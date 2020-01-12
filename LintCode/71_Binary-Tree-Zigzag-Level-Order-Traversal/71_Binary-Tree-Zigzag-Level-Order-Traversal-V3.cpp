class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        helper(root, 0, res);
        return res;
    }
    void helper(TreeNode* node, int level, vector<vector<int>>& res) {
        if (!node) return;
        if (res.size() <= level) {
            res.push_back({});
        }
        vector<int> &oneLevel = res[level];
        if (level % 2 == 0) oneLevel.push_back(node->val);
        else oneLevel.insert(oneLevel.begin(), node->val);
        helper(node->left, level + 1, res);
        helper(node->right, level + 1, res);
    }
};