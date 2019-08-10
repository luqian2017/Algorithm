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
    /*
     * @param root: the root of binary tree
     * @return: collect and remove all leaves
     */
    vector<vector<int>> findLeaves(TreeNode * root) {
        if (!root) return result;
        result.resize(1);
        dfs(root);
        return result;
    }

private:
    int dfs(TreeNode * root) {
        
        if (!root) return 0;
       
        if (!root->left && !root->right) {
            result[0].push_back(root->val);
            return 1;
        };
        int depth = max(dfs(root->left), dfs(root->right)) + 1;
        if (depth > result.size()) result.resize(depth);
        result[depth - 1].push_back(root->val);
        return depth;
    }
    
    vector<vector<int>> result;
};


//simplified version;

class Solution {
public:
    /*
     * @param root: the root of binary tree
     * @return: collect and remove all leaves
     */
    vector<vector<int>> findLeaves(TreeNode * root) {
        if (!root) return result;
        dfs(root);
        return result;
    }

private:
    int dfs(TreeNode * root) {
        
        if (!root) return 0;
        cout<<root->val<<endl;
        int depth = max(dfs(root->left), dfs(root->right)) + 1;
        if (depth > result.size()) result.resize(depth);
        result[depth - 1].push_back(root->val);
        return depth;
    }
    
    vector<vector<int>> result;
};