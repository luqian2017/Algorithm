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
     * @param root: the root of binary tree
     * @return: the root of the minimum subtree
     */
    TreeNode * findSubtree(TreeNode * root) {
        if (!root) return NULL;
        int sumLeft = sumSubTree(root->left);
        int sumRight = sumSubTree(root->right);
        int sumAll = sumLeft + sumRight + root->val;
        int minChildSum;
        if (!root->left) 
            minChildSum = sumRight;
        else if (!root->right) 
            minChildSum = sumLeft;
        else 
            minChildSum = min(sumLeft, sumRight);

        if (sumAll < minValue) {
            minValue = sumAll;
            recordNode = root;
        } else if (minChildSum < minValue) {
            minValue = minChildSum;
            recordNode = (sumLeft< sumRight)? root->left : root->right; 
        }

        return recordNode;
    }

private:
    int sumSubTree(TreeNode * root) {
        if (!root) 
            return 0;
        else {
            int sum = sumSubTree(root->left) + sumSubTree(root->right) + root->val; 
            if (sum < minValue) {
                minValue = sum;
                recordNode = root;
            }
            return sum;  
        }
    }

    int minValue=INT_MAX;
    TreeNode *recordNode;
};