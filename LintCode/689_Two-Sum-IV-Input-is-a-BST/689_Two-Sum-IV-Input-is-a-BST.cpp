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
     * @param : the root of tree
     * @param : the target sum
     * @return: two number from tree witch sum is n
     */
    vector<int> twoSum(TreeNode * root, int n) {
        if (!root || n <= 0) return vector<int>();
        origRoot = root;
        inOrderTraversal(root, n);
        return result;
    }
    
private:
    TreeNode * origRoot;
    vector<int> result;
    
    bool bst(TreeNode * root, int target) {
        if (!root) return false;
        if (root->val > target) return bst(root->left, target);
        if (root->val < target) return bst(root->right, target);
        return true;
    }
    
    void inOrderTraversal(TreeNode * root, int n) {
        if (!root) return;
        inOrderTraversal(root->left, n);
        if (bst(origRoot, n - root->val)) result = vector<int>{root->val, n - root->val};
        inOrderTraversal(root->right, n);
    }
    
    
};