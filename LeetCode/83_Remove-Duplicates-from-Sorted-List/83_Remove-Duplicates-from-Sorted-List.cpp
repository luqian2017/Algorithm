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
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) return NULL;
        ListNode * dummyHead = new ListNode(-1, head);
        unordered_set<int> u_set;
        ListNode *pNode = dummyHead;
        while(pNode->next) {
            if (u_set.find(pNode->next->val) != u_set.end()) {
              //  ListNode *tmpNode = pNode->next;
                pNode->next = pNode->next->next;
           //     free(tmpNode);
            } else {
                u_set.insert(pNode->next->val);
                pNode = pNode->next;
            }
            
        }
        return dummyHead->next;
    }
};