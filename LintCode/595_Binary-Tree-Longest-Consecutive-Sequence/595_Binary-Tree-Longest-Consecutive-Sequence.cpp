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
     * @param root: the root of binary tree
     * @return: the length of the longest consecutive sequence path
     */
    int longestConsecutive(TreeNode * root) {
        helper(root);
        return maxLen;
    }

private:
    int maxLen = 0;
    int helper(TreeNode * root) {
        if (!root) return 0;
        if (!root->left && !root->right) return 1;
        int leftNum = 0, rightNum = 0;

        if (root->left) {
            leftNum = helper(root->left);
            if (root->val == root->left->val - 1) {
                leftNum++;
                maxLen = max(maxLen, leftNum);
            } else {
                maxLen = max(maxLen, leftNum);
                leftNum = 1;
            }
        }

        if (root->right) {
            rightNum = helper(root->right);
            if (root->val == root->right->val - 1) {
                rightNum++;
                maxLen = max(maxLen, rightNum);
            } else {
                maxLen = max(maxLen, rightNum);
                rightNum = 1;
            }
        }

        return max(leftNum, rightNum);
    }
};