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
    ListNode* removeElements(ListNode* head, int val) {
        if (!head) return NULL;
        ListNode * dummyHead = new ListNode(-1);
        ListNode * pNode = dummyHead;
        dummyHead->next = head;
        while (pNode->next) {
            if (pNode->next->val == val) {
                ListNode * tempNode = pNode->next;
                pNode->next = pNode->next->next;
                free(tempNode);
                tempNode = NULL;
            } else {
                pNode = pNode->next;
            }
        }
        return dummyHead->next;
    }
};