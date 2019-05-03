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
     * @param p: the given node
     * @return: the in-order predecessor of the given node in the BST
     */
    TreeNode * inorderPredecessor(TreeNode * root, TreeNode * p) {
        if (!root) return NULL;
        
        lastVisted = NULL; predecessorNode = NULL;
        
        inOrderTraversal(root, p);
        return predecessorNode;
    }
    
private:
    TreeNode * lastVisted;
    TreeNode * predecessorNode;
    
    void inOrderTraversal(TreeNode * root, TreeNode * p) {
        if (!root || predecessorNode) return;

        inOrderTraversal(root->left, p);
    
        if (root == p) {
            predecessorNode = lastVisted;
        } else {
            lastVisted = root;
        }

        inOrderTraversal(root->right, p);
    }
    
};