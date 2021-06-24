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

struct Context {
    TreeNode* node;
    int step;
    Context(TreeNode* _node = NULL, int _step = 0) : node(_node), step(_step) {}
};

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<Context> s;
        s.push_back(Context(root, 0));
        vector<int> res;
        while (!s.empty()) {
            if (s.back().node == NULL) {
                //root为空，直接返回
                s.pop_back();
            } else if (s.back().step == 0) {
                s.back().step = 1;
                s.push_back(Context(s.back().node->left, 0));
            } else if (s.back().step == 1) {
                s.back().step = 2;
                s.push_back(Context(s.back().node->right, 0));
            } else if (s.back().step == 2) {
                s.back().step = 3;
                res.push_back(s.back().node->val);
            } else {
                s.pop_back();
            }
        }
        return res;  
    }
};