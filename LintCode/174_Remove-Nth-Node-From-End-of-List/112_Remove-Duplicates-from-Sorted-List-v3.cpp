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
        if (head == NULL) return NULL;
        if (n == 0) return head;
        
        ListNode *p1 = head, *p2 = head; //->next;
        for (int i = 0; i <= n; ++i) {
            if (p2 == NULL) {
                ListNode *newHead = head->next;
                free(head); head = NULL;
                return newHead;
            }
            p2 = p2->next;
        }

        while (p2 != NULL) {
            p1 = p1->next;
            p2 = p2->next;
        }
        
        ListNode *temp = p1->next;
        p1->next = p1->next->next;
        free(temp); temp = NULL;
        
        return head;
    }
};