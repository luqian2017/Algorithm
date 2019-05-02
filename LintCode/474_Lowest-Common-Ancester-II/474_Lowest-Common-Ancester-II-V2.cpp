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
        if (!root) return NULL;
        if (root == A || root == B) return root;
        
        unordered_set<ParentTreeNode *> s;
        ParentTreeNode * tempA = A;
        ParentTreeNode * tempB = B;
        
        while(tempA) {
            s.insert(tempA);
            tempA = tempA->parent;
        }
        
        while (tempB) {
            if (s.find(tempB) == s.end()) {
                tempB = tempB->parent;
            } else {
                return tempB;
            }
        }
        
       // return root;
    }
};