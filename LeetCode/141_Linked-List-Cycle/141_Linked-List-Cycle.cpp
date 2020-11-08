/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (!head || !head->next) return false;
        ListNode *pSlow = head;
        ListNode *pFast = head->next;
        while(pFast && pFast->next) {
            if (pSlow == pFast) return true;
            pFast = pFast->next->next;
            pSlow = pSlow->next;
        }
        return false;
    }
};