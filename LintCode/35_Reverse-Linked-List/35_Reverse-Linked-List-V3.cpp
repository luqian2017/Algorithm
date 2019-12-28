/**
 * Definition of singly-linked-list:
 *
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *        this->val = val;
 *        this->next = NULL;
 *     }
 * }
 */

class Solution {
public:
    /**
     * @param head: n
     * @return: The new head of reversed linked list.
     */
    ListNode * reverse(ListNode * head) {
        if (!head || !head->next) return head;
        ListNode * node = reverse(head->next);
        head->next->next = head;
        head->next = NULL;
        return node;
    }
};