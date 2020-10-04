/**
  * Definition of Doubly-ListNode
 * class DoublyListNode {
 * public:
 *     int val;
 *     DoublyListNode *next, *prev;
 *     DoublyListNode(int val) {
 *         this->val = val;
 *         this->prev = this->next = NULL;
 *     }
 * }
 */

class Solution {
public:
    /**
     * @param head: the given doubly linked list
     * @param nodes: the given nodes array
     * @return: the number of blocks in the given array
     */
    int blockNumber(DoublyListNode * head, vector<int> &nodes) {
        int n = nodes.size();
        unordered_set<int> node_set;
        int count = 0;

        for (int i = 0; i < n; ++i) {
            node_set.insert(nodes[i]);
        }
        
        DoublyListNode * node = head;
        while(node) {
            if (node_set.find(node->val) != node_set.end()) {
                count++;
                while (node && node_set.find(node->val) != node_set.end()) {
                    node_set.insert(node->val);
                    node = node->next;
                }
            } else {
                node = node->next;
            }
        }

        return count;
    }
};