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
 * Example of iterate a tree:
 * BSTIterator iterator = BSTIterator(root);
 * while (iterator.hasNext()) {
 *    TreeNode * node = iterator.next();
 *    do something for node
 */


class BSTIterator {
public:
    /*
    * @param root: The root of binary tree.
    */
    BSTIterator(TreeNode * root) {
        while(root) {
            s.push(root);
            root=root->left;
        }
    }

    /*
     * @return: True if there has next node, or false
     */
    bool hasNext() {
        return !s.empty();
    }

    /*
     * @return: return next node
     */
    TreeNode * next() {
        TreeNode* node = s.top();
        TreeNode* retNode = node;

        if (node->right) {
            node = node->right;
            while (node) {
                s.push(node);
                node = node->left;
            }
        } else {
            node = s.top();
            s.pop();
            while(!s.empty() && s.top()->right == node) {
                node = s.top();
                s.pop();
            }
        }

        return retNode;
    }

private:
    stack<TreeNode*> s;
};