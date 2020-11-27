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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        if (!root) return res;
        
        queue<TreeNode *> q;
        q.push(root);
        
        while(!q.empty()) {
            int qSize = q.size();
            vector<int> level;
            for (int i = 0; i < qSize; ++i) {
                TreeNode *frontNode = q.front();
                q.pop();
                level.push_back(frontNode->val);
                if (frontNode->left) q.push(frontNode->left);
                if (frontNode->right) q.push(frontNode->right);                
            }
            res.insert(res.begin(), level);
        }
        
        return res;
    }
};