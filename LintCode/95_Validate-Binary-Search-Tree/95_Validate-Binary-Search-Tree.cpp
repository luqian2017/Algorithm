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
     * @return: True if the binary tree is BST, or false
     */
    bool isValidBST(TreeNode * root) {
        if (!root)
            return true;

        if (root && !root->left && !root->right) 
            return true;

        ReturnType ret = helper(root, LONG_MIN, LONG_MAX);

        if (ret.valid)
            return true;
        else
            return false;
    }

private:
    struct ReturnType {
        long min;
        long max;
        bool valid;
        ReturnType(long a = LONG_MIN, long b = LONG_MAX, bool c = true) : min(a), max(b), valid(c) {}
    };

    ReturnType helper(TreeNode* root, long min, long max) {
        ReturnType ret;

        if (!root) 
            return ret;

        ReturnType leftRet = helper(root->left, min, (long)root->val);
        ReturnType rightRet = helper(root->right, (long)root->val, max);

        if (!leftRet.valid || !rightRet.valid || root->val <= min || root->val >= max)
            return ReturnType(min, max, false);

        return ReturnType(min, max, true);
    }
};