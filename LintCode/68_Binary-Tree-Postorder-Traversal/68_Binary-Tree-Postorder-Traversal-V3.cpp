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
        
        while(current || !s.empty()) {
            while(current) {
                s.push(current);
                current = current->left;
            }
            
            current = s.top();
            
            if (!current->right || current->right == lastVisited) {
                s.pop();
                result.push_back(current->val);
                lastVisited = current;
                current = NULL;
            } else {
                current = current->right;
            }
        }
        return result;
    }
};