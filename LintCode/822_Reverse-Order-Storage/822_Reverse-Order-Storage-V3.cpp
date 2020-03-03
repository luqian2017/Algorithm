class Solution {
public:
    /**
     * @param head: the given linked list
     * @return: the array that store the values in reverse order 
     */
    vector<int> reverseStore(ListNode * head) {
        if (!head) return {};
        vector<int> result;
        result = reverseStore(head->next);
        result.push_back(head->val);
        return result;
    }
};