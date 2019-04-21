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
          
        queue<TreeNode *> q1, q2;
        q1.push(root);
        
        while(!q1.empty()) {
            int n = q1.size();
            vector<int> lines;
            for (int i = 0; i < n; ++i) {
                TreeNode * node = q1.front();
                q1.pop();
                lines.push_back(node->val);
                if (node->left) {
                    q2.push(node->left);
                }
                if (node->right) {
                    q2.push(node->right);
                }
            }
            result.push_back(lines);
            swap(q1, q2);
        }
        
        return result;
    }
};