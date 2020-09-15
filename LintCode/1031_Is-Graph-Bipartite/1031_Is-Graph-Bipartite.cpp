class Solution {
public:
    /**
     * @param graph: the given undirected graph
     * @return:  return true if and only if it is bipartite
     */
    bool isBipartite(vector<vector<int>> &graph) {
        int n = graph.size();
        if (n == 0) return false;
        
        unordered_set<int> set1;
        unordered_set<int> set2;
        
        for (int i = 0; i < n; ++i) {
            if (set2.find(i) != set2.end()) {
                for (int j = 0; j < graph[i].size(); ++j) {
                    if (set2.find(graph[i][j]) != set2.end()) return false;
                    set1.insert(graph[i][j]);
                }
            } else if (set1.find(i) != set1.end()) {
                for (int j = 0; j < graph[i].size(); ++j) {
                    if (set1.find(graph[i][j]) != set1.end()) return false;
                    set2.insert(graph[i][j]);
                }
            } else {
                set1.insert(i);
                for (int j = 0; j < graph[i].size(); ++j) {
                    if (set1.find(graph[i][j]) != set1.end()) return false;
                    set2.insert(graph[i][j]);
                }
            }
        }
        
        return true;        
    }
};
