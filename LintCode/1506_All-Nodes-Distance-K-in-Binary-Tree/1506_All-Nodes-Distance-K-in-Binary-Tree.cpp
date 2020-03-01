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
     * @param root: the root of the tree
     * @param target: the target
     * @param K: the given K
     * @return: All Nodes Distance K in Binary Tree
     */
    vector<int> distanceK(TreeNode * root, TreeNode * target, int K) {
        vector<int> results;
        findParents(root, target);
        unordered_set<TreeNode *> visited;
        findDistKNodeFromRoot(target, K, results, visited);
      
        return results;
    }

private:
    unordered_map<TreeNode *, TreeNode *> parentMap;
    
    void findParents(TreeNode * root, TreeNode * target) {
        if (!root) return;
        if (root == target) return;
        parentMap[root->left] = root;
        parentMap[root->right] = root;
        findParents(root->left, target);
        findParents(root->right, target);
    }
    
    void findDistKNodeFromRoot(TreeNode * root, int dist, vector<int> & results, unordered_set<TreeNode *> & visited) {
        if (!root || visited.find(root) != visited.end()) return;

        if (dist == 0) {
            results.push_back(root->val);
            return;
        }
        visited.insert(root);
        findDistKNodeFromRoot(root->left, dist - 1, results, visited);
        findDistKNodeFromRoot(root->right, dist - 1, results, visited);
        findDistKNodeFromRoot(parentMap[root], dist - 1, results, visited);
    }
};