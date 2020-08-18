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
     * @param A: Given an integer array with no duplicates.
     * @return: The root of max tree.
     */
    TreeNode * maxTree(vector<int> &A) {
        int n = A.size();
        vector<TreeNode* > stk;
        for (int i = 0; i < n; ++i) {
            TreeNode* tmpNode = new TreeNode(A[i]);
            while(stk.size() > 0 && A[i] > stk.back()->val) { //如果stk中的最后一个节点比新节点小
                tmpNode->left = stk.back(); //当前新节点的左子树为stk的最后一个节点
                stk.pop_back();
            }
            if (stk.size() > 0) { //如果stk不为空
                stk.back()->right = tmpNode; //将新节点设为stk最后一个节点的右子树
            }
            stk.push_back(tmpNode);
        }
    
        return stk[0];
    }
};