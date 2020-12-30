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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *dummyNode = new ListNode(0);
        if (!l1) return l2;
        if (!l2) return l1;
        ListNode *p1 = l1, *p2 = l2, *p;
        if (p1->val < p2->val) {
            p = p1, p1 = p1->next;
        } else {
            p = p2, p2 = p2->next;
        }
        dummyNode->next = p;
        while (p1 && p2) {
            if (p1->val < p2->val) {
                p->next = p1;
                p1 = p1->next;
            } else {
                p->next = p2;
                p2 = p2->next;
            }
            p = p->next;
        }
        if (p1) {
            p->next = p1;
        } else {
            p->next = p2;
        }
        return dummyNode->next;
    }
};