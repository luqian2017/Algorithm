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
     * @param head: ListNode head is the head of the linked list 
     * @param m: An integer
     * @param n: An integer
     * @return: The head of the reversed ListNode
     */
    ListNode * reverseBetween(ListNode * head, int m, int n) {
        if (!head || (m >= n)) return head;
           
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        head = dummy;
        
        //get the m-1 th node
        for (int i = 1; i < m; ++i) {
            head = head->next;
        } 
        
        ListNode *prev = head->next; //the mth node
        ListNode *cur = head->next; //the m+1 th node
        
        for (int i = m; i <= n; ++i) {
            ListNode *temp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = temp;
        }
        
        head->next->next = cur;
        head->next = prev;
        head = dummy->next;
        delete dummy;
        return head;

    }
};