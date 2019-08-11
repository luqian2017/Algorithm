class Solution {
public:
    /**
     * @param A: as indicated in the description
     * @param E: as indicated in the description
     * @return: Return the number of edges on the longest path with same value.
     */
    int LongestPathWithSameValue(vector<int> &A, vector<int> &E) {
        int Asize = A.size();
        if (Asize == 0) return 0;
        int Esize = E.size();
        if (Esize != (Asize - 1) * 2) return 0;
        
        maxLength = 0;
        visited.resize(Asize + 1, 0);
        
        for (int i = 0; i < Esize; i += 2) {
            mp[E[i]].insert(E[i + 1]);
            mp[E[i + 1]].insert(E[i]);
        }

        for (int i = 1; i <= Asize; ++i) {
            dfs(A, E, i, 0);
        }
        
        return maxLength;
    }

private:
    void dfs(vector<int> &A, vector<int> &E, int startNode, int  len) {
        if (visited[startNode]) return;
        visited[startNode] = 1;
        
        maxLength = max(maxLength, len);
        
        for (auto node : mp[startNode]) {
            if (A[node - 1] == A[startNode - 1]) {
                dfs(A, E, node, len + 1);
            }
        }
        visited[startNode] = 0;
    }
    
    map<int, set<int>> mp;
    int maxLength;
    vector<int> visited;
};