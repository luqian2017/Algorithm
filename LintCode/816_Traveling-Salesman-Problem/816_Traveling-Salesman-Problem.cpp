class Solution {
public:
    /**
     * @param n: an integer,denote the number of cities
     * @param roads: a list of three-tuples,denote the road between cities
     * @return: return the minimum cost to travel all cities
     */
    int minCost(int n, vector<vector<int>> &roads) {
        int len = roads.size();
        int inf = 1000000000;
        graph.resize(n + 1, vector<int>(n + 1, inf));
        constructGraph(roads, n);
        
        int state_size = (1 << n); //0000 - 1111
        
        //dp[i][j] : the min cost when state is i, the last passed city is j
        vector<vector<int>> dp(state_size, vector<int>(n + 1, inf));

        dp[1][1] = 0; // start from city 1, state is 0000001, minCost is 0
        
        for (int state = 0; state < state_size; ++state) {
            for (int i = 2; i <= n; ++i) {
                if ((state & (1 << (i - 1))) == 0) continue;
                
                int prev_state = state ^ (1 << (i - 1));
                
                for (int j = 1; j <= n; ++j) {
                    if (i == j) continue;
                    dp[state][i] = min(dp[state][i], dp[prev_state][j] + graph[j][i]);
                }
            }
        }
        
        int min_cost = inf;
        for (int i = 1; i <= n; ++i) {
            min_cost = min(min_cost, dp[state_size - 1][i]);
        }
        
        return min_cost;
    }
    
private:
    vector<vector<int>> graph;
    void constructGraph(vector<vector<int>> & roads, int n) {
        int len = roads.size();
        for (int i = 0; i < len; ++i) {
            int source = roads[i][0];
            int destination = roads[i][1];
            int cost = roads[i][2];
        //    graph[source][destination] = cost;
        //    graph[destination][source] = cost;
            graph[source][destination] = min(graph[source][destination], cost);
            graph[destination][source] = min(graph[destination][source], cost);

        }
    }
};