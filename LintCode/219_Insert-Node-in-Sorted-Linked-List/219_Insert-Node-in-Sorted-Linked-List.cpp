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
     * @param val: An integer.
     * @return: The head of new linked list.
     */
    ListNode * insertNode(ListNode * head, int val) {
        if (!head) return new ListNode(val);
        ListNode * newNode = new ListNode(val);
        
        if (val < head->val) {
            newNode->next = head;
            return newNode;
        }
        
        ListNode * node = head;
        
        while(node && node->next) {
            if (val >= node->val && val < node->next->val) {
                newNode->next = node->next;
                node->next = newNode;
                break;
            }
            node = node->next;
        }        
        node->next = newNode;
        
        return head;
    }
};