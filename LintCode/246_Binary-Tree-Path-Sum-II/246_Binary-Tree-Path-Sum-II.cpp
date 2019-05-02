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
    /*
     * @param root: the root of binary tree
     * @param target: An integer
     * @return: all valid paths
     */
    vector<vector<int>> binaryTreePathSum2(TreeNode * root, int target) {
        if (!root) return vv;
        vector<int> v;
        helper(root, target, v);
        return vv;
    }

private:
    vector<vector<int>> vv;
    void helper(TreeNode * root, int target, vector<int> & v) {
        if (!root) return;

        v.push_back(root->val);

        int sum = 0, n = v.size();
        for (int i = n - 1; i >= 0; --i) {
            sum += v[i];
            if (sum == target) {
                vv.push_back(vector<int>(v.begin() + i, v.end()));
            }
                
        }
        
        helper(root->left, target, v);
        helper(root->right, target, v);

        v.pop_back();
    }
};