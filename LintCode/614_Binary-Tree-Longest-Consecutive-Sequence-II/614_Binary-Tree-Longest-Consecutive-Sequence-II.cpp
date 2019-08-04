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
struct DataType {
    int leftIncLen;
    int leftDecLen;
    int rightIncLen;
    int rightDecLen;
    
    DataType(int lIL = 0, int lDL = 0, int rIL = 0, int rDL = 0) : leftIncLen(lIL), leftDecLen(lDL), rightIncLen(rIL), rightDecLen(rDL) {};
};

class Solution {
public:
    /**
     * @param root: the root of binary tree
     * @return: the length of the longest consecutive sequence path
     */
    int longestConsecutive2(TreeNode * root) {
        maxTotalLength = 0;
        dfs(root);
        return maxTotalLength;
    }
private:
    DataType dfs(TreeNode * root) {
        if (!root) return DataType(0, 0, 0, 0);
        cout<<root->val<<endl;
        DataType result(1,1,1,1);

        if (!root->left && !root->right) {
            maxTotalLength = max(maxTotalLength, 1);
            return DataType(1, 1, 1, 1);
        }

        DataType resultLeft = dfs(root->left);
        DataType resultRight = dfs(root->right);

        if (root->left && root->val == root->left->val - 1) {
            result.leftDecLen = max(resultLeft.leftDecLen, resultLeft.rightDecLen) + 1;
        } else if (root->left && root->val == root->left->val + 1) {
            result.leftIncLen = max(resultLeft.leftIncLen, resultLeft.rightIncLen) + 1;
        }

        if (root->right && root->val == root->right->val - 1) {
            result.rightDecLen = max(resultRight.rightDecLen, resultRight.leftDecLen) + 1;
        } else if (root->right && root->val == root->right->val + 1) {
            result.rightIncLen = max(resultRight.rightIncLen, resultRight.leftIncLen) + 1;
        }
 
        if (!root->left) {
            maxTotalLength = max(maxTotalLength, max(result.rightDecLen, result.rightIncLen));
        } else if (!root->right) {
            maxTotalLength = max(maxTotalLength, max(result.leftDecLen, result.leftIncLen));
        } else {
            maxTotalLength = max(
                maxTotalLength, 
                max(result.rightDecLen + result.leftIncLen, 
                    result.rightIncLen + result.leftDecLen) - 1);
        }

        return result;
    }

    int maxTotalLength;
};