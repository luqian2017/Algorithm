/**
 * Definition for Directed graph.
 * struct DirectedGraphNode {
 *     int label;
 *     vector<DirectedGraphNode *> neighbors;
 *     DirectedGraphNode(int x) : label(x) {};
 * };
 */

class Solution {
public:
    /*
     * @param graph: A list of Directed graph node
     * @return: Any topological order for the given graph.
     */
    vector<DirectedGraphNode*> topSort(vector<DirectedGraphNode*>& graph) {
        vector<DirectedGraphNode*> result;
        map<DirectedGraphNode*, int> hashmap;
        queue<DirectedGraphNode*> q;
        for (int i = 0; i < graph.size(); ++i) {
            for (int j = 0; j < graph[i]->neighbors.size(); ++j) {
                if (hashmap.find(graph[i]->neighbors[j]) == hashmap.end()) {
                    hashmap[graph[i]->neighbors[j]] = 1;
                } else {
                    hashmap[graph[i]->neighbors[j]]++;
                }
            }
        }
    
        for (int i = 0; i < graph.size(); ++i) {
            if (hashmap[graph[i]] == 0) {
                q.push(graph[i]);
                result.push_back(graph[i]);
            }
        }
        
        while(!q.empty()) {
            DirectedGraphNode * node = q.front();
            q.pop();
            for (auto nb : node->neighbors) {
                hashmap[nb]--;
                if (hashmap[nb] == 0) {
                    result.push_back(nb);                    
                    q.push(nb);
                }
            }
        }
        
        return result;
    }
};