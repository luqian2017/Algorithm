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
        if (!head) return vector<int>();
        
        vector<int> result;
        while(head) {
            result.push_back(head->val);
            head = head->next;
        }
        
        reverse(result.begin(), result.end());
        return result;
    }
};