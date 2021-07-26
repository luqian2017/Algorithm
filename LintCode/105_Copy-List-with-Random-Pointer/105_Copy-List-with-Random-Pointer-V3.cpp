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
        RandomListNode *origHead = head;
        while(head) {
            RandomListNode *node = new RandomListNode(head->label);
            node->next = head->next;
            
            head->next = node;
            head = node->next;
        }
        head = origHead;
        
        while(head) {
            if (head->random) head->next->random = head->random->next;
            head = head->next->next;
        }

        RandomListNode *newHead = origHead->next;
        head = origHead;
        while(head) {
            RandomListNode *node = head->next;
            head->next = node->next;
            if (node->next) node->next = node->next->next;
            head = head->next;
        }
        return newHead;
    }
};