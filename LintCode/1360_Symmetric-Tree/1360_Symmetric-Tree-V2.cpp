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
    * @param root: root of the given tree
    * @return: whether it is a mirror of itself
    */
    bool isSymmetric(TreeNode * root) {
        if (!root) return true;
        
        queue<TreeNode *> q;
        q.push(root);
        q.push(root);
        
        while(!q.empty()) {
            TreeNode *p1 = q.front();
            q.pop();
            TreeNode *p2 = q.front();
            q.pop();
            if (p1->val != p2->val) return false;

            if (p1->left && p2->right) {
                q.push(p1->left);
                q.push(p2->right);
            } else if (p1->left || p2->right) 
                return false;

            if (p1->right && p2->left) {
                q.push(p1->right);
                q.push(p2->left);
            } else if (p1->right || p2->left) 
                return false;
        }
        
        return true;
    }
};
