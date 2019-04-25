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
     * @return: Postorder in ArrayList which contains node values.
     */
    vector<int> postorderTraversal(TreeNode * root) {
        vector<int> result;
        stack<TreeNode *> s;
        
        TreeNode * current = root, * lastVisited = NULL;
        
        if (!root) return vector<int>();
        
        s.push(root);
        
        while(!s.empty()) {
            current = s.top();
            if (!lastVisited || current == lastVisited->left || current == lastVisited->right) {
                if (current->left) {
                    s.push(current->left);
                } else if (current->right) { //note! the else is needed here!!!
                    s.push(current->right);
                }
            } else if (current->left == lastVisited) {
                if (current->right) {
                    s.push(current->right);
                }
            } else {
                result.push_back(current->val);
                s.pop();
            }   
            
            lastVisited = current;
        }
        
        return result;
    }
};