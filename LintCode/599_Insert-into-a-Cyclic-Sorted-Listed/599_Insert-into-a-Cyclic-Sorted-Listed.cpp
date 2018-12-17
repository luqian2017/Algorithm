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
     * @param node: a list node in the list
     * @param x: An integer
     * @return: the inserted new list node
     */
    ListNode * insert(ListNode * node, int x) {

        ListNode *newNode = new ListNode(x);
        if (!node) {
            newNode->next = newNode;
            return newNode;   
        }
        
        ListNode *original = node;
  
        //single node case      
        if (node->next == original) {
            node->next = newNode;
            newNode->next = node;
            return newNode;
        }
        
        while(1) {
            if (node->next == original) { //2->2->2 3
                newNode->next = original->next;
                original->next = newNode;
                break;
            }
            
            if ((x == node->val) ||
                ((x > node->val) && (x < node->next->val)) ||
                ((node->val > node->next->val) && (x > node->val)) ||
                ((node->val > node->next->val) && (x < node->next->val))
                ) { 
                
                newNode->next = node->next;
                node->next = newNode;
                break;
            }
            
            node = node->next;
        }
        
        return newNode;
    }
};