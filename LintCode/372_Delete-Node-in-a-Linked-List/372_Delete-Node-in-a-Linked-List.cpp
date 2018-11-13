/**
 * Definition of ListNode
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *         this->val = val;
 *         this->next = NULL;
 *     }
 * }
 */


class Solution {
public:
    /*
     * @param node: the node in the list should be deletedt
     * @return: nothing
     */
    void deleteNode(ListNode * node) {
        if (!node) return;
        ListNode * node1 = node;
        while(node) {
            if (node->next) {
                node->val = node->next->val;
                if (!node->next->next) node->next = NULL;
                node = node->next; 
            } 
        }
    }
};