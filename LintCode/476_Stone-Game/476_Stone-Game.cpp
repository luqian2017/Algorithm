class Solution {
public:
    /**
     * @param A: An integer array
     * @return: An integer
     */
    int stoneGame(vector<int> &A) {
        int n = A.size();
        if (n == 0) return 0;
        
        dp.resize(n, vector<int>(n, 0));
        visited.resize(n, vector<bool>(n, false));
        presums.resize(n, vector<int>(n, 0));
        
        for (int i = 0; i < n - 1; ++i) {
            presums[i][i] = A[i];
            for (int j = i + 1; j < n; ++j) {
                presums[i][j] = presums[i][j - 1] + A[j];
            }
        }
        
        return search(0, n - 1);
    }
    
private:
    int search(int start, int end) {
        if (visited[start][end]) return dp[start][end];
        if (start == end) {
            visited[start][end] = true;
            return dp[start][end];
        }
        dp[start][end] = INT_MAX;
        for (int i = start; i < end; ++i) {
            dp[start][end] = min(dp[start][end], search(start, i) + search(i + 1, end) + presums[start][end]);
        }
        visited[start][end] = true;
        return dp[start][end];
    }
    vector<vector<int>> presums;
    vector<vector<bool>> visited;
    vector<vector<int>> dp;
};