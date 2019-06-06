/**
 * Definition of ListNode
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *         this->val = val;
 *         this->next = NULL;
 *     }
 * }
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
    /*
     * @param head: The first node of linked list.
     * @return: a tree node
     */
    TreeNode * sortedListToBST(ListNode * head) {
        if (!head) return NULL;
        
        return helper(head);
    }
    
private:
    TreeNode * helper(ListNode * head) {
        if (!head) return NULL;
        if (!head->next) return new TreeNode(head->val);
        
        ListNode * p1 = head, * p2 = head, * pre = head;

        while(p2 && p2->next) {
            pre = p1;
            p1 = p1->next;
            p2 = p2->next->next;
            
        }
        //now p1 is the mid of the list;
        TreeNode * mid = new TreeNode(p1->val);
        pre->next = NULL;
        mid->left = helper(head);
        mid->right = helper(p1->next);

        return mid;
    }
};