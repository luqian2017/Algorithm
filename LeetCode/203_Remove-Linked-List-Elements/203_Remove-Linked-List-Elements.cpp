/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if (!head) return NULL;
        ListNode * dummyHead = new ListNode(-1);
        dummyHead->next = head;
        ListNode *pNode = dummyHead;
        while(pNode && pNode->next) { // note both pNode && pNode->next are needed
            if (pNode->next->val == val) {
               //ListNode *tmpNode = pNode->next;
               pNode->next = pNode->next->next;
               //free(tmpNode);
            } else {
                pNode = pNode->next;
            }
        }
        return dummyHead->next;
    }
};