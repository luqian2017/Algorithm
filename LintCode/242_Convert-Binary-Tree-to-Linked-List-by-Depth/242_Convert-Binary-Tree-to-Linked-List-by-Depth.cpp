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
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    /**
     * @param root the root of binary tree
     * @return a lists of linked list
     */
    vector<ListNode*> binaryTreeToLists(TreeNode* root) {
        if (!root) return vector<ListNode*>();
        queue<TreeNode *> q;
        vector<ListNode *> result;
        ListNode * listNode;
                    
        q.push(root);

        while(!q.empty()) {
            int n = q.size();
            ListNode * dummyHead = new ListNode(0);
            listNode = dummyHead;
            for (int i = 0; i < n; ++i) {
                TreeNode * treeNode = q.front();
                q.pop();
                
                listNode->next = new ListNode(treeNode->val);
                listNode = listNode->next;

                if (treeNode->left) {
                    q.push(treeNode->left);
                }
                if (treeNode->right) {
                    q.push(treeNode->right);
                }
            }

            listNode->next = NULL;

            result.push_back(dummyHead->next);
        }
        return result;
    }
};