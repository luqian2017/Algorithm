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
     * @return: You should return the head of the sorted linked list, using constant space complexity.
     */
    ListNode * sortList(ListNode * head) {
        if (!head || !head->next) return head;
        
        ListNode * mid = findMiddle(head);
        ListNode * rightHead = sortList(mid->next);
        mid->next = NULL;
        ListNode * leftHead = sortList(head);
        
        return merge(leftHead, rightHead);
    }

private:
    ListNode * findMiddle(ListNode * head) {
        ListNode * slow = head, * fast = head->next;
        while(fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
    
    ListNode * merge(ListNode * head1, ListNode * head2) {
        ListNode * dummy = new ListNode(0);
        ListNode * p = dummy;
        
        while(head1 && head2) {
            if (head1->val < head2->val) {
                p->next = head1;
                head1 = head1->next;
            } else {
                p->next = head2;
                head2 = head2->next;
            }
            p = p->next;
        }
        
        if (head1) {
            p->next = head1;
        } else {
            p->next = head2;
        }
        
        return dummy->next;
    }
};