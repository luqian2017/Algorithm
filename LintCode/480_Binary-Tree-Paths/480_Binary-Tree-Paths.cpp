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
     * @param root: the root of the binary tree
     * @return: all root-to-leaf paths
     */
    vector<string> binaryTreePaths(TreeNode * root) {
        vector<string> result;
        if (!root) return result;
        string path;
        findPath(root, path, result);
        return result;
    }

private:
    void findPath(TreeNode *root, string & path, vector<string> & result) {
        if (root && !root->left && !root->right) { 
            result.push_back(path+to_string(root->val));    
        } else {
            string tempStr=path + to_string(root->val) + "->";
            if (root->left) 
                findPath(root->left, tempStr, result);
            if (root->right)
                findPath(root->right, tempStr, result);
         }
    }
};