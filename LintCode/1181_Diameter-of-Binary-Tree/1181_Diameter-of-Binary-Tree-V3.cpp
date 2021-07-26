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
     * @param root: a root of binary tree
     * @return: return a integer
     */
    int diameterOfBinaryTree(TreeNode * root) {
        if (!root) return 0;
        dfs(root);
        return maxLen;
    }
private:
    int maxLen = 0;
    int dfs(TreeNode *root) {
        
        if (!root) return 0;
        if (!root->left && !root->right) return 0;
        int leftLen = 0, rightLen = 0;
        leftLen = dfs(root->left);
        rightLen = dfs(root->right);
       // cout << root->val << " " << leftLen << " " << rightLen << endl;
        if (!root->left || !root->right) {
            if (maxLen < leftLen + rightLen + 1) maxLen = leftLen + rightLen + 1;
        }
        else if (maxLen < leftLen + rightLen + 2) maxLen = leftLen + rightLen + 2;
        return max(leftLen, rightLen) + 1;
    }
};