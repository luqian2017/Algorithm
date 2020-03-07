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
     * @param nums: the sorted array
     * @return: the root of the tree
     */
    TreeNode * convertSortedArraytoBinarySearchTree(vector<int> &nums) {
        return helper(nums, 0, nums.size() - 1);
    }

private:
    TreeNode * helper(vector<int> & nums, int start, int end) {
        if (start > end) return NULL;
        int mid = start + (end - start) / 2;
        TreeNode * root = new TreeNode(nums[mid]);
        root->left = helper(nums, start, mid - 1);
        root->right = helper(nums, mid + 1, end);
        return root;
    }
};