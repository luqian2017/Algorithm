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
     * @param head: a ListNode
     * @param k: An integer
     * @return: a ListNode
     */
    ListNode * reverseKGroup(ListNode * head, int k) {
        if (!head) return NULL;
        int count = 0;
        ListNode * prev = NULL, * oldPrev = NULL;
        ListNode * pEndNode = head;
        bool enoughNodes = true;
        ListNode * newHead = NULL;
        while(enoughNodes) {
            count = 0;
            while(count < k) {
                if (!pEndNode) {
                    if (count != k) enoughNodes = false;
                    break;
                } else {
                    pEndNode = pEndNode->next;
                    count++;    
                }
            }
            if (enoughNodes) {
                ListNode *oldHead = head;
                ListNode * temp = NULL;
                while(head && head != pEndNode) {
                    temp = head->next;
                    head->next = prev;
                    prev = head;
                    head = temp;
                }

                if (!newHead) newHead = prev;

                oldHead->next = head;

                if (!oldPrev) { 
                    oldPrev = oldHead;
                } else {
                    oldPrev->next = prev;
                    oldPrev = oldHead;
                }
                prev = oldHead;
            }
        }
        
        return newHead;
    }
};