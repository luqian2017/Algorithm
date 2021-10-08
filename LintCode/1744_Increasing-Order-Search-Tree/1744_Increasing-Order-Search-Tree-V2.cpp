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
     * @param root: a binary search tree
     * @return: Root of a tree
     */
    TreeNode * increasingBST(TreeNode * root) {
        TreeNode * dummyRoot = new TreeNode(0);
        dummyRoot->right = root;
        currNode = dummyRoot;
        inOrderTravel(dummyRoot);
        return dummyRoot->right;
    }
private:
    void inOrderTravel(TreeNode * node) {
        if (!node) return;
        stack<TreeNode *> stk;
        stk.push(node);

        while (!stk.empty()) {
            node = stk.top();
            stk.pop();
        
            if (node->right) {
                node = node->right;
                while (node) {
                    stk.push(node);
                    node = node->left;
                }
            }
            
            if (!stk.empty()) {
                currNode->right = stk.top();
                currNode = stk.top();
            }
           
        }
    }
    TreeNode * currNode;
};