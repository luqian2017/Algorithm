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
     * @param root: param root: The root of the binary search tree
     * @param k1: An integer
     * @param k2: An integer
     * @return: return: Return all keys that k1<=key<=k2 in ascending order
     */
    vector<int> searchRange(TreeNode * root, int k1, int k2) {
        if (!root || k1 > k2) return vector<int>();
        inOrderTraversal(root);
        int n = inOrderList.size();
  
        vector<int> result;
        
        int low = lower_bound(inOrderList.begin(), inOrderList.end(), k1) - inOrderList.begin();

        if (low >= n) return vector<int>();
        
        int up = upper_bound(inOrderList.begin(), inOrderList.end(), k2) - inOrderList.begin();
        if (up > n) return vector<int>();
        
        for (int i = low; i < up; ++i) {
            result.push_back(inOrderList[i]);
        }
        return result;
    }

private:
    void inOrderTraversal(TreeNode * root) {
        if (!root) return;
        inOrderTraversal(root->left);
        inOrderList.push_back(root->val);
        inOrderTraversal(root->right);
    }
    
    vector<int> inOrderList;
};