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
     * @param root: The root of binary tree.
     * @return: The maximum amount of money you can rob tonight
     */
    int houseRobber3(TreeNode * root) {
        return maxChildTree(root);
    }

private:
    int maxChildTree(TreeNode * root) {
        
        if (!root) return 0;
        if (!root->left && !root->right) return max(0, root->val);
        if (!root->left) return max(maxChildTree(root->right->left) + maxChildTree(root->right->right) + max(0, root->val), maxChildTree(root->right));
        if (!root->right) return max(maxChildTree(root->left->left) + maxChildTree(root->left->right) + max(0, root->val), maxChildTree(root->left));
        
        int option1 = maxChildTree(root->left->left) + maxChildTree(root->left->right) + maxChildTree(root->right->left) + maxChildTree(root->right->right) + max(0, root->val);
        
        int option2 = maxChildTree(root->left) + maxChildTree(root->right);
        
        return max(option1, option2);
    }
};