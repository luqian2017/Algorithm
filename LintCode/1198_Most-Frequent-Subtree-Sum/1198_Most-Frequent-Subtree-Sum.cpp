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
     * @param root: the root
     * @return: all the values with the highest frequency in any order
     */
    vector<int> findFrequentTreeSum(TreeNode * root) {
        if (!root) return vector<int>();
        helper(root);
        vector<int> result;
        
        int maxFreq = 0;
        set<int> s;  //remove duplicate sums such as {0, -1} has two {-2}, but only return one {-1}
        for (auto m : mp) {
            int sum = m.first;
            if (maxFreq < mp.count(sum)) {
                s.clear();
                maxFreq = mp.count(sum);
                s.insert(sum);
            } else if (maxFreq == mp.count(sum)) {
                s.insert(sum);   
            }
        }
        
        for (auto i : s) result.push_back(i);
        return result;
    }
    
    int helper(TreeNode * root) {
        if (!root) return 0;
        int sum = helper(root->left) + helper(root->right) + root->val;
        mp.insert(make_pair(sum, root));
        return sum;
    }
    
private:
    multimap<int, TreeNode *> mp; //<sum, node *>
};