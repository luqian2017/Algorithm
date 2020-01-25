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
     * @param root: The root of the binary tree.
     * @param A: A TreeNode
     * @param B: A TreeNode
     * @return: Return the LCA of the two nodes.
     */
    TreeNode * lowestCommonAncestor3(TreeNode * root, TreeNode * A, TreeNode * B) {
        if (!root || !findNode(root, A) || !findNode(root, B)) return NULL;
        return helper(root, A, B);
    }

private:
    bool findNode(TreeNode * root, TreeNode * node) {
        if (!root) return false;
        if (root == node) return true;
        return findNode(root->left, node) || findNode(root->right, node);
    }
    
    TreeNode * helper(TreeNode * root, TreeNode * A, TreeNode * B) {
        if (!root || root == A || root == B) return root;
        TreeNode * leftFind = helper(root->left, A, B);
        TreeNode * rightFind = helper(root->right, A, B);
        if (leftFind && rightFind) return root;
        return leftFind ? leftFind : rightFind;
    }
};