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
 
struct ResultType {
    TreeNode * node;
    int depth;
    ResultType(TreeNode * _node = NULL, int _depth = 0) : node(_node), depth(_depth) {}
};

class Solution {
public:
    /**
     * @param root: the root
     * @param k: an integer
     * @return: the value of the nearest leaf node to target k in the tree
     */
    int findClosestLeaf(TreeNode * root, int k) {
        int depth = 0;
        ResultType res, res1, res2, res3;
        map<TreeNode *, TreeNode *> mp;
        res = findK(root, k, depth, mp);
        TreeNode *nodeK = res.node;
        int pri1Len = INT_MAX, pri2Len = INT_MAX, pri3Len = INT_MAX;
        
        if (nodeK->left) {
            res1 = closestLeafDepth(nodeK->left, 1);
            if (res1.node) pri1Len = res1.depth;
        }
        
        if (nodeK->right) {
            res2 = closestLeafDepth(nodeK->right, 1);
            if (res2.node) pri2Len = res2.depth;
        }
        
        int count = 0;
        TreeNode * node = nodeK;
        int saveRecord = 0;
        while (1) {
            res3 = closestLeafDepth(node, 0);
            if (res3.node) {
                if (res3.depth + count < pri3Len) {
                    pri3Len = res3.depth + count;
                    saveRecord = res3.node->val;
                }
            }
            if (mp.find(node) != mp.end()) {
                node = mp[node];
                count++;
            }
            else break;
        }
            
        int minLen = min(min(pri1Len, pri2Len), pri3Len);
        if (minLen == pri1Len) return res1.node->val;
        if (minLen == pri2Len) return res2.node->val;
        return saveRecord;
    }

private:
    ResultType findK(TreeNode * root, int k, int depth, map<TreeNode *, TreeNode *> &mp) {
        ResultType res;
        if (!root) return res;
        
        if (root->val == k) {
            return ResultType(root, depth);
        }
        
        if (root->left) {
            mp[root->left] = root;
            res = findK(root->left, k, depth + 1, mp);
            if (res.node) {
                return res;
            }
        }
        if (root->right) {
            mp[root->right] = root;
            res = findK(root->right, k, depth + 1, mp);
            if (res.node) return res;
        }
        return NULL;
    }

    ResultType closestLeafDepth(TreeNode * node, int depth) {
        if (!node->left && !node->right) return ResultType(node, depth);
        if (!node->left) return closestLeafDepth(node->right, depth + 1);
        if (!node->right) return closestLeafDepth(node->left, depth + 1);
        ResultType leftRes = closestLeafDepth(node->left, depth + 1);
        ResultType rightRes = closestLeafDepth(node->right, depth + 1);
        if (leftRes.depth <= rightRes.depth) return leftRes;
        else return rightRes;
    }
};