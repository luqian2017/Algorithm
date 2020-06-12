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
        
        int res = INT_MAX;
        helper(account, 0, 0, res);
        
        return res;
    }

private:
    void helper(vector<int> & account, int start, int sol, int &res) {
        if (sol >= res) return;
        int n = account.size();
        while(start < n && account[start] == 0) start++;

        if (start == n) {
            res = min(res, sol);
            return;
        }
        
        for (int i = start + 1; i < n; ++i) {
            if (account[i] * account[start] < 0) {
                account[i] += account[start];
                helper(account, start + 1, sol + 1, res);
                account[i] -= account[start];
            }
        }
    }
};