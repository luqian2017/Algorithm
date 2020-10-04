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
        map<int, bool> nodes_mp; //<node_val, visited>
        int count = 0;

        DoublyListNode * node = head;
        for (int i = 0; i < n; ++i) {
            nodes_mp[nodes[i]] = false;
        }
        
        node = head;
        while(node) {
            if (nodes_mp.find(node->val) != nodes_mp.end() && !nodes_mp[node->val]) {
                count++;
                while (node && nodes_mp.find(node->val) != nodes_mp.end() && !nodes_mp[node->val]) {
                    nodes_mp[node->val] = true;
                    node = node->next;
                }
            } else {
                node = node->next;
            }
        }

        return count;
    }
};