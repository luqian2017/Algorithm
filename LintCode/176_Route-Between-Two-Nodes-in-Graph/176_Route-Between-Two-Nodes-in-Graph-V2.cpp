/**
 * Definition for Directed graph.
 * struct DirectedGraphNode {
 *     int label;
 *     vector<DirectedGraphNode *> neighbors;
 *     DirectedGraphNode(int x) : label(x) {};
 * };
 * 
 */


class Solution {
public:
    /*
     * @param graph: A list of Directed graph node
     * @param s: the starting Directed graph node
     * @param t: the terminal Directed graph node
     * @return: a boolean value
     */
    bool hasRoute(vector<DirectedGraphNode*> graph, DirectedGraphNode* s, DirectedGraphNode* t) {
        
        if (s->neighbors.size() == 0) return false;
        if (s == t) return true;
        
        queue<DirectedGraphNode *> q;
        unordered_set<DirectedGraphNode *> visited;
        q.push(s);
        visited.insert(s);
        
        while(q.size() > 0) {
            DirectedGraphNode * currNode = q.front();
            q.pop();
            for (int i = 0; i < currNode->neighbors.size(); ++i) {
                if (visited.find(currNode->neighbors[i]) != visited.end()) {
                    continue;
                }
                if (currNode->neighbors[i] == t) {
                    return true;
                } else {
                    q.push(currNode->neighbors[i]);
                    visited.insert(currNode->neighbors[i]);
                }
            }
        }
        return false;
    }
};