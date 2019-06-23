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
     * @param n: the start index
     * @param m: the end node
     * @return: A ListNode
     */
    ListNode * deleteNode(ListNode * head, int n, int m) {
        if (!head || n > m) return NULL;
    
        ListNode * dummyHead = new ListNode(0);
        dummyHead->next = head;
        ListNode * prevNode = dummyHead;
        int index = 0;
        while(head) {
            if (index == n - 1) {
                prevNode = head;
            } else if (index == m + 1) {
                prevNode->next = head;
                break;
            }
            head = head->next;
            index++;
        }
        
        return dummyHead->next;
    }
};