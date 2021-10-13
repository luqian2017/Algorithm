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
    int rangeSumBST(TreeNode* root, int low, int high) {
        if (!root) return 0;
        return inOrderTravel(root, low, high);
    }
private:
    int inOrderTravel(TreeNode *root, int L, int R) {
        if (!root) return 0;
        int sum = 0;
        TreeNode *dummyRoot = new TreeNode(0);
        dummyRoot->right = root;
        stack<TreeNode *> stk;
        stk.push(dummyRoot);
        while (!stk.empty()) {
            TreeNode *node = stk.top();
            stk.pop();
            if (node->right) {
                node = node->right;
                while (node) {
                    stk.push(node);
                    if (node->left) node = node->left;
                }
            }

            if (!stk.empty()) {
                //if (node->val >= L && node->val <= R) sum += node->val; 
                if (node->val >= L && node->val <= R) sum += stk.top()->val; 
                else if (node->val > R) break;
            }
        }
        return sum;        
    }
};