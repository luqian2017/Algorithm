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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr) return nullptr;
        ListNode *p = head;
        int cnt = 1;
        while (p->next) {
            p = p->next;
            cnt++;
        }
        k %= cnt; 
        p->next = head;
        
        for (int i = 0; i < cnt - k; i++) p = p->next;
        head = p->next;
        p->next = nullptr;
        return head;        
    }
};