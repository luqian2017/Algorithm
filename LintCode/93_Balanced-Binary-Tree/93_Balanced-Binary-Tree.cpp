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
    int depth;
    bool isBalanced;
    ResultType(int dp = 0, bool iB = true) : depth(dp), isBalanced(iB) {}
};

class Solution {
public:
    /**
     * @param root: The root of binary tree.
     * @return: True if this Binary tree is Balanced, or false.
     */
    bool isBalanced(TreeNode * root) {
        return depth(root).isBalanced;
    }
    
private:
    ResultType depth(TreeNode * root) {
        if (!root) return ResultType();
        
        ResultType left = depth(root->left);
        if (!left.isBalanced) return ResultType(-1, false);
        
        ResultType right = depth(root->right);
        if (!right.isBalanced) return ResultType(-1, false);
        
        int maxDepth = max(left.depth, right.depth);
        if (abs(left.depth - right.depth) <= 1) {
            return ResultType(maxDepth + 1, true);
        } else {
            return ResultType(maxDepth + 1, false);
        }
    }
};