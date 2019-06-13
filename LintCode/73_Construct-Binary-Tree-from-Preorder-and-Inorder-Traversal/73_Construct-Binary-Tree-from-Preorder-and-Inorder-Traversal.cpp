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
     *@param preorder : A list of integers that preorder traversal of a tree
     *@param inorder : A list of integers that inorder traversal of a tree
     *@return : Root of a tree
     */
    TreeNode * buildTree(vector<int> &preorder, vector<int> &inorder) {
        return helper(preorder.begin(), preorder.end(), inorder.begin(), inorder.end());
    }
    
private:
    TreeNode * helper(vector<int>::iterator preorderStart, vector<int>::iterator preorderEnd,
                      vector<int>::iterator inorderStart, vector<int>::iterator inorderEnd) {
    if (inorderStart == inorderEnd) return NULL;
    
    vector<int>::iterator inorderRootIter = find(inorderStart, inorderEnd, *preorderStart);
    TreeNode * root = new TreeNode(*inorderRootIter);
    root->left = helper(preorderStart + 1, preorderStart + 1 + (inorderRootIter - inorderStart), inorderStart, inorderRootIter);
    root->right = helper(preorderStart + 1 + (inorderRootIter - inorderStart), preorderEnd, inorderRootIter + 1, inorderEnd);
    
    return root;
    }
    
};