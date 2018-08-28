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
     * @param k: the given k
     * @return: the kth smallest element in BST
     */
    int kthSmallest(TreeNode * root, int k) {
        vector<int> inOrderList;
        inOrderTraversal(root, inOrderList);
        return inOrderList[k-1];
    }

    void inOrderTraversal(TreeNode *root, vector<int> &inOrderList) {
        if (!root) 
            return;
        inOrderTraversal(root->left, inOrderList);
        inOrderList.push_back(root->val);
        inOrderTraversal(root->right, inOrderList);
    }
};
