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
     * @param root: the given tree
     * @return: the tree after swapping
     */
    TreeNode * bstSwappedNode(TreeNode * root) {
        if (!root) return NULL;
        
        firstNode = NULL; secondNode = NULL; lastVisitedNode = new TreeNode(INT_MIN);   
        
        inOrderTraversal(root);
        
        if (firstNode && secondNode) swap(firstNode->val, secondNode->val);
        return root;
    }

private:
    TreeNode * firstNode, * secondNode, * lastVisitedNode;
    
    void inOrderTraversal(TreeNode * root) {
        if (!root) return;
        inOrderTraversal(root->left);
                
        if (!firstNode && root->val < lastVisitedNode->val) {
            firstNode = lastVisitedNode;
        }
        if (firstNode && root->val < lastVisitedNode->val) {
            secondNode = root;

        }
        lastVisitedNode = root;  
        
        inOrderTraversal(root->right);
    }
};