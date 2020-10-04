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
      
    // with the path compression
    int find(int a){
        int x = a;
        while (father[x] != x){
            x = father[x];
        }
        
        int nx;
        int y = a;
        while (father[y] != y){
            nx = father[y];
            father[y] = x;
            y = nx;
        }
        return x;
    }
    
    void connect(int a, int b){
        int fa = find(a);
        int fb = find(b);

        if (fa != fb){
            father[fa] = fb;
            count--;
        }
    }
    
    int blockNumber(DoublyListNode * head, vector<int> &nodes) {
        int n = nodes.size();
        unordered_set<int> node_set;
        count = n;
        for (int i = 0; i < n; ++i) {
            father[nodes[i]] = nodes[i];
            node_set.insert(nodes[i]);
        }
        DoublyListNode *node = head;
        while(node != NULL && node->next != NULL){
            if (node_set.find(node->val) != node_set.end() && 
                node_set.find(node->next->val) != node_set.end()) {
                connect(node->next->val, node->val);
            }
            node = node->next;
        }
        //int res = 0;
        //for (auto f: father){
        //    if ((f.first == f.second) && (node_set.find(f.first) != node_set.end()))
        //        res++;
        //}
        //return res;
        return count;
        
    }
private:
    int count = 0;
    map<int, int> father;
};