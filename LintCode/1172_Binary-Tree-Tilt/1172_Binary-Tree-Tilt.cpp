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
        getSum(root);
        return tilt_sum;
    }

private:
    int getSum(TreeNode *root) {
        if (!root) return 0;
        if (!root->left && !root->right) {
            return root->val;
        }
        if (!root->left) {
            int ret = getSum(root->right);
            tilt_sum += abs(ret);
            return ret + root->val;
        }
        if (!root->right) {
            int ret = getSum(root->left);   
            tilt_sum += abs(ret);
            return ret + root->val;
        }
        int left_sum = getSum(root->left);
        int right_sum = getSum(root->right);
        tilt_sum += abs(left_sum - right_sum);
        return  left_sum + right_sum + root->val; 
    }

    int tilt_sum = 0;
};