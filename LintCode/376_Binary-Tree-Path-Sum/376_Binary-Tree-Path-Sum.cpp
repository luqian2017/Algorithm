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
        if (!root) {
            if (target == 0) {
                vv.push_back(v);
            }
            return;
        }
        
        v.push_back(root->val);
        helper(root->left, target - root->val, v);
        helper(root->right, target - root->val, v);
        v.pop_back();
    }
    
};