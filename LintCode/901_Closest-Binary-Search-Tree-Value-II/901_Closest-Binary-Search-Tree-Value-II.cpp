
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
     * @param root: the given BST
     * @param target: the given target
     * @param k: the given k
     * @return: k values in the BST that are closest to the target
     */
    vector<int> closestKValues(TreeNode * root, double target, int k) {
        vector<int> nums = inOrderTraversal(root);

        int i = 0, j = nums.size()-1;

        while(j - i > k - 1) {
            if (abs(nums[i] - target) <= abs(nums[j] - target)) {
                j--;
            } else {
                i++;
            }
        }

        vector<int> result;
        for (int m = i; m <= j; m++) {
            result.push_back(nums[m]);
        }

        return result;
    }

private:
    vector<int> inOrderTraversal(TreeNode *root) {
        stack<TreeNode *> s;
        vector<int> result;

        while(root) {
            s.push(root);
            root=root->left;
        }

        while(!s.empty()) {
            TreeNode* node = s.top();
            result.push_back(node->val);

            if (node->right) {
                node = node->right;
                while(node) { 
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
        }

        return result;        
    }
};