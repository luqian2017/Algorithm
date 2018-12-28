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
        if (!root) return result;
        
        stack<TreeNode *> s;
        TreeNode * cur;
        TreeNode * pre;
        
        s.push(root);
        
        while(!s.empty()) {
            cur = s.top();
            
            if ((!cur->left && !cur->right) ||
                (pre && ((pre == cur->left) || (pre == cur->right)))) {
                s.pop();
                result.push_back(cur->val);
                pre = cur;
            } else {
                if (cur->right)
                    s.push(cur->right);
                if (cur->left)
                    s.push(cur->left);
                
            }
        }
        
        return result;        
    }
};