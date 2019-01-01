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
     * @param t: the root of tree
     * @return: return a string
     */
    string tree2str(TreeNode * t) {
        string result;
        helper(t, result);
        return result;
    }
    
    void helper(TreeNode * node, string & s) {
        if (node) {
            string s1;
            helper(node->left, s1);
            string s2;
            helper(node->right, s2);
            
            if ((s1.size() == 0) && (s2.size() == 0))
                s += to_string(node->val);
            else if ((s1.size() != 0) && (s2.size() == 0))
                s += to_string(node->val) + '(' + s1 + ')';
           // else if ((s1.size() == 0) && (s2.size() != 0))
           //   s += to_string(node->val) + '(' + s2 + ')';
            else    
                s += to_string(node->val) + '(' + s1 + ')' + '(' + s2 + ')';
        } 
    }
};