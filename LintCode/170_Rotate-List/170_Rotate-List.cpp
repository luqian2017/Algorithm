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
     * @param head: the List
     * @param k: rotate to the right k places
     * @return: the list after rotation
     */
    ListNode * rotateRight(ListNode * head, int k) {
        if (!head || k == 0) return head;
        
        int len = 1;
        ListNode * p = head, * tail = NULL;
        while(p->next) {
            len++;
            p = p->next;
        }
        k %= len;
        if (k == 0) return head;
        
        tail = p;
        k = len - k;
        p = head;
        for (int i = 0; i < k - 1; ++i) {
            p = p->next;
        }

        ListNode * newHead = p->next;
        p->next = NULL;
        tail->next = head;
        return newHead;
    }
};