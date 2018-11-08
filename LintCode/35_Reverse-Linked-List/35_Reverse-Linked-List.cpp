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
        ListNode *prev = NULL;
        
        while(head) {
           ListNode *temp = head->next;
           head->next = prev;
           prev = head;
           head = temp;
        }
        
        return prev;
    }
};