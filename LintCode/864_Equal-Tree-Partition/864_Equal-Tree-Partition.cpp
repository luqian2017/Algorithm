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
     * @param root: a TreeNode
     * @return: return a boolean
     */
    bool checkEqualTree(TreeNode * root) {
        int totalSum = helper(root);

        for (int i = 0; i < sums.size() - 1; ++i) {
            if (sums[i] == totalSum / 2) return true;
        }

        return false;
    }

private:
    vector<long long> sums;

    int helper(TreeNode * root) {
        if (!root) return 0;
        if (!root->left && !root->right) {
            sums.push_back(root->val);
            return root->val;
        }
        int res = helper(root->left) + helper(root->right) + root->val;
        sums.push_back(res);
        return res;
    }
};