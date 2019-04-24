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
 
 struct ResultType {
     bool isBST;
     TreeNode * minNode, * maxNode;
     ResultType(bool is_bst = true, TreeNode * min_node = NULL, TreeNode * max_node = NULL) : isBST(is_bst), minNode(min_node), maxNode(max_node) {}
 };

class Solution {
public:
    /**
     * @param root: The root of binary tree.
     * @return: True if the binary tree is BST, or false
     */
    bool isValidBST(TreeNode * root) {
        return helper(root).isBST;
    }
    
private:
    ResultType helper(TreeNode * root) {
        if (!root) return ResultType(true);
    //    if (!root->left && !root->right) return ResultType(true, root, root);
        
        ResultType left = helper(root->left);
        if (!left.isBST) return ResultType(false);
        
        ResultType right = helper(root->right);
        if (!right.isBST) return ResultType(false);
        
        //now both left and right subtree are BST
        if (left.maxNode && root->val <= left.maxNode->val) return ResultType(false);
        if (right.minNode && root->val >= right.minNode->val) return ResultType(false);
        
        //is BST
        //return ResultType(true, left.minNode, right.maxNode);
        ResultType result = ResultType(true);
        result.minNode = left.minNode ? left.minNode : root;
        result.maxNode = right.maxNode ? right.maxNode : root;
        return result;
    }
};