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
        postOrder(root, result);
        return result;
    }
    
private:
    void postOrder(TreeNode * node, vector<int> &vec) {
        if (!node) return;
        
        postOrder(node->left, vec);
        postOrder(node->right, vec);
        vec.push_back(node->val);
    }
};