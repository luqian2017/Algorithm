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
     * @param inorder: A list of integers that inorder traversal of a tree
     * @param postorder: A list of integers that postorder traversal of a tree
     * @return: Root of a tree
     */
    TreeNode * buildTree(vector<int> &inorder, vector<int> &postorder) {
        return helper(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);
    }
private:
    TreeNode * helper(vector<int> &inorder, int inStart, int inEnd, vector<int> &postorder, int postStart, int postEnd) {
        if (inStart > inEnd) {
            return NULL;
        }
        
        TreeNode * root = new TreeNode(postorder[postEnd]);
        int rootIndex = 0;
        
        for (int i = inStart; i <= inEnd; ++i) {
            if (inorder[i] == postorder[postEnd]) {
                rootIndex = i;
                break;
            }
        }
        int leftTreeCount = rootIndex - inStart;
        int rightTreeCount = inEnd - rootIndex;
        root->left = helper(inorder, inStart, rootIndex - 1, postorder, postStart, postStart + leftTreeCount - 1);
        root->right = helper(inorder, rootIndex + 1, inEnd, postorder, postEnd - rightTreeCount, postEnd - 1);
        return root;
    }
};