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
     * @param head: The first node of linked list.
     * @param n: An integer
     * @return: The head of linked list.
     */
    ListNode * removeNthFromEnd(ListNode * head, int n) {
        if (!head) return NULL;
        if (n == 0) return NULL;
        
        ListNode *p1 = head, *p2 = head;
        for (int i = 0; i < n + 1; ++i) {
            p2 = p2->next;
            if (!p2) {
                ListNode *newHead = p1->next;
                p1->next = NULL;
                return newHead;
            }
        }

        while(p2) {
            p2 = p2->next; 
            p1 = p1->next;
        }

        ListNode *deleteP = p1->next;
        p1->next = p1->next->next;
        deleteP->next = NULL;
        
        return head;
    }
};