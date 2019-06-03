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
        
        ListNode *dummyHead = new ListNode(0);
        dummyHead->next = head;
        ListNode * pre = dummyHead; //pre of the 1st node >= x
        
        while(pre->next) {
            if (pre->next->val >= x) {
                break;
            }
            pre = pre->next;    
        }
        ListNode * p1 = pre, * p2 = pre;//->next;
        while(p2->next) {
            if (p2->next->val < x) {
                ListNode * temp = p2->next;
                p2->next = temp->next;
                temp->next = p1->next;
                p1->next = temp;
                p1 = p1->next;
            } else {
                p2 = p2->next;
            }
        }
        
        return dummyHead->next;
    }
};