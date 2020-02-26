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
     * @return: a ListNode
     */
    ListNode * swapPairs(ListNode * head) {
        ListNode * dummy = new ListNode(0);
        dummy->next = head;
        head = dummy;
        while(head->next && head->next->next) {
            ListNode * p1 = head->next;
            ListNode * p2 = head->next->next;
            head->next = p2;
            p1->next = p2->next;
            p2->next = p1;
            head = p1;
        }
        return dummy->next;
    }
};