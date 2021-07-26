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
     * @return: the root of the maximum average of subtree
     */
    TreeNode * findSubtree2(TreeNode * root) {
        int cnt = 0;
        getSum(root, cnt);
        return maxAvgNode;
    }
private:
    double maxAvg = LLONG_MIN;
    TreeNode *maxAvgNode = NULL;
    double getSum(TreeNode *root, int &cnt) {
        if (!root) {
            cnt = 0;
            return 0;
        }
        int cnt_left, cnt_right;
        double res = getSum(root->left, cnt_left) + getSum(root->right, cnt_right) + root->val;
        cnt = cnt_left + cnt_right + 1;
        if (maxAvg < res / cnt) {
            maxAvg = res / cnt;
            maxAvgNode = root;
        }
        return res;
    }
};