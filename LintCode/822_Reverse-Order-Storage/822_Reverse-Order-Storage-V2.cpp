/**
 * Definition of singly-linked-list:
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *        this->val = val;
 *        this->next = NULL;
 *     }
 * }
 */

class Solution {
public:
    /**
     * @param head: the given linked list
     * @return: the array that store the values in reverse order 
     */
    vector<int> reverseStore(ListNode * head) {
        vector<int> result;
        helper(head, result);
        return result;
    }

private:
    void helper(ListNode * head, vector<int> & result) {
        if (!head) return;
        
        helper(head->next, result);

        result.push_back(head->val);
   }
};