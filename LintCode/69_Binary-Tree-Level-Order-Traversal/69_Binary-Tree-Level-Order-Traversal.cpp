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
     * @return: Level order a list of lists of integer
     */
    vector<vector<int>> levelOrder(TreeNode * root) {
        vector<vector<int>> result;
        if (!root) return result;
        
        queue<TreeNode *> q;
        q.push(root);
        result.push_back(vector<int>{root->val});
        
        while(!q.empty()) {
            int n = q.size();
            vector<int> nodes;
            for (int i = 0; i < n; ++i) {
                TreeNode * node = q.front();
                q.pop();
                if (node->left) {
                    q.push(node->left);
                    nodes.push_back(node->left->val);
                }
                if (node->right) {
                    q.push(node->right);
                    nodes.push_back(node->right->val);
                }
            }
            if (nodes.size() > 0) result.push_back(nodes);
        }
        
        return result;
    }
};