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
     * @param head: The head of linked list.
     * @return: nothing
     */
    void reorderList(ListNode * head) {
        if (!head || !head->next) return; 
    
        ListNode * mid = findMiddle(head);
        ListNode * rightHead = reverseList(mid->next);
        mid->next = NULL;
        
        ListNode * p = head, * pRight = rightHead;
        while(p && pRight) {
            ListNode * pNext = p->next;
            ListNode * pRightNext = pRight->next;
            
            p->next = pRight;
            pRight->next = pNext;
            
            p = pNext;
            pRight = pRightNext;
        }
        
        return;
    }
    
private:
    ListNode * findMiddle(ListNode * head) {
        ListNode * slow = head, * fast = head->next;
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    
    ListNode * reverseList(ListNode * head) {
        ListNode * pre = NULL;
        while(head) {
            ListNode * tmpNode = head->next;
            head->next = pre;
            pre = head;
            head = tmpNode;
        }
        
        return pre;
    } 
};