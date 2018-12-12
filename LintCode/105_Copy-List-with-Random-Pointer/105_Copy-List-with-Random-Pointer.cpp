/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    /**
     * @param head: The head of linked list with a random pointer.
     * @return: A new head of a deep copy of the list.
     */
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (!head) return NULL;
        map<RandomListNode*, RandomListNode*> mp; //original node, copied node
        
        RandomListNode *head2 = new RandomListNode(head->label);
        RandomListNode *node = head;
        RandomListNode *node2 = head2;
        mp[node] = node2;
        
        while(node->next) {
            node2->next = new RandomListNode(node->next->label);
            node = node->next;
            node2 = node2->next;
            mp[node] = node2;    
        }
        
        node = head;
        node2 = head2;
        while(node) {
            node2->random = mp[node->random];
            node = node->next;
            node2 = node2->next;
        }
        
        return head2;
    }
};