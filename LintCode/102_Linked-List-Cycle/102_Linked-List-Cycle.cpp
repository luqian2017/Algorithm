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
     * @return: True if it has a cycle, or false
     */
    bool hasCycle(ListNode * head) {
        if (!head) return false;
        ListNode *p1 = head, *p2 = p1->next;
        //p1 increase one each step, p2 increase two each step
        while(p2) {
            if (p2 == p1) return true;
            if (p2->next && p2->next->next) {
                p2 = p2->next->next;
                p1 = p1->next;
            } else {
                return false;
            }
        }
     
     
        return false;   
    }
};