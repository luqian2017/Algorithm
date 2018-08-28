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
        ReturnType ret = helper(root, A, B);
        if (ret.findA && ret.findB) 
            return ret.node;
        else
            return NULL;
    }

private:

    struct ReturnType {
        bool findA;
        bool findB;
        TreeNode* node;
        ReturnType(bool a=false, bool b=false, TreeNode* c=NULL) : findA(a), findB(b), node(c) {} 
    };

    ReturnType helper(TreeNode* root, TreeNode* A, TreeNode* B) {
        if (!root) 
            return ReturnType();

        ReturnType leftRet = helper(root->left, A, B);
        ReturnType rightRet = helper(root->right, A, B);

        bool findA = leftRet.findA || rightRet.findA || root == A;
        bool findB = leftRet.findB || rightRet.findB || root == B;

        if (A == root || B == root) {
            return ReturnType(findA, findB, root);
        }

        //now find A and find B, and we know it is not overlapping with root 
        if (leftRet.node && rightRet.node) {
            return ReturnType(true, true, root);
        }

        if (leftRet.node) {
            return ReturnType(findA, findB, leftRet.node);
        }

        if (rightRet.node) {
            return ReturnType(findA, findB, rightRet.node);    
        }

        return ReturnType(false, false, NULL);
    }

};