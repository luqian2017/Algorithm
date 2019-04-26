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
     * @param root: A Tree
     * @return: Preorder in ArrayList which contains node values.
     */
    vector<int> preorderTraversal(TreeNode * root) {
        if (!root) return vector<int>();
        stack<TreeNode *> s;
        vector<int> result;
        
        s.push(root);
        while(!s.empty()) {
            TreeNode * current = s.top();
            result.push_back(current->val);
            s.pop();
            if (current->right) {
                s.push(current->right);
            }
            if (current->left) {
                s.push(current->left);
            }
        }
        return result;
    }
};