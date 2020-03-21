class Solution {
public:
    /**
     * @param root: a root of binary tree
     * @return: return a integer
     */
    int diameterOfBinaryTree(TreeNode * root) {
        maxDepth(root);
        return diameter;
    }
private:
    int diameter = 0;
    int maxDepth(TreeNode * root) {
        if (!root) return 0;
        int left = maxDepth(root->left);
        int right= maxDepth(root->right);
        diameter = max(diameter, left + right);
        return max(left, right) + 1;
    }
};