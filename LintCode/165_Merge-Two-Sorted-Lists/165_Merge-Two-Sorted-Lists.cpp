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
        
        ListNode * l3 = new ListNode(0);
        ListNode *dummyHead = l3;
        while (l1 && l2) {
            ListNode * node;
            if (l1->val <= l2->val) {
                l3->next = new ListNode(l1->val);
                l3 = l3->next;
                l1 = l1->next;
            } else {
                l3->next = new ListNode(l2->val);
                l3 = l3->next;
                l2 = l2->next;
            }
        }
        
        ListNode * l = l1 ? l1 : l2;
        while (l) {
            l3->next = new ListNode(l->val);
            l3 = l3->next;
            l = l->next;
        }
        
        return dummyHead->next;
    }
};