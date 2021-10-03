/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        TreeNode *dummyNode = new TreeNode(0, NULL, root);
        stack<TreeNode *> stk;
        stk.push(dummyNode);
        while (!stk.empty()) {
            TreeNode *node = stk.top();
            stk.pop();
            if (node->right) {
                node = node->right;
                while (node) {
                    stk.push(node);
                    node = node->left;
                }
            }
            if (!stk.empty()) res.push_back(stk.top()->val);
        }
        
        delete dummyNode;
        return res;
    }
};