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
        if (graph.size() == 0) return false;
        if (s == t) return true;
        
        int N = graph.size();
        
        for (int i = 0; i < graph.size(); ++i) {
            visited[graph[i]] = 0; 
        }
        
        return dfs(s, t);
    }

private:
    bool dfs(DirectedGraphNode * source, DirectedGraphNode * target) {
        if (source == target) return true;
        
        if (visited[source] == 1) return false;
        visited[source] = 1;
        for (int i = 0; i < source->neighbors.size(); ++i) {
            if (dfs(source->neighbors[i], target)) return true;
        }
        
        return false;
    }

    map<DirectedGraphNode *, int> visited;    
};