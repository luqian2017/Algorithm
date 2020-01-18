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
     * @param root: the root
     * @return: the maximum width of the given tree
     */
    int widthOfBinaryTree(TreeNode * root) {
        if (!root) return 0;
        int gMaxWidth = 0;
        queue<TreeNode *> q;
        root->val = 1; 
        q.push(root);
        
        while(!q.empty()) {
            int qSize = q.size();
            gMaxWidth = max(gMaxWidth, q.back()->val - q.front()->val + 1);    
            for (int i = 0; i < qSize; ++i) {
                TreeNode * node = q.front();
                q.pop();
        
                if (node->left) {
                    node->left->val = node->val * 2;
                    q.push(node->left);
                }
                if (node->right) {
                    node->right->val = node->val * 2 + 1;
                    q.push(node->right);
                }                
            }
        }
        
        return gMaxWidth;
    }
};