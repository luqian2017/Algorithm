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
     * @param root: the given BST
     * @param target: the given target
     * @return: the value in the BST that is closest to the target
     */
    int closestValue(TreeNode * root, double target) {
        if (!root) return 0;
        minGap = (double)INT_MAX;
        result = root->val;
        inOrderTraversal(root, target);
        return result;
    }

private:
    void inOrderTraversal(TreeNode * root, double target) {
        if (!root) return;
        inOrderTraversal(root->left, target);
        double gap = abs((double)root->val - target);
        if (gap < minGap) {
            minGap = gap;
            result = root->val;
        }
        inOrderTraversal(root->right, target)
;    }
    
    int result;
    double minGap;
};