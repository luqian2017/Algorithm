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
    ListNode* swapPairs(ListNode* head) {
        if (!head) return NULL;
        ListNode *dummyHead = new ListNode();
        dummyHead->next = head;
        
        ListNode *pNode = dummyHead;
        while(pNode->next && pNode->next->next) {
            ListNode *tmpNodeA = pNode->next;
            ListNode *tmpNodeB = tmpNodeA->next;
            pNode->next = tmpNodeB;
            tmpNodeA->next = tmpNodeB->next;
            tmpNodeB->next = tmpNodeA;
            pNode = tmpNodeA; 
        }
        
        return dummyHead->next;
    }
};