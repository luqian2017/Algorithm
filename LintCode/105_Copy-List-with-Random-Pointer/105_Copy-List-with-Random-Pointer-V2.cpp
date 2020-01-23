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
        unordered_map<RandomListNode *, RandomListNode *> mp;
        RandomListNode * dummyHead = new RandomListNode(0);
        RandomListNode * origNode = head, * copyNode = dummyHead;
        RandomListNode * tmpNode;
        
        while(origNode) {
            tmpNode = new RandomListNode(origNode->label);
            mp[origNode] = tmpNode;
            copyNode->next = tmpNode;
            copyNode = tmpNode;
            origNode = origNode->next;
        }

        origNode = head;
        copyNode = dummyHead->next;
        while(origNode) {
            if (origNode->random) copyNode->random = mp[origNode->random];
            origNode = origNode->next;
            copyNode = copyNode->next;
        }
        
        return dummyHead->next;
    }
};