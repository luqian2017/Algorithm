class Solution {
public:
    /**
     * @param root: the tree
     * @param sum: the sum
     * @return:  if the tree has a root-to-leaf path 
     */
    bool pathSum(TreeNode * root, int sum) {
        // Write your code here.
        if (root == nullptr) return false;
            else if (root->val == sum && !root->left && !root->right)  return true;
        	else return pathSum(root->left, sum - root->val) || pathSum(root->right, sum - root->val);
    }
};