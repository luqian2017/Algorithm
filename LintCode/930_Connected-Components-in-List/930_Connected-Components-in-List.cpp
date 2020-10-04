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
        map<int, DoublyListNode*> list_mp;
        map<int, bool> node_mp; //<node_dex, visited>
        int count = 0;

        DoublyListNode * node = head;
        while(node) {
            list_mp[node->val] = node;
            node = node->next;
        }
        
        for (int i = 0; i < n; ++i) {
            node_mp[nodes[i]] = false;
        }
        
        for (int i = 0; i < n; ++i) {
            if (!node_mp[nodes[i]]) {
                count++;
                node = list_mp[nodes[i]];
                //while(node && !node_mp[node->val]) { //if the node is in nodes and unvisited
                while(node && (node_mp.find(node->val) != node_mp.end()) && !node_mp[node->val]) { //if the node is in nodes and unvisited
                    node_mp[node->val] = true;
                    node = node->next;
                }
                node = list_mp[nodes[i]]->prev;
                while(node && (node_mp.find(node->val) != node_mp.end()) && !node_mp[node->val]) { //if the node is in nodes and unvisited
                    node_mp[node->val] = true;
                    node = node->prev;
                }
            }
        }
        
        return count;
    }
};