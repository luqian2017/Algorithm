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
     * @return: A list of lists of integer include the zigzag level order traversal of its nodes' values.
     */
    vector<vector<int>> zigzagLevelOrder(TreeNode * root) {
        if (!root) return {};
        queue<TreeNode *> q;
        q.push(root);
        bool left2Right = true;
        vector<int> levelNodesValue;
        vector<vector<int>> result;
        
        while(!q.empty()) {
            int qSize = q.size();
            for (int i = 0; i < qSize; ++i) {
                TreeNode * node = q.front();
                q.pop();
                levelNodesValue.push_back(node->val);
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            
            if (left2Right) {
                left2Right = false;
            } else {
                reverse(levelNodesValue.begin(), levelNodesValue.end());
                left2Right = true;
            }            
            result.push_back(levelNodesValue);
            levelNodesValue.clear();
        }
        return result;
    }
};