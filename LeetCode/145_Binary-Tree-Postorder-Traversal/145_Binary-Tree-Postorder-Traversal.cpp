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
                //对标dfs函数中第一行，root为空，直接返回
                s.pop_back();
            } else if (s.back().step == 0) {
                //处于第一个阶段中
                s.back().step++;
                s.push_back(Context(s.back().node->left, 0));
            } else if (s.back().step == 1) {
                //处于第二个阶段
                s.back().step++;
                s.push_back(Context(s.back().node->right, 0));
            } else {
                //处于第三个阶段
                res.push_back(s.back().node->val);
                s.pop_back();
            }
        }
        return res;  
    }
};