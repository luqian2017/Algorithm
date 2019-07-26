/**
 * Definition for Undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */


class Solution {
public:
    /*
     * @param nodes: a array of Undirected graph node
     * @return: a connected set of a Undirected graph
     */
    vector<vector<int>> connectedSet(vector<UndirectedGraphNode*> nodes) {
        if (nodes.size() == 0) return result;
        for (auto node : nodes) visited[node] = 0;
        for (auto node : nodes) {
            if (!visited[node]) {
                visited[node] = 1;
                bfs(node, nodes);
            }
        }
        return result;
    }

private:
    void bfs(UndirectedGraphNode * node, vector<UndirectedGraphNode *> nodes)
    {
        queue<UndirectedGraphNode *> q;
        q.push(node);
        vector<int> component;
        component.push_back(node->label);
        while(!q.empty()) {
            UndirectedGraphNode * topNode = q.front();
            q.pop();
            for (int i = 0; i < topNode->neighbors.size(); ++i) {
                if (visited[topNode->neighbors[i]]) continue;
                visited[topNode->neighbors[i]] = 1;
                q.push(topNode->neighbors[i]);
                component.push_back(topNode->neighbors[i]->label);
            }
        }
        sort(component.begin(), component.end());
        result.push_back(component);
    } 
    
    vector<vector<int>> result;
    map<UndirectedGraphNode *, int> visited;
};