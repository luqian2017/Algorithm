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
     * @param head: A ListNode.
     * @return: A boolean.
     */
    bool isPalindrome(ListNode * head) {
        if (!head || !head->next) return true;
        
        int len = 0;
        ListNode * p = head;
        while(p) {
            len++;
            p = p->next;
        }
        
        //1->2->1, midIndex = 0;
        //1->2->2->1, midIndex = 1;
        int midIndex = len / 2 - 1; 
        
        stack<int> s;
        p = head;
        
        for (int i = 0; i <= midIndex; ++i) {
            s.push(p->val);
            p = p->next;
        }
        if (len & 0x1) p = p->next; //1->2->1, p points to the 2nd 1
 
        while(p) {
            if (p->val == s.top()) {
                p = p->next;
                s.pop();
            } else {
                return false;
            }
        }

        return true;
    }
};