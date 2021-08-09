
class Solution {
public:
    /**
     * @param root: The root of binary tree.
     * @return: True if the binary tree is BST, or false
     */
    bool isValidBST(TreeNode * root) {
        if (!root) return true;
        inOrderTraversal(root);
        int len = inOrderRes.size();
        for (int i = 1; i < len; i++) {
            if (inOrderRes[i] <= inOrderRes[i - 1]) return false;
        }
        return true;        
    }
private:
    vector<int> inOrderRes;
    void inOrderTraversal(TreeNode *root) {
        if (!root) return;
        inOrderTraversal(root->left);
        inOrderRes.push_back(root->val);
        inOrderTraversal(root->right);
    }
};