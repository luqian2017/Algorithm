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
#include <limits>
struct ResultType {
    TreeNode * node;
    int sum;
    int count;
    ResultType(TreeNode * t = NULL, int s = 0, int c = 0) : node(t), sum(s), count(c) {}
};

class Solution {
public:
    /**
     * @param root: the root of binary tree
     * @return: the root of the maximum average of subtree
     */
    TreeNode * findSubtree2(TreeNode * root) {
        if (!root) return NULL;
        
        maxResult = ResultType(NULL, INT_MIN, 0);
        
        helper(root);

        return maxResult.node;
    }
    
    ResultType helper(TreeNode * root) {
        if (!root) return ResultType();
        ResultType left = helper(root->left);
        ResultType right = helper(root->right);
        
        int sum = left.sum + right.sum + root->val;
        int count = left.count + right.count + 1;
        ResultType newResult = ResultType(root, sum, count);

         //division -> multiply, reducing time!!!
        if (sum * maxResult.count > maxResult.sum * count) {
            maxResult = newResult;
        } 
        return newResult;
    }
    
private:
    ResultType maxResult;
};