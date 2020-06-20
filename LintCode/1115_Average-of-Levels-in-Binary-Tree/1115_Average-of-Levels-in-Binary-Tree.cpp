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
     * @param root: the binary tree of the  root
     * @return: return a list of double
     */
    vector<double> averageOfLevels(TreeNode * root) {
        vector<double> result;
        queue<TreeNode *> q;
        q.push(root);
        
        while(!q.empty()) {
            int len = q.size();
            double sum = 0.0;
            for (int i = 0; i < len; ++i) {
                TreeNode * cur = q.front();
                q.pop();
                sum += cur->val;
                if (cur->left) q.push(cur->left);
                if (cur->right) q.push(cur->right);
            }
            result.push_back(sum / len);
        }
        
        return result;
    }
};