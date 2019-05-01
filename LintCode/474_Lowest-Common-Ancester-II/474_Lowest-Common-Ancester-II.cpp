/**
 * Definition of ParentTreeNode:
 * class ParentTreeNode {
 * public:
 *     int val;
 *     ParentTreeNode *parent, *left, *right;
 * }
 */


class Solution {
public:
    /*
     * @param root: The root of the tree
     * @param A: node in the tree
     * @param B: node in the tree
     * @return: The lowest common ancestor of A and B
     */
    ParentTreeNode * lowestCommonAncestorII(ParentTreeNode * root, ParentTreeNode * A, ParentTreeNode * B) {
        if (!root || root == A || root == B) return root;
        ParentTreeNode * rootLeft = lowestCommonAncestorII(root->left, A, B);
        ParentTreeNode * rootRight = lowestCommonAncestorII(root->right, A, B);
        if (rootLeft && rootRight) return root;
        if (rootLeft) return rootLeft;
        if (rootRight) return rootRight;
        return NULL;
    }
};