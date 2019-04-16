/**
 * Definition of singly-linked-list:
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
     * @param head: the head of linked list.
     * @return: a middle node of the linked list
     */
    ListNode * middleNode(ListNode * head) {
        if (!head) return NULL;
        if (!head->next || !head->next->next) return head;
    
        ListNode *p1 = head, *p2 = head;
        while(p2->next && p2->next->next) {
            p2 = p2->next->next;
            p1 = p1->next;
        }
        return p1;
    }
};