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
     * @return: the tilt of the whole tree
     */
    int findTilt(TreeNode * root) {
        int tilt = 0;
        dfs(root, tilt);
        return tilt;
    }

private:
    int dfs(TreeNode *root, int &tilt) {
        if (!root) return 0;
        
        int left_sum = dfs(root->left, tilt);
        int right_sum = dfs(root->right, tilt);
        tilt += abs(left_sum - right_sum);
        return  left_sum + right_sum + root->val; 
    }
};