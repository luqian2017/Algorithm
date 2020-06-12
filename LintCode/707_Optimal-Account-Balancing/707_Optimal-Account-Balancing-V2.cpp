class Solution {
public:
    /*
     * @param edges: a directed graph where each edge is represented by a tuple
     * @return: the number of edges
     */
    int balanceGraph(vector<vector<int>> &edges) {
        int nRow = edges.size();
        int nCol = edges[0].size();
        unordered_map<int, int> um; //<i, j> Node i has balance j
        for (auto e : edges) {
            um[e[0]] -= e[2];
            um[e[1]] += e[2];
        }
        
        vector<int> account;
        for (auto u : um) {
            if (u.second != 0) account.push_back(u.second);
        }
        if(account.size() == 0) return 0;

        vector<int> dp(1 << account.size(), INT_MAX / 2);  //???
        for (int i = 1; i < dp.size(); ++i) {
            int sum = 0, count = 0;
            for (int j = 0; j < account.size(); ++j) {
                if ((1 << j) & i) {
                    sum += account[j];
                    count++;
                } 
            }
            
            if (sum == 0) {
                dp[i] = count - 1;
                for (int j = 1; j < i ; ++j) {
                    if ((i & j) == j) {
                        dp[i] = min(dp[i], dp[j] + dp[i - j]);
                    }
                }
            }
        }
        return dp.back(); //dp[dp.size() - 1]; 
    }
};