class Solution {
public:
    /**
     * @param graph: the given undirected graph
     * @return:  return true if and only if it is bipartite
     */
    bool isBipartite(vector<vector<int>> &graph) {
        int n = graph.size();
        vector<int> colors(n, 0);
        for (int i = 0; i < n; ++i) {
            if (colors[i] == 0 && !bfs(i, graph, colors)) {
                return false;
            }
        }
        return true;
    }
    
private:
    bool bfs(int node, vector<vector<int>> &graph, vector<int> & colors) {
        queue<int> q;
        q.push(node);
        colors[node] = 1;
        
        while(!q.empty()) {
            int curNode = q.front();
            q.pop();
            for (auto n : graph[curNode]) {
                if (colors[n] == 0) {
                    colors[n] = -colors[curNode];
                    q.push(n);
                } else {
                    if (colors[n] == colors[curNode]) return false;
                }
            }
        }
 
        return true;
    }
};