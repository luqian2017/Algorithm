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
     * @param head: The first node of linked list
     * @param x: An integer
     * @return: A ListNode
     */
    ListNode * partition(ListNode * head, int x) {
        if (!head || !head->next) return head;
        
        ListNode * p = head;
        ListNode * p1 = new ListNode(0); // >=x
        ListNode * p2 = new ListNode(0); // <x
        ListNode * dummyHead_1 = p1;
        ListNode * dummyHead_2 = p2;
 
        while(p) {
            if (p->val >= x) {
                p1->next = new ListNode(p->val);
                p1 = p1->next;
            } else {
                p2->next = new ListNode(p->val);
                p2 = p2->next;
            }
            p = p->next;
        }
        
        p2->next = dummyHead_1->next;
        return dummyHead_2->next;
    }
};