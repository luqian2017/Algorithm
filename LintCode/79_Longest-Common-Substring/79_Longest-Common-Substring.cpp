class Solution {
public:
    /**
     * @param A: A string
     * @param B: A string
     * @return: the length of the longest common substring.
     */
    int longestCommonSubstring(string &A, string &B) {
        int M = A.size();
        int N = B.size();
        if (M == 0 || N == 0) return 0;
        
        vector<vector<int>> DP(M + 1, vector<int>(N + 1, 0));
        int result = 0;

        for (int i = 1; i <= M; ++i) {
            for (int j = 1; j <= N; ++j) {
                if (A[i - 1] == B[j - 1]) {
                    DP[i][j] = DP[i - 1][j - 1] + 1;
                } //else {
                //    DP[i][j] = 0;
                //} 
                result = max(result, DP[i][j]);
            }
        }
        
        return result;
    }
};