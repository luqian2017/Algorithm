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
     * @param l1: the first list
     * @param l2: the second list
     * @return: the sum list of l1 and l2 
     */
    ListNode * addLists(ListNode * l1, ListNode * l2) {
        ListNode * node = new ListNode(0);
        ListNode * dummyHead = node;
        int carry = 0;
        while(l1 && l2) {
            ListNode *temp;
            int sum = l1->val + l2->val + carry;
            if (sum >= 10) {
                carry = 1;
                temp = new ListNode(sum % 10);
            } else {
                carry = 0;
                temp = new ListNode(sum);
            }
            node->next = temp;
            node = node->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        
        ListNode *l;
        if (l1) l = l1;
        else if (l2) l = l2;
        else {
            if (carry) node->next = new ListNode(1);
            return dummyHead->next;
        }

        while (l) {
            ListNode *temp;
            int sum = l->val + carry;
            if (sum >= 10) {
                carry = 1;
                temp = new ListNode (sum % 10);
            } else {
                carry = 0;
                temp = new ListNode (sum);
            }
            node->next = temp;
            node = node->next;
            l = l->next;
        }
        
        if (carry) node->next = new ListNode(1);
        
        return dummyHead->next;
    }
};