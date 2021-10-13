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
     * @param root: root of a tree
     * @return: head node of a doubly linked list
     */
    TreeNode * treeToDoublyList(TreeNode * root) {
        inOrderTravel(root);
        pre->right = head;
        head->left = pre;
        return head;
    }
private:
    void inOrderTravel(TreeNode * root) {
        if (!root) return;
        inOrderTravel(root->left);
        if (!pre) {
            pre = root;
            head = root;
        } else {
            pre->right = root;
            root->left = pre;
            pre = root;
        }
        inOrderTravel(root->right);
    }
    TreeNode *pre = NULL, *head = NULL;
    
};