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
     * @param headA: the first list
     * @param headB: the second list
     * @return: a ListNode
     */
    ListNode * getIntersectionNode(ListNode * headA, ListNode * headB) {

        if (!headA || !headB) return NULL;
        
        ListNode * nodeA = headA;
        ListNode * endA = NULL;
        
        while(nodeA && nodeA->next) {
            nodeA = nodeA->next;
        }
        endA = nodeA;
        endA->next = headA;  // construct a circle
        
        ListNode * node1 = headB;
        ListNode * node2 = node1->next;
        ListNode * meetNode = NULL;
        
        while(node1 && node2 && node1->next && node2->next) {
            if (node1 == node2) {
                meetNode = node1;
                break;
            }
            node1 = node1->next;
            node2 = node2->next->next;
        }

        if (!meetNode) {
            endA->next = NULL;
            return NULL;
        }
        
        node1 = meetNode->next;
        node2 = headB;
        while(node1 != node2) {
            node1 = node1->next;
            node2 = node2->next;
        }
        
        endA->next = NULL;
        return node1;
    }
};