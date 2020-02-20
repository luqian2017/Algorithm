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
     * @param l1: ListNode l1 is the head of the linked list
     * @param l2: ListNode l2 is the head of the linked list
     * @return: ListNode head of linked list
     */
    ListNode * mergeTwoLists(ListNode * l1, ListNode * l2) {
        if (!l1) return l2;
        if (!l2) return l1;
        ListNode *p1 = l1, *p2 = l2;
        
        ListNode *head = new ListNode(0); //dummy head
        ListNode *p = head;
        while(p1 && p2) {
            if (p1->val < p2->val) {
                p->next = p1;
                p = p->next;
                p1 = p1->next;
            } else {
                p->next = p2;
                p = p->next;
                p2 = p2->next;
            }
        }
        if (p1) {
            p->next = p1;
        } else if (p2) {
            p->next = p2;
        }
        
        return head->next;
    }
};