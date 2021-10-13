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
        if (!root) return 0;
        inOrderTravel(root, L, R);
        return sum;
    }
private:
    void inOrderTravel(TreeNode *root, int L, int R) {
        if (!root) return;
        if (root->val >= L) inOrderTravel(root->left, L, R);
        if (root->val >= L && root->val <= R) sum += root->val;
        if (root->val <= R) inOrderTravel(root->right, L, R);
    }
    int sum = 0;
};