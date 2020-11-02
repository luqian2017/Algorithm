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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (!head) return NULL;
        ListNode *dummyHead = new ListNode(-1);
        dummyHead->next = head;
        ListNode * pNode = head;
        int count = 1;
        while (count != n + 1) {
            pNode = pNode->next;
            count++;
        }
        // if it happens to remove head
        if (!pNode) {
            dummyHead->next = head->next;
          //  free(head);
            return dummyHead->next;
        }
        while(pNode->next) {
            pNode = pNode->next;
            head = head->next;
        }
        ListNode *tmpNode = head->next;
        head->next = tmpNode->next;
       // free(tmpNode);
        return dummyHead->next;
    }
};