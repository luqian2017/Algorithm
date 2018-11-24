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
     * @param nums: an array
     * @return: the maximum tree
     */
    TreeNode * constructMaximumBinaryTree(vector<int> &nums) {
        return helper(nums, 0, nums.size() - 1); 
    }
    
private:
    TreeNode * helper(vector<int> &nums, int start, int end) {
        if (start > end) return NULL;
        
        int max = nums[start];
        int max_index = start;
        
        for (int i = start; i <= end; ++i) {

            if (nums[i] > max) {
                max = nums[i];
                max_index = i;
            }
        }
        
        TreeNode *node = new TreeNode(nums[max_index]);
        node->left = helper(nums, start, max_index - 1);
        node->right = helper(nums, max_index + 1, end);
        return node;
    }
};