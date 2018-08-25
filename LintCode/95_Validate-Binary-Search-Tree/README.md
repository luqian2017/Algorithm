首先要注意的是BST的定义： 
1) root的值要大于所有左子树的节点的值，小于所有右子树节点的值。所以不能单单和左子节点与右子节点比较。 
像下面这个代码就不会通过这个测试用例： 
10,5,15,#,#,6,20 
因为该例并非BST (10>6)。

    bool isValidBST(TreeNode * root) {
        if (!root)
            return true;

        if (root && !root->left && !root->right) 
            return true;

        return isValidBST(root->left) && 
                isValidBST(root->right) && 
               (root->left ? root->val > root->left->val : true) &&
               (root->right ? root->val < root->right->val : true);
    }

2) helper()函数会返回该root所代表的子树里面的最大值和最小值。左右子树的最大值和最小值都要考虑。 
考虑 
3) min, max 还要考虑root本身的值。

我最开始的代码如下，效率非常低。
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
     * @param root: The root of binary tree.
     * @return: True if the binary tree is BST, or false
     */
    bool isValidBST(TreeNode * root) {
        if (!root)
            return true;

        if (root && !root->left && !root->right) 
            return true;

        ReturnType leftRet = helper(root->left);
        ReturnType rightRet = helper(root->right);

        return isValidBST(root->left) && 
               isValidBST(root->right) && 
               (root->left ? root->val > leftRet.max : true) &&
               (root->right ? root->val < rightRet.min : true);
    }

private:
    struct ReturnType {
        int max;
        int min;
        ReturnType(int a=INT_MIN, int b=INT_MAX) : max(a), min(b) {}
    };

    ReturnType helper(TreeNode* root) {
        ReturnType ret;

        if (!root) 
            return ret;

        if (root && !root->left && !root->right) 
            return ReturnType(root->val, root->val);

        ReturnType leftRet = helper(root->left);
        ReturnType rightRet= helper(root->right);

        ret.max = max(root->val, max(ret.max, max(leftRet.max, rightRet.max)));
        ret.min = min(root->val, min(ret.min, min(leftRet.min, rightRet.min)));

        return ret;
    }
};

效率低的原因是做了很多无用功。.cpp里面的代码效率高些。

这个链接有两个version值得好好研究。下次学习。 
https://www.jiuzhang.com/solution/validate-binary-search-tree/#tag-highlight-lang-cpp

另外，这个链接关于LCA的讨论好像很不错，下次参考。 
https://www.hrwhisper.me/algorithm-lowest-common-ancestor-of-a-binary-tree/
