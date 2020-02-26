class Solution {
public:
    /**
     * @param head: a ListNode
     * @return: a ListNode
     */
    ListNode * swapPairs(ListNode * head) {
        int count = 1;
        ListNode * origHead = head;
        while(head && head->next) {
            if (count & 0x1) {
                swap(head->val, head->next->val);
            }
            head = head->next;
            count++;
        }
        return origHead;
    }
};