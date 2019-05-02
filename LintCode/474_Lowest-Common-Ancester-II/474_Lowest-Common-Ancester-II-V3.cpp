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
        
        while(tempA || tempB) {
            if (tempA && s.find(tempA) != s.end()) return tempA;
            s.insert(tempA);
            if (tempB && s.find(tempB) != s.end()) return tempB;
            s.insert(tempB);
            
            tempA = tempA->parent;
            tempB = tempB->parent;
        }
        
       // return root;
    }
};