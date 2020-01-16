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
     * @param root: the root of the given tree
     * @return: the values of the nodes you can see ordered from top to bottom
     */
    vector<int> rightSideView(TreeNode * root) {
        if (!root) return {};
        vector<int> result;
        queue<TreeNode *> q;
        q.push(root);
        
        while(!q.empty()) {
            int qSize = q.size();  
            TreeNode * node = NULL;
            for (int i = 0; i < qSize; ++i) {
                node = q.front();
                q.pop();
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            result.push_back(node->val);
        }
    
        return result;
    }
};