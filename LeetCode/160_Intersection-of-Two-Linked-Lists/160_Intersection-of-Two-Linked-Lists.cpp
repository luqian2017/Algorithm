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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA = 0, lenB = 0;
        ListNode *pA = headA;
        ListNode *pB = headB;
        while(pA) {
            lenA++;
            pA = pA->next;
        }
        while(pB) {
            lenB++;
            pB = pB->next;
        }
        
        if (lenA < lenB) {
            pA = headB;
            pB = headA;
        } else {
            pA = headA;
            pB = headB;
        }
        
        int gap = abs(lenA - lenB);
        for (int i = 0; i < gap; i++) {
            pA = pA->next;
        }
        
        while(pA) {
            if (pA == pB) return pA;
            pA = pA->next;
            pB = pB->next;
        }
        
        return NULL;
    }
};