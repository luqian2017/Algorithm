/*
0 -> 4, 6
1 -> 6, 8
2 -> 7, 9
3 -> 4, 8
4 -> 3, 9
5 ->
6 -> 1, 7
7 -> 2, 6
8 -> 1, 3
9 -> 2, 4
*/


class Solution {
public:
    /**
     * @param N: N
     * @return: return the number of distinct numbers can you dial in this manner mod 1e9+7
     */
    int knightDialer(int N) {
        //#define M (long long)(10e9 + 7)
        int M = 1e9 + 7;
        unordered_map<int, vector<int>> dict = 
        { {0, {4, 6}},
          {1, {6, 8}},
          {2, {7, 9}},
          {3, {4, 8}},
          {4, {0, 3, 9}},
          {5, {}},
          {6, {0, 1, 7}},
          {7, {2, 6}},
          {8, {1, 3}},
          {9, {2, 4}}   
        };

        vector<vector<int>> dp(N + 1, vector<int>(10, 0));
        for (int i = 0; i <= 9; i++) {
            dp[1][i] = 1;
        }
        
        for (int i = 2; i <= N; i++) {
            for (int j = 0; j <= 9; j++) {
                for (int k = 0; k < dict[j].size(); k++) {
                    dp[i][j] = (dp[i][j] + dp[i - 1][dict[j][k]]) % M;
                }
            }
        }
        int sum = 0;
        for (int i = 0; i <= 9; ++i) {
            sum = (sum + dp[N][i]) % M;
        }
        return sum;
    }
};