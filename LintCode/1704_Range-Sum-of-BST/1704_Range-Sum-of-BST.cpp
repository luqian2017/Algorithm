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
     * @param root: the root node
     * @param L: an integer
     * @param R: an integer
     * @return: the sum
     */
    int rangeSumBST(TreeNode * root, int L, int R) {
        int sum = 0;
        helper(root, L, R, sum);
        return sum;
    }
private:
    void helper(TreeNode * root, int L, int R, int & sum) {
        if (!root) return;
        if (root->val >= L && root->val <= R) sum += root->val;
        if (root->val > L) helper(root->left, L, R, sum);
        if (root->val < R) helper(root->right, L, R, sum);
    }
    
};