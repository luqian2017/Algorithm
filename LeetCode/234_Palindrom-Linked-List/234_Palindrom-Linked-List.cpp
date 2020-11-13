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
    bool isPalindrome(ListNode* head) {
        if (!head) return true;
        int len = 0;
        ListNode *origHead = head;
        while(head) {
            len++;
            head = head->next;
        }
        
        //reverse the first half
        head = origHead;
        ListNode *pre = NULL;
        int count = len / 2;
        while(head && count) {
            ListNode *tmpNode = head->next;
            head->next = pre;
            pre = head;
            head = tmpNode;
            count--;
        }
        
        if (len & 0x1) {
            head = head->next;
        }
        while(head) {
            if (pre->val != head->val) return false;
            head = head->next;
            pre = pre->next;
        }
        return true;
    }
};