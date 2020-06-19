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
     * @param s: the s' root
     * @param t: the t' root
     * @return: whether tree t has exactly the same structure and node values with a subtree of s
     */
    bool isSubtree(TreeNode * s, TreeNode * t) {
        if (!s) return false;
        if (compare(s, t)) {
            return true;
        } else {
            return isSubtree(s->left, t) || isSubtree(s->right, t);
        }
    }

private:
    bool compare(TreeNode * s, TreeNode * t) {
        if (!s && !t) return true;
        if (!s || !t) return false;
        if (s->val != t->val) return false;
        if (s->val == t->val) {
            return compare(s->left, t->left) && compare(s->right, t->right);
        }
    }
};