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
     * @param head: head is the head of the linked list
     * @return: head of linked list
     */
    ListNode * deleteDuplicates(ListNode * head) {
        if (!head) return NULL;
        
        ListNode * p = head;
        while(p && p->next) {
            while (p->next && p->val == p->next->val) {
                ListNode * tempNode = p->next;
                p->next = p->next->next;
                tempNode->next = NULL;
            }
            p = p->next;
        }
        
        return head;
    }
};