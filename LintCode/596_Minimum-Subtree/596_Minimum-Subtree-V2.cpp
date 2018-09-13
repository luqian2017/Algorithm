class Solution {
public:
    /**
     * @param root: the root of binary tree
     * @return: the root of the minimum subtree
     */
    TreeNode * findSubtree(TreeNode * root) {
        helper(root);
        return recordRoot;
    }

private:
    int helper(TreeNode * root) {
        if (!root) 
            return 0;
            
        int sum = helper(root->left)+helper(root->right)+root->val;
        if (sum < minSum) {
            recordRoot = root;
            minSum = sum;
        }
        return sum;
    }

    int minValue=INT_MAX;
    TreeNode *recordNode;
};