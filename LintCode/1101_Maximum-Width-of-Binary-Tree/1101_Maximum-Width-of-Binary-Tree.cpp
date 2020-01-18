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
        q.push(root);
        
        while(!q.empty()) {
            int qSize = q.size();
            
            vector<int> validArray;
            for (int i = 0; i < qSize; ++i) {
                TreeNode * node = q.front();
                q.pop();
                if (!node) {
                    validArray.push_back(0);
                    q.push(NULL);
                    q.push(NULL);
                    continue;
                } else {
                    validArray.push_back(1);
                }
                
                if (node->left) q.push(node->left);
                else q.push(NULL);
                if (node->right) q.push(node->right);
                else q.push(NULL);
            }
            int maxWidth = validArray.size();
            for (int i = validArray.size() - 1; i >= 0; --i) {
                if (validArray[i] == 1) break;
                else maxWidth--;
            }
            gMaxWidth = max(gMaxWidth, maxWidth);
        }
        
        return gMaxWidth;
    }
};