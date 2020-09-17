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
            if (colors[i] == 0 && !colored(i, graph, colors, 1)) {
                return false;
            }
        }
        return true;
    }
    
private:
    bool colored(int node, vector<vector<int>> &graph, vector<int> & colors, int color) {
        colors[node] = color;
        for (auto j : graph[node]) {
            if (colors[j] == color) return false;
            if (colors[j] == 0 && !colored(j, graph, colors, -color)) return false;
        }

        return true;
    }
};