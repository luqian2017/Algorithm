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
     * @paramn n: An integer
     * @return: A list of root
     */
    vector<TreeNode *> generateTrees(int n) {
        return helper(1, n);
    }

private:
    vector<TreeNode *> helper(int begin, int end) {
        if (begin > end) return vector<TreeNode *>{NULL};
        
        vector<TreeNode *> result;
        
        for (int i = begin; i <= end; ++i) {
            vector<TreeNode *> leftTree = helper(begin, i - 1);
            vector<TreeNode *> rightTree = helper(i + 1, end);
            for (int j = 0; j < leftTree.size(); ++j) {
                for (int k = 0; k < rightTree.size(); ++k) {
                    TreeNode * node = new TreeNode(i);
                    node->left = leftTree[j];
                    node->right = rightTree[k];
                    result.push_back(node);
                }
            }
        }
        
        return result;
    }
};